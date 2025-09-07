#include <vector>
#include <stdexcept>
#include <map>
#include <set>

namespace statistics {
std::vector<long long> mostFrequentElements(const std::vector<long long>& v) {
  if (v.size() == 0) {
    throw std::logic_error(
        "There is no most frequent element in a vector with 0 elements");
  }

  std::vector<long long> res(0);

  std::map<long long, long long> frequencies;
  for (auto& e : v) {
    frequencies[e]++;
  }

  long long maxCount = 0;
  for (auto& [element, frequency] : frequencies) {
    if (frequency > maxCount) {
      res.clear();
      maxCount = frequency;
    }
    if (frequency == maxCount) {
      res.push_back(element);
    }
  }

  return res;
}

double calculateRate(const long long frequency, const long long total_size) {
  if (total_size == 0) {
    throw std::runtime_error("Cannot divide by zero");
  }
  return frequency * 1.0 / total_size;
}

double entryRate(const long long entry, const std::vector<long long>& v) {
  if (v.size() == 0) {
    return 0.0;
  }

  long long entryCount = 0;
  for (auto& e : v) {
    if (e == entry) {
      entryCount++;
    }
  }

  return calculateRate(entryCount, v.size());
}

std::vector<std::pair<long long, double>> allEntryRates(
    const std::vector<long long>& v) {
  std::map<long long, long long> frequencies;
  for (auto& e : v) {
    frequencies[e]++;
  }

  std::vector<std::pair<long long, double>> all_entry_rates;
  for (auto& [element, frequency] : frequencies) {
    double rate = calculateRate(frequency, v.size());
    all_entry_rates.push_back({element, rate});
  }

  return all_entry_rates;
}

double average(const std::vector<long long>& v) {
  if (v.size() == 0) {
    throw std::logic_error(
        "There is no average in a vector with 0 elements");
  }

  double sum = 0;
  for (auto& e : v) {
    sum += e;
  }

  return sum / v.size();
}

double median(const std::vector<long long>& v) {
  if (v.size() == 0) {
    throw std::logic_error("There is no median in a vector with 0 elements");
  }

  size_t center_index = v.size() / 2;

  double res = 0;
  if (v.size() % 2 == 0) {
    res = (v[center_index - 1] * 1.0 + v[center_index]) / 2.0;
  } else {
    res = v[center_index];
  }

  return res;
}
};  // namespace statistics