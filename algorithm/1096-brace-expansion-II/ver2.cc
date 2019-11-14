#pragma GCC optimise ("Ofast")

static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<std::string> braceExpansionII(const std::string& expression) {
    size_t idx = 0;
    std::set<std::string> strings = dfs(expression, expression.size(), idx);
    std::vector<std::string> res(strings.begin(), strings.end());
    return res;
  }

 private:
  std::set<std::string> dfs(const std::string& expr, const size_t sz, size_t& idx) {
    std::set<std::string> res, sub;

    while (idx < sz and expr[idx] != '}') {
      if (expr[idx] == ',') {  // just compelete a sub-expr, union!
        res.insert(sub.begin(), sub.end());
        sub.clear();
        ++idx;
      } else {  // still in sub-expr, store in `cur` for cartesian product with `sub`.
        std::set<std::string> cur;
        if (expr[idx] == '{') {
          cur = dfs(expr, sz, ++idx);
        } else {
          std::string tmp;
          while ('a' <= expr[idx] and expr[idx] <= 'z') {
            tmp += expr[idx++];
          }
          cur.insert(tmp);
        }

        if (sub.empty()) {
          std::swap(sub, cur);
        } else {
          std::set<std::string> tmp;
          for (auto& c : cur) {
            for (auto& s : sub) {
              tmp.insert(s + c);
            }
          }
          std::swap(sub, tmp);
        }
      }
    }

    res.insert(sub.begin(), sub.end());
    ++idx;
    return res;
  }
};

