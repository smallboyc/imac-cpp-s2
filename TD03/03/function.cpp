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
    std::vector<Token> EXIT;     // tableau final
    std::stack<Token> Operators; // stack qui stock les opérateurs

    for (int i{0}; i < words.size(); i++)
    {
        if (is_floating(words[i]))
            EXIT.push_back(make_token(std::stof(words[i])));
        else
        {
            Operator current_op{check_operator(words[i])};

            if (current_op == Operator::OPEN_PAREN)
            {
                Operators.push(make_token(current_op));
            }
            else if (current_op == Operator::CLOSE_PAREN)
            {
                while (!Operators.empty() && Operators.top().op != Operator::OPEN_PAREN)
                {
                    EXIT.push_back(Operators.top());
                    Operators.pop();
                }
                Operators.pop(); // Supprime la (
            }
            else
            {
                while (!Operators.empty() && operator_precedence(Operators.top().op) >= operator_precedence(current_op))
                {
                    EXIT.push_back(Operators.top());
                    Operators.pop();
                }
                Operators.push(make_token(current_op));
            }
        }
    }

    while (!Operators.empty())
    {
        EXIT.push_back(Operators.top());
        Operators.pop();
    }

    return EXIT;
}

size_t operator_precedence(Operator const op)
{
    if (op == Operator::POW)
        return 3;
    else if (op == Operator::MUL || op == Operator::DIV)
        return 2;
    else if (op == Operator::ADD || op == Operator::SUB)
        return 1;
    return 0;
}

std::vector<Token> infix_to_npi_tokens(std::string const &expression)
{
    // tokens = éléments divisés de la string de base dans un tableau
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