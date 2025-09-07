#ifndef CARD_H
#define CARD_H

#include <compare>

struct Card {
  int suit;
  int number;

  auto operator<=>(const Card&) const = default;
};

#endif  // CARD_H
