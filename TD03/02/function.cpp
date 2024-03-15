#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <math.h>
#include <stack>
#include "function.hpp"

std::vector<std::string> split_string(std::string const &s)
{
    std::istringstream in(s);
    return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>());
}

bool is_floating(std::string const &s)
{
    for (int i{0}; i < s.size(); i++)
        if (!(std::isdigit(s[i]) || s[i] == '.'))
            return false;
    return true;
}

Operator check_operator(std::string const &s)
{
    if (s == "+")
        return Operator::ADD;
    else if (s == "-")
        return Operator::SUB;
    else if (s == "*")
        return Operator::MUL;
    else if (s == "/")
        return Operator::DIV;
    else if (s == "^")
        return Operator::POW;
    else if (s == "(")
        return Operator::OPEN_PAREN;
    else
        return Operator::CLOSE_PAREN;
}

Token make_token(float value)
{
    return {TokenType::OPERAND, value};
}
Token make_token(Operator op)
{
    return {TokenType::OPERATOR, 0, op};
}

std::vector<Token> tokenize(std::vector<std::string> const &words)
{
    std::vector<Token> Tokens{};
    for (int i{0}; i < words.size(); i++)
    {
        if (is_floating(words[i]))
            Tokens.push_back(make_token(std::stof(words[i])));
        else
            Tokens.push_back(make_token(check_operator(words[i])));
    }
    return Tokens;
}

float npi_evaluate(std::vector<Token> const &tokens)
{
    std::stack<float> stack;
    int i{0};
    while (i < tokens.size())
    {
        if (tokens[i].type == TokenType::OPERAND)
            stack.push(tokens[i].value);
        else
        {
            float last = stack.top();
            stack.pop();
            float last_minus_one = stack.top();
            stack.pop();
            if (tokens[i].op == Operator::ADD)
                stack.push(last + last_minus_one);
            else if (tokens[i].op == Operator::SUB)
                stack.push(last - last_minus_one);
            else if (tokens[i].op == Operator::MUL)
                stack.push(last * last_minus_one);
            else if (tokens[i].op == Operator::DIV)
                stack.push(last_minus_one / last);
            else if (tokens[i].op == Operator::POW)
                stack.push(pow(last_minus_one, last));
        }
        i++;
    }
    return stack.top();
}