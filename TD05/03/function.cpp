#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <numeric>
#include <unordered_map>
#include "function.hpp"

bool operator==(Card const &c1, Card const &c2)
{
    // return c1.kind == c2.kind && c1.value == c2.value;
    return c1.hash() == c2.hash();
}

int Card::hash() const
{
    return static_cast<int>(this->value) * 4 + static_cast<int>(this->kind);
}

std::vector<Card> get_cards(size_t const size)
{
    std::vector<Card> cards;
    cards.reserve(size);
    for (size_t i{0}; i < size; ++i)
    {
        cards.push_back({static_cast<CardKind>(rand() % 4), static_cast<CardValue>(rand() % 13)});
    }
    return cards;
}

bool is_card_in_list(std::unordered_map<std::string, int> const &result, std::string const &curent_card_name)
{
    auto it = result.find(curent_card_name);
    if (it == result.end())
        return false;
    return true;
}

std::unordered_map<std::string, int> get_instances_of_cards(std::vector<Card> const &cards_list)
{
    std::unordered_map<std::string, int> result;
    for (int i{0}; i < cards_list.size(); i++)
    {
        Card current_card_to_check{cards_list[i]};
        if (!is_card_in_list(result, card_name(current_card_to_check)))
        {
            int total{0};
            for (auto const card : cards_list)
                if (current_card_to_check == card)
                    total++;
            result.insert({card_name(current_card_to_check), total});
        }
    }
    return result;
}

void display_cards_instances(std::unordered_map<std::string, int> const &instances_of_cards_list)
{
    for (auto const card : instances_of_cards_list)
    {
        std::cout << card.first << " (" << card.second << " cards)" << std::endl;
    }
}

std::string card_name(Card const &card)
{
    std::string name{};

    unsigned int card_value{(static_cast<unsigned int>(card.value) + 2) % 14};

    if (card_value < 10)
    {
        name += '0' + card_value;
    }
    else if (card_value == 10)
    {
        name += "10";
    }
    else if (card_value == 11)
    {
        name += 'V';
    }
    else if (card_value == 12)
    {
        name += 'Q';
    }
    else if (card_value == 13)
    {
        name += 'K';
    }

    name += " of ";

    if (card.kind == CardKind::Heart)
    {
        name += "Heart";
    }
    else if (card.kind == CardKind::Diamond)
    {
        name += "Diamond";
    }
    else if (card.kind == CardKind::Club)
    {
        name += "Club";
    }
    else if (card.kind == CardKind::Spade)
    {
        name += "Spade";
    }
    return name;
}