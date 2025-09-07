#pragma once

#include <vector>

namespace statistics {
std::vector<long long> mostFrequentElements(const std::vector<long long>& v);
double entryRate(const long long entry, const std::vector<long long>& v);
double average(const std::vector<long long>& v);
double median(const std::vector<long long>& v);
}