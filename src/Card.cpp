#include "Card.h"

#include <stdexcept>

Card::Card() : suit_(0), number_(0) {}

Card::Card(const int suit, const int number) : suit_(0), number_(number) {
  if (suit < kMinSuit || suit > kMaxSuit) {
    throw std::out_of_range("suit out of range");
  }

  suit_ = suit;
}
int Card::suit() const { return suit_; }

int Card::number() const { return number_; }