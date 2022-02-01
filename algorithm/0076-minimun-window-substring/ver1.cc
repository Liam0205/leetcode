static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  std::string minWindow(const std::string& s, const std::string& t) {
    const int m = s.size(), n = t.size();
    if (m < n) {
      return "";
    }
    // array-style map, since only ASCII chars.
    // if map[foo] > 0, some char with ASCII code `foo` in t is not included in s.
    int map[128] = {0};
    for (char c : t) {
      ++map[c];
    }

    int cnt = n /* num_of_char in s that are not included in s */;
    int slow = 0 /* the slow pointer */, fast = 0;
    int dist = std::numeric_limits<int>::max() /* substr length, to be optimized */,
        first = 0 /* valid substr's first pointer */;
    for (fast = 0; fast < m;) {
      char c = s[fast];
      ++fast;
      if (map[c]-- > 0) /* `c` in `t` was found */ {
        --cnt; /* a new match happens */
      }
      while (0 == cnt) /* all chars in t are exactly included in the substr of s */ {
        if (fast - slow < dist) /* find smaller substr! */ {
          dist = fast - slow;
          first = slow;
        }
        // try to cut short the substr from left side
        char c = s[slow];
        ++slow;
        if (map[c]++ == 0) /* `c` is in `t`, and requires new match */ {
          ++cnt;
        }
      }
    }
    return std::numeric_limits<int>::max() == dist ? "" : s.substr(first, dist);
  }
};
