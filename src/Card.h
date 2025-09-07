#ifndef CARD_H
#define CARD_H

#include <compare>

class Card {
 private:
  static constexpr int kMinSuit = 0;
  static constexpr int kMaxSuit = 3;
  int suit_;
  int number_;

 public:
  Card();
  Card(int suit, int number);
  auto operator<=>(const Card&) const = default;

  int suit() const;
  int number() const;
};

#endif  // CARD_H
