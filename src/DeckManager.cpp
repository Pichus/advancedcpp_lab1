#include "DeckManager.h"

#include <algorithm>
#include <random>

DeckManager::DeckManager(const int cards_of_same_suit_count)
    : current_card_index_(0),
      cards_of_same_suit_count_(cards_of_same_suit_count) {
  deck_size_ = kSuitCount * cards_of_same_suit_count_;
  deck_.resize(deck_size_);
  GenerateDeck();
  ShuffleDeck();
}

void DeckManager::GenerateDeck() {
  for (int i = 0; i < deck_size_; i++) {
    const int card_suit = i / cards_of_same_suit_count_;
    const int card_number = i % cards_of_same_suit_count_;
    const Card card(card_suit, card_number);
    deck_[i] = card;
  }
}

void DeckManager::ShuffleDeck() {
  current_card_index_ = 0;

  std::random_device random_device;
  std::mt19937 mersenne_twister_engine(random_device());

  std::ranges::shuffle(deck_, mersenne_twister_engine);
}

Card DeckManager::operator()() {
  if (current_card_index_ == deck_size_) {
    ShuffleDeck();
  }

  const auto current_card = deck_[current_card_index_];
  current_card_index_++;
  return current_card;
}