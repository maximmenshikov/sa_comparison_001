#include <vector>
#include <iostream>
#include "Parser.hpp"

int result;

void *thread(void *arg)
{
    Expression *expr = (Expression *)arg;

    // race condition
    result = expr->eval();
    return NULL;
}

int main()
{
    char str[20] = { '\0' };
    Parser parser;
    Expression *expr = parser.parse(std::cin);

    pthread_t thread1, thread2;
    pthread_create(&thread1, NULL, thread, expr);
    pthread_create(&thread2, NULL, thread, expr);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    // stack corruption on long expressions
    expr->dump(str);

    std::cout << str << " = ";
    std::cout << expr->eval();
    // no return, memory leak
}