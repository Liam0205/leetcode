static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  bool isMatch(const std::string& s, const std::string& p) {
    const size_t szs = s.size(), szp = p.size();
    size_t star_p = -1, star_s = -1;
    size_t is = 0, ip = 0;
    while (is != szs) {
      if (p[ip] == '?' || p[ip] == s[is]) {
        // meet '?' in pattern, what every s[is] is, advance both pointer.
        // meet same char in p[ip] && s[is], advance both pointer.
        ++is, ++ip;
      } else if (p[ip] == '*') {
        // meet '*', record star_p & star_s, advance ip.
        star_p = ip;
        star_s = is;
        ++ip;
      } else if (-1 != star_p) {
        // mismatch, but we've met a '*', make it match more chars in s.
        ip = star_p + 1;
        is = ++star_s;
      } else {
        return false;
      }
    }
    while (ip != szp && '*' == p[ip]) {
      ++ip;
    }
    return ip == szp;
  }
};
