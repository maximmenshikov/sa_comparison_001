#pragma once
#include "Expression.hpp"

class LiteralExpression : public Expression
{
private:
    char val;
public:

    void setValue(int value);

    virtual int eval();
    virtual void dump(char *);
};
