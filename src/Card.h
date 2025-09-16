#ifndef CARD_H
#define CARD_H

#include <compare>

struct Card {
    long long suit;
    long long number;

    auto operator<=>(const Card& rhs) const { return number <=> rhs.number; }
};

#endif  // CARD_H
