#include <cassert>
#include <cmath>
#include <iostream>
#include <random>
#include <algorithm>
#include <limits>
#include <functional>
#include <map>
#include <vector>
#include <queue>

template <typename T>
class discrete_random_variable {
 private:
  const std::vector<T> values_;
  std::vector<double>  probs_;
  std::vector<size_t>  alias_;
  mutable std::random_device   rd;
  mutable std::mt19937         gen{rd()};
  mutable std::uniform_real_distribution<double> real_dis{0.0, 1.0};
  mutable std::uniform_int_distribution<size_t>  int_dis;

 public:
  discrete_random_variable(const std::vector<T>& vals, std::vector<double> probs) :
      values_(vals), int_dis(0, probs.size() - 1) {
    assert(vals.size() == probs.size());
    const double sum = std::accumulate(probs.begin(), probs.end(), 0.0);
    assert(std::fabs(1.0 - sum) < std::numeric_limits<double>::epsilon());
    const size_t sz = probs.size();
    std::vector<size_t> alias(sz, std::numeric_limits<size_t>::max());
    std::queue<size_t>  small, large;

    for (size_t i = 0; i != sz; ++i) {
      probs[i] *= sz;
      if (probs[i] < 1.0) {
        small.push(i);
      } else {
        large.push(i);
      }
    }

    while (not(small.empty()) and not(large.empty())) {
      auto s = small.front(), l = large.front();
      small.pop(), large.pop();
      alias[s] = l;
      probs[l] -= (1.0 - probs[s]);

      if (probs[l] < 1.0) {
        small.push(l);
      } else {
        large.push(l);
      }
    }

    probs_ = std::move(probs);
    alias_ = std::move(alias);
  }

  T operator()() const {
    const size_t idx  = int_dis(gen);
    if (real_dis(gen) >= probs_[idx] and alias_[idx] != std::numeric_limits<size_t>::max()) {
      return values_[alias_[idx]];
    } else {
      return values_[idx];
    }
  }
};

int main() {
  std::vector<int> values{1, 2, 3, 4};
  std::vector<double> probs{0.05, 0.25, 0.35, 0.35};

  discrete_random_variable<int> drv{values, probs};

  std::map<int, size_t> counter;

  for (size_t i = 0; i != 400000; ++i) {
    int x = drv();
    assert(std::find(values.begin(), values.end(), x) != values.end());
    ++counter[x];
  }
  for (auto pair : counter) {
    std::cout << pair.first << "[" << pair.second << "]" << ": \t";
    for (size_t i = 0; i != pair.second / 2500; ++i) {
      std::cout << '=';
    }
    std::cout << std::endl;
  }

  return 0;
}
