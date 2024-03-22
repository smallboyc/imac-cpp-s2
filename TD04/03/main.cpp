#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <iterator>

bool is_palindrome(std::string const &s)
{
    return std::equal(s.begin(), s.end(), s.rbegin());
}

int main()
{
    std::string word{"LAVAL"};
    std::cout << word << (is_palindrome(word) ? " est " : " n'est pas ") << "un palindrome.";
    return 0;
}