#include <cassert>
#include <cmath>
#include <iostream>
#include <random>
#include <algorithm>
#include <limits>
#include <functional>
#include <map>
#include <vector>

template <typename T>
class discrete_random_variable {
 private:
  const std::vector<T>         values_;
  const std::vector<double>    cumulative_;
  mutable std::random_device   rd_;
  mutable std::mt19937         gen_{rd_()};
  mutable std::uniform_real_distribution<double> dis_{0.0, 1.0};

 public:
  discrete_random_variable(const std::vector<T>& val, const std::vector<double>& prob) :
      values_(val), cumulative_(generate_cumulative(prob)) {
    assert(val.size() == prob.size());
    assert(std::fabs(1.0 - cumulative_.back()) < std::numeric_limits<double>::epsilon());
  }

  T operator()() const {
    const double rand = dis_(gen_);
    const size_t idx  = bsearch_last_not_greater_than(cumulative_.begin(), cumulative_.end(), rand);
    assert(idx < values_.size());
    return values_[idx];
  }

 private:
  std::vector<double> generate_cumulative(const std::vector<double>& prob) {
    std::vector<double> cumulative;
    cumulative.reserve(prob.size() + 1);
    cumulative.emplace_back(0);
    std::transform(prob.begin(), prob.end(), std::back_inserter(cumulative),
        [&](const double p) { return p + cumulative.back(); } );
    return cumulative;
  }

  template <typename iter_t,
            typename value_t = typename std::iterator_traits<iter_t>::value_type,
            typename binpred_t = std::less<value_t>>
  size_t bsearch_last_not_greater_than(const iter_t begin,
                                       const iter_t end,
                                      const value_t target,
                                          binpred_t binpred = binpred_t()) const {
    iter_t first = begin, last = end;
    while (first < last) {
      iter_t mid = first + std::distance(first, last) / 2;
      if (not(binpred(target, *mid)) and
            (std::next(mid) == last or binpred(target, *(std::next(mid))))) {
        return std::distance(begin, mid);
      } else if (binpred(target, *mid)) {
        last = mid;
      } else {
        first = std::next(mid);
      }
    }
    return std::distance(begin, end);
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
