class Solution {
 public:
  bool isScramble(const std::string& lhs, const std::string& rhs) {
    if (lhs == rhs) {
      return true;
    } else if (lhs.size() != rhs.size()) {
      return false;
    } else { ; }
    std::string l = lhs, r = rhs;
    std::sort(l.begin(), l.end());
    std::sort(r.begin(), r.end());
    if (l != r) { return false; }

    const size_t sz = lhs.size();
    for (size_t i = 1; i != sz; ++i) {
      if ((isScramble(lhs.substr(0, i), rhs.substr(0, i)) and isScramble(lhs.substr(i), rhs.substr(i))) or
          (isScramble(lhs.substr(0, i), rhs.substr(sz - i)) and isScramble(lhs.substr(i), rhs.substr(0, sz - i)))) {
        return true;
      }
    }

    return false;
  }
};
