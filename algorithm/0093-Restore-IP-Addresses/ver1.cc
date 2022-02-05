static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::vector<std::string> restoreIpAddresses(const std::string& s) {
    std::vector<std::string> ret;
    std::string ans;

    for (int a = 1; a <= 3; a++) {
      for (int b = 1; b <= 3; b++) {
        for (int c = 1; c <= 3; c++) {
          for (int d = 1; d <= 3; d++) {
            if (a + b + c + d == s.size()) {
              int A = std::atoi(s.substr(0, a).c_str());
              int B = std::atoi(s.substr(a, b).c_str());
              int C = std::atoi(s.substr(a + b, c).c_str());
              int D = std::atoi(s.substr(a + b + c, d).c_str());
              if (A <= 255 && B <= 255 && C <= 255 && D <= 255)
                if ((ans = std::to_string(A) + "." + std::to_string(B) + "." + std::to_string(C) + "." +
                           std::to_string(D))
                        .size() == s.size() + 3)
                  ret.push_back(ans);
            }
          }
        }
      }
    }

    return ret;
  }
};
