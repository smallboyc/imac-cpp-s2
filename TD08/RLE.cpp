#include <iostream>
#include <string>
#include <vector>
#include "RLE.hpp"

std::string RLE(std::string const str)
{
    int multiplicator{1};
    char current_char = str[0];
    std::string final_str;
    for (size_t i{1}; i < str.size(); i++)
    {
        if (str[i] == current_char)
            multiplicator++;
        else
        {
            final_str += std::to_string(multiplicator) + current_char;
            current_char = str[i];
            multiplicator = 1;
        }
    }
    final_str += std::to_string(multiplicator) + current_char;
    return final_str;
}

std::string RLE_reverse(std::string const str)
{
    char current_char = str[0];
    std::string final_str;
    std::vector<int> single_multiplicator;
    std::string multiplicator;
    for (size_t i{0}; i < str.size(); i++)
    {
        if (std::isdigit(str[i]))
            single_multiplicator.push_back(static_cast<int>(str[i] - '0'));
        else
        {
            for (int m : single_multiplicator)
                multiplicator += std::to_string(m);
            for (int j{0}; j < std::stoi(multiplicator); j++)
                final_str += str[i];
            single_multiplicator.clear();
            multiplicator.clear();
        }
    }
    return final_str;
}

std::string RLE_control(std::string const str)
{
    int multiplicator{1};
    char current_char = str[0];
    char control_char{'*'};
    std::string final_str;
    for (size_t i{1}; i < str.size(); i++)
    {
        if (str[i] == current_char)
            multiplicator++;
        else
        {
            if (multiplicator != 1)
            {
                final_str += control_char;
                final_str += std::to_string(multiplicator) + current_char;
            }
            else
                final_str += current_char;

            current_char = str[i];
            multiplicator = 1;
        }
    }

    if (multiplicator != 1)
    {
        final_str += control_char;
        final_str += std::to_string(multiplicator) + current_char;
    }
    else
        final_str += current_char;

    if (str.size() < final_str.size())
    {
        std::cout << "Compression inutile pour : ";
        return str;
    }

    return final_str;
}

std::string RLE_control_reverse(std::string const str)
{
    char current_char = str[0];
    char control_char{'*'};
    std::string final_str;
    std::vector<char> multiplicators_info;
    std::string multiplicator;
    for (size_t i{0}; i < str.size(); i++)
    {
        if (str[i] == control_char || std::isdigit(str[i]))
            multiplicators_info.push_back(str[i]);
        else
        {
            if (!multiplicators_info.empty())
            {
                for (int m : multiplicators_info)
                {
                    if (m != control_char)
                        multiplicator += m;
                }
                for (int j{0}; j < std::stoi(multiplicator); j++)
                    final_str += str[i];
                multiplicators_info.clear();
                multiplicator.clear();
            }
            else
                final_str += str[i];
        }
    }
    return final_str;
}