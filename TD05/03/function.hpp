#pragma once

enum class CardKind
{
    Heart,
    Diamond,
    Club,
    Spade,
};

enum class CardValue
{
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Eight,
    Nine,
    Ten,
    Jack,
    Queen,
    King,
    Ace,
};

struct Card
{
    CardKind kind;
    CardValue value;
    int hash() const;
};

namespace std
{
    template <>
    struct hash<Card>
    {
        size_t operator()(Card const &card) const
        {
            return card.hash();
        }
    };
}

bool operator==(Card const &c1, Card const &c2);
std::vector<Card> get_cards(size_t const size);
std::string card_name(Card const &card);
std::unordered_map<std::string, int> get_instances_of_cards(std::vector<Card> const &cards_list);
void display_cards_instances(std::unordered_map<std::string, int> const &instances_of_cards_list);