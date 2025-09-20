#pragma once

#include <map>
#include <vector>

namespace statistics {
    std::vector<long long> mostFrequentElements(
        const std::vector<long long>& v);
    double calculateRate(const long long frequency, const long long total_size);
    double entryRate(const long long entry, const std::vector<long long>& v);
    std::map<long long, double> allEntryRates(const std::vector<long long>& v);
    double average(const std::vector<long long>& v);
    // Requires sorted vector to work properly
    double median(const std::vector<long long>& v);
}  // namespace statistics