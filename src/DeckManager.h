#ifndef DECKMANAGER_H
#define DECKMANAGER_H
#include <random>
#include <vector>

#include "Card.h"

class DeckManager {
 private:
  static constexpr int kSuitCount = 4;

  std::mt19937 mersenne_twister_engine_;
  std::size_t current_card_index_;
  int cards_of_same_suit_count_;
  std::size_t deck_size_;
  std::vector<Card> deck_;

  void GenerateDeck();
  void ShuffleDeck();

 public:
  explicit DeckManager(int cards_of_same_suit_count);
  Card operator()();
};

#endif  // DECKMANAGER_H
