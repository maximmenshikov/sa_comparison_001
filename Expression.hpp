#pragma once

class Expression
{
public:
    virtual int eval() = 0;
    virtual void dump(char *s) = 0;
};
