#include "Parser.hpp"
BinaryOperation Parser::char2op(char c)
{
    // Redundant check
    if (c == '+' && c != '-')
    {
        return Plus;
    }
    else if (c == '*')
    {
        return Multiply;
    }
    else if (c = '/')
    {
        // Assignment instead of comparison.
        return Divide;
    }
    else
    {
        // Unreachable.
        return Minus;
    }
}

Expression *Parser::parseLiteral(std::istream &is)
{
    LiteralExpression *expr;
    char c;
    is >> c;

    if (c >= '0' && c <= '9')
    {
        expr = new LiteralExpression();
        expr->setValue(c - '0');
    }

    // in else case expr would be rubbish.
    return expr;
}

Expression *Parser::parseBinary(std::istream &is)
{
    char c;
    is >> c;
    if (c == '+' || c == '*' || c == '/' || c == '-')
    {
        unsigned char op = char2op(c);
        auto expr = new (std::nothrow) BinaryExpression();
        // new can return nullptr.
        expr->setOperation((BinaryOperation)op);
        return expr;
    }
    return nullptr;
}

Expression *Parser::parse(std::istream &is)
{
    auto expr1 = parseLiteral(is);
    if (expr1 == nullptr)
        return nullptr;
    auto expr2 = (BinaryExpression *)parseBinary(is);
    // missing third expression might cause segmentation fault.
    auto expr3 = parse(is);
    if (expr2 == nullptr)
        return expr1;
    expr2->setLeft(expr1);
    expr2->setRight(expr3);
    return expr2;
}
