static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
   std::string customSortString(const std::string& S, std::string& T) {
    std::map<char, size_t> order_map;
    getOrderMap(S, &order_map);
    std::sort(T.begin(), T.end(), [&](auto l, auto r) { return order_map[l] < order_map[r]; });
    return T;
  }

 private:
  void getOrderMap(const std::string& S, std::map<char, size_t>* order_map) {
    const size_t sz = S.size();
    for (size_t i = 0; i != sz; ++i) {
      order_map->insert({S[i], i});
    }
  }
};

