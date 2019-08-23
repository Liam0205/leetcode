static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  int numTilePossibilities(const std::string& tiles) {
    std::map<char, uint32_t> counter;
    for (const char c : tiles) {
      const bool found = (counter.end() != counter.find(c));
      if (found) {
        ++counter[c];
      } else {
        counter.insert({c, 1});
      }
    }
    return dfs(counter);
  }

 private:
  int dfs(std::map<char, uint32_t>& counter) {
    int sum = 0;
    for (auto& pair : counter) {
      if (pair.second == 0) continue;
      ++sum;
      --pair.second;
      sum += dfs(counter);
      ++pair.second;
    }
    return sum;
  }
};

