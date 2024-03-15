#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iterator>
#include <cctype>
#include <math.h>
#include <stack>

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

// tokens contient les float et opérateurs.
float npi_evaluate(std::vector<std::string> const &tokens)
{
    std::stack<float> stack;
    int i{0};
    while (i < tokens.size())
    {
        if (is_floating(tokens[i]))
            stack.push(std::stof(tokens[i]));
        else
        {
            float last = stack.top();
            stack.pop();
            float last_minus_one = stack.top();
            stack.pop();
            if (tokens[i] == "+")
                stack.push(last + last_minus_one);
            else if (tokens[i] == "-")
                stack.push(last - last_minus_one);
            else if (tokens[i] == "*")
                stack.push(last * last_minus_one);
            else if (tokens[i] == "/")
                stack.push(last_minus_one / last);
            else if (tokens[i] == "^")
                stack.push(pow(last_minus_one, last));
        }
        i++;
    }
    return stack.top();
}

int main()
{
    std::string str{};
    std::cout << "Entrez une chaine : ";
    std::getline(std::cin, str);
    std::cout << str;
    std::cout << std::endl;
    std::vector<std::string> tokens{split_string(str)};
    std::cout << npi_evaluate(tokens);

    return 0;
}