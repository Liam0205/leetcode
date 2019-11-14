#pragma GCC optimise ("Ofast")

static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<int> numSmallerByFrequency(const std::vector<std::string>& queries,
                                         const std::vector<std::string>& words) {
    size_t recoder[12];  // max_len == 10, plus one for zero-based indexing, plus one for line #29
    std::fill(std::begin(recoder), std::end(recoder), 0);
    for (const std::string& word : words) {
      ++recoder[freqfunc(word)];
    }
    size_t bigger_sum = 0;
    std::transform(std::rbegin(recoder), std::rend(recoder), std::rbegin(recoder),
        [&](size_t count) {
          bigger_sum += count;
          return bigger_sum;
        });

    std::vector<int> res;
    res.reserve(queries.size());
    for (const std::string& query : queries) {
      res.push_back(recoder[freqfunc(query) + 1]);
    }
    return res;
  }

 private:
  size_t freqfunc(const std::string& s) {
    std::map<char, size_t> counter;
    for (auto c : s) {
      ++counter[c];
    }
    return counter.begin()->second;
  }
};

