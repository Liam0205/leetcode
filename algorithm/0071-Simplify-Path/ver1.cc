static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::string simplifyPath(std::string path) {
    std::vector<std::string> s;
    std::istringstream iss(path);
    std::string line;
    while (std::getline(iss, line, '/')) {
      if ("." == line) {
        /* pass */
      } else if (".." == line) {
        if (s.empty()) {
          /* pass */
        } else {
          s.pop_back();  // drop.
        }
      } else if (!line.empty()) {
        s.push_back(line);
      } else {
        /* empty line, drop */
      }
    }
    if (s.empty()) {
      return "/";
    } else {
      std::string res;
      for (auto& str : s) {
        res.append("/");
        res.append(std::move(str));
      }
      return res;
    }
  }
};
