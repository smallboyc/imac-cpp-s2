#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <math.h>
#include <stack>

enum class Operator
{
    ADD,
    SUB,
    MUL,
    DIV,
    POW,
    OPEN_PAREN,
    CLOSE_PAREN
};

enum class TokenType
{
    OPERATOR,
    OPERAND
};

struct Token
{
    TokenType type;
    float value;
    Operator op;
};

std::vector<std::string> split_string(std::string const &s);
bool is_floating(std::string const &s);
Operator check_operator(std::string const &s);

Token make_token(float value);
Token make_token(Operator op);
std::vector<Token> tokenize(std::vector<std::string> const &words);

size_t operator_precedence(Operator const op);
std::vector<Token> infix_to_npi_tokens(std::string const &expression);

void display_NPI_Result(std::vector<Token> const &exit);