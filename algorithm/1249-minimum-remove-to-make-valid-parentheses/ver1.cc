#pragma GCC optimise ("Ofast")

static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::string minRemoveToMakeValid(std::string& s) {
    std::stack<size_t> deletion;
    const size_t sz = s.size();
    for (size_t i = 0; i != sz; ++i) {
      if (s[i] == '(') {
        deletion.push(i);
      } else if (s[i] == ')') {
        if (not deletion.empty() and s[deletion.top()] == '(') {
          deletion.pop();
        } else {
          deletion.push(i);
        }
      }
    }
    while (not deletion.empty()) {
      s.erase(deletion.top(), 1);
      deletion.pop();
    }
    return s;
  }
};

