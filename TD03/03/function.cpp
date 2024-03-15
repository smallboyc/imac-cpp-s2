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

std::string reverse_operator(Operator const &op)
{
    if (op == Operator::ADD)
        return "+";
    else if (op == Operator::SUB)
        return "-";
    else if (op == Operator::MUL)
        return "*";
    else if (op == Operator::DIV)
        return "/";
    else if (op == Operator::POW)
        return "^";
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
    std::vector<Token> EXIT{};
    std::stack<Token> Operators{};
    for (int i{0}; i < words.size(); i++)
    {
        if (is_floating(words[i]))
            EXIT.push_back(make_token(std::stof(words[i])));
        else if (check_operator(words[i]) == Operator::CLOSE_PAREN)
        {
            while (Operators.top().op != Operator::OPEN_PAREN)
            {
                EXIT.push_back(Operators.top());
                Operators.pop();
            }
            Operators.pop(); // Supprime la ( qui était le point d'arrêt
        }
        else
            Operators.push(make_token(check_operator(words[i])));

        if (operator_precedence(Operators.top().op) >= operator_precedence(check_operator(words[i])))
        {
            EXIT.push_back(Operators.top());
            Operators.pop();
        }
    }
    return EXIT;
}

size_t operator_precedence(Operator const op)
{
    if (op == Operator::POW)
        return 3;
    else if (op == Operator::MUL || op == Operator::DIV)
        return 2;
    else
        return 1;
}

std::vector<Token> infix_to_npi_tokens(std::string const &expression)
{

    std::vector<std::string> tokens{split_string(expression)};
    return tokenize(tokens);
}

void display_NPI_Result(std::vector<Token> const &exit)
{
    for (int i{0}; i < exit.size(); i++)
    {
        if (exit[i].value != 0)
            std::cout << exit[i].value << " ";
        else
            std::cout << reverse_operator(exit[i].op) << " ";
    }
}