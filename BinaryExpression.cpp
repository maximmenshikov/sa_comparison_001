#include "BinaryExpression.hpp"
#include <string.h>

void BinaryExpression::setLeft(Expression *expr)
{
    left = expr;
}

void BinaryExpression::setRight(Expression *expr)
{
    right = expr;
}

void BinaryExpression::setOperation(BinaryOperation operation)
{
    op = operation;
}

int BinaryExpression::eval()
{
    int res;
    switch (op)
    {
        case Plus:
            res = left->eval() + right->eval();
            break;
        case Multiply:
            // missing break
            res = left->eval() * right->eval();
        case Minus:
            res = left->eval() - right->eval();
            break;
        // Missing Divide
    }
    // res can be anything if case is Divide
    return res;
}

void BinaryExpression::dump(char *s)
{
    left->dump(s);

    // stack corruption possible
    switch (op)
    {
        case Plus:
            strcat(s, "+");
            break;
        case Multiply:
            strcat(s, "*");
            break;
        case Minus:
            strcat(s, "-");
            break;
        case Divide:
            strcat(s, "/");
            break;
    }

    right->dump(s);
}
