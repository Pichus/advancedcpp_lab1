#ifndef CARD_H
#define CARD_H

#include <compare>

class Card {
 public:
  auto operator<=>(const Card&) const = default;
};

#endif  // CARD_H
