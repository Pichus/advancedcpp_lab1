#pragma once

#include <vector>

namespace statistics {
std::vector<long long> mostFrequentElements(const std::vector<long long>& v);
double calculateRate(const long long frequency, const long long total_size);
double entryRate(const long long entry, const std::vector<long long>& v);
std::vector<std::pair<long long, double>> allEntryRates(
    const std::vector<long long>& v);
double average(
    const std::vector<long long>& v);
double median(const std::vector<long long>& v);
}