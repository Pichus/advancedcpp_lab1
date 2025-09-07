#ifndef CARD_H
#define CARD_H

#include <compare>

struct Card {
 private:
  int suit_;
  int number_;

 public:
  explicit Card(const int suit, const int number)
      : suit_(suit), number_(number) {}
  auto operator<=>(const Card&) const = default;
};

#endif  // CARD_H
