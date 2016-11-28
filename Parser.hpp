#include <iostream>
#include "Expression.hpp"
#include "BinaryExpression.hpp"
#include "LiteralExpression.hpp"

class Parser
{
public:

    BinaryOperation char2op(char c);
    Expression *parseLiteral(std::istream &is);
    Expression *parseBinary(std::istream &is);
    Expression *parse(std::istream &is);
};
