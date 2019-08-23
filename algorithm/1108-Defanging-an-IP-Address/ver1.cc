static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::string defangIPaddr(const std::string& address) {
    return replace_all_copy(address, '.', "[.]");
  }

 private:
  inline
  void replace_all(std::string& str, const std::string& from, const std::string& to) {
    const size_t from_sz = from.size(), to_sz = to.size();
    for (size_t i = 0; (i = str.find(from, i)) != std::string::npos; i += to_sz) {
      str.replace(i, from_sz, to);
    }
  }

  inline
  std::string replace_all_copy(std::string str, const std::string& from, const std::string& to) {
    replace_all(str, from, to);
    return str;
  }

  inline
  std::string replace_all_copy(const std::string& str, const char from, const std::string& to) {
    std::string res;
    for (const char c : str) {
      if (from == c) {
        res += to;
      } else {
        res += c;
      }
    }
    return res;
  }
};

