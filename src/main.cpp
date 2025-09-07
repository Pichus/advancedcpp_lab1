// Compiler: ... (needs to be specified)

#include <exception>
#include <format>
#include <iostream>
#include <set>
#include <vector>

#include "DeckManager.h"
#include "safeInputs.h"
#include "statistics.h"

void addNewStackLengthAndClear(
    std::vector<long long>& finished_card_stack_lengths,
    std::vector<Card>& current_card_stack) {
    long long new_length = current_card_stack.size();
    finished_card_stack_lengths.push_back(new_length);
    current_card_stack.clear();
}

void processNewCard(const Card& new_card,
                    std::vector<long long>& finished_card_stack_lengths,
                    std::vector<Card>& current_card_stack,
                    bool is_last_card = false) {
    if (current_card_stack.size() != 0) {
        auto comp = new_card <=> current_card_stack.back();
        if (comp <= 0) {
            addNewStackLengthAndClear(finished_card_stack_lengths,
                                      current_card_stack);
        }
    }
    current_card_stack.push_back(new_card);

    if (is_last_card) {
        addNewStackLengthAndClear(finished_card_stack_lengths,
                                  current_card_stack);
    }
}

std::vector<long long> startSimulation() {
    long long cards_amount_in_deck = safeInputs::safeBoundedNumberInput(
        "Enter cards amount in deck in range [1, 9223372036854775807]: ", 1,
        LLONG_MAX);
    long long cards_amount_in_simulation = safeInputs::safeBoundedNumberInput(
        "Enter cards amount in simulation in range [1, 9223372036854775807]: ",
        1, LLONG_MAX);

    std::vector<long long> finished_card_stack_lengths;
    std::vector<Card> current_card_stack;

    DeckManager deck_manager(cards_amount_in_deck);

    for (long long i = 0; i < cards_amount_in_simulation; i++) {
        Card next_card = deck_manager();
        processNewCard(next_card, finished_card_stack_lengths,
                       current_card_stack, i == cards_amount_in_simulation - 1);
    }

    return finished_card_stack_lengths;
}

void outputStatistics(const std::vector<long long>& v) {
    auto all_entry_rates = statistics::allEntryRates(v);
    std::cout << "Rates of all present lengths:" << std::endl;
    for (auto& [length, rate] : all_entry_rates) {
        std::cout << length << " : " << std::format("{:.2f}%", rate * 100)
                  << std::endl;
    }

    auto most_common_lengths = statistics::mostFrequentElements(v);
    std::cout << "Most common lengths: ";
    for (auto& e : most_common_lengths) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    double average_length = statistics::average(v);
    std::cout << std::format("Average length: {:.4f}", average_length)
              << std::endl;

    double median_length = statistics::median(v);
    std::cout << std::format("Median length: {:.1g}", median_length)
              << std::endl;
}

int main() {
    try {
        std::vector<long long> simulation_result = startSimulation();
        outputStatistics(simulation_result);
    } catch (std::logic_error& err) {
        std::cout << "Aborting program..." << std::endl;
        std::cout << "Logic error: " << err.what() << std::endl;
    } catch (std::exception& err) {
        std::cout << "Aborting program..." << std::endl;
        std::cout << "Error: " << err.what() << std::endl;
    }
}
