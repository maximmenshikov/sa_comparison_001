#pragma once

#include "Expression.hpp"

typedef enum
{
    Minus = -2,
    Divide = -1,
    Plus = 1,
    Multiply = 2,
} BinaryOperation;

class BinaryExpression : public Expression
{
private:
    Expression *left;
    Expression *right;
    BinaryOperation op;

public:
    void setLeft(Expression *expr);
    void setRight(Expression *expr);
    void setOperation(BinaryOperation operation);

    virtual int eval();
    virtual void dump(char *);
};
