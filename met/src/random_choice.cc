#include <iostream>
#include <vector>
#include <random>
#include <unordered_set>
#include <algorithm>

namespace yuuki {
template <typename vector_type>
vector_type random_choice(const vector_type& vec, const size_t k) {
  const size_t sz = vec.size();
  if (k == sz) {
    return vec;
  } else if (k > sz) {
    std::terminate();
  }

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<size_t> dis(0, sz - 1);

  std::unordered_set<size_t> chosen;
  for (size_t i = 0; i != k; ++i) {
    size_t r = dis(gen);
    while (r < sz and chosen.find(r) != chosen.end()) r = ++r % sz;
    chosen.insert(r);
  }

  vector_type res;
  res.reserve(k);
  for (auto i : chosen) {
    res.push_back(vec[i]);
  }
  return res;
}
}  // namespace yuuki

int main() {
  std::vector<int> v{1, 2, 3, 4};
  auto vv = yuuki::random_choice(v, 3);
  std::for_each(vv.begin(), vv.end(), [&](auto e) { std::cout << e << ' '; });
  std::cout << std::endl;

  return 0;
}
