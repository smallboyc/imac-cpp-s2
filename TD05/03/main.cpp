#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <numeric>
#include <unordered_map>
#include "function.hpp"

int main()
{
    std::vector<Card> cards_list{get_cards(100)};
    display_cards_instances(get_instances_of_cards(cards_list));
    return 0;
}