#include <vector>
#include <stdexcept>
#include <map>

namespace statistics {
std::vector<int> mostFrequentElements(const std::vector<int>& v) {
  if (v.size() == 0) {
    throw std::logic_error(
        "There is no most frequent element in an array with 0 elements");
  }

  std::vector<int> res(0);

  std::map<int, int> frequencies;
  for (auto& e : v) {
    frequencies[e]++;
  }

  int maxCount = 0;
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

double average(const std::vector<int>& v) {
  if (v.size() == 0) {
    throw std::logic_error(
        "There is no average in an array with 0 elements");
  }

  double sum = 0;
  for (auto& e : v) {
    sum += e;
  }

  return sum / v.size();
}

double median(const std::vector<int>& v) {
  if (v.size() == 0) {
    throw std::logic_error("There is no median in an array with 0 elements");
  }

  size_t center_index = v.size() / 2;

  double res = 0;
  if (v.size() % 2 == 0) {
    res = (v[center_index] * 1.0 + v[center_index + 1]) / 2.0;
  } else {
    res = v[center_index];
  }

  return res;
}
};  // namespace statistics