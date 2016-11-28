#include "LiteralExpression.hpp"
#include <stdio.h>
#include <string.h>

void LiteralExpression::setValue(int value)
{
    // loss of data. But it is false alarm as value is in [0, 9] range.
    val = value;
}

int LiteralExpression::eval()
{
    return val;
}

void LiteralExpression::dump(char *s)
{
    char str[50];
    sprintf(str, "%d", val);

    // stack corruption possible
    strcat(s, str);
}
