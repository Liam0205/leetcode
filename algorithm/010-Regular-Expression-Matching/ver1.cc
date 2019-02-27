class Solution {
public:
  inline
  bool isMatch(const std::string& s, const std::string& p) {
    return isMatch(s.c_str(), p.c_str());
  }

  bool isMatch(const char* s, const char* p) {
    if (*p == '\0') {
      return *s == '\0';
    } else if (*(p + 1) == '\0' or *(p + 1) != '*') {
      if (*s == '\0' or ( *p != '.' and *s != *p)) {
        return false;
      } else {
        return isMatch(s + 1, p + 1);
      }
    } else {
      int len = strlen(s);
      int i = -1;
      for (int i = -1; i < len and (i < 0 or *p == '.' or *p == *(s + i)); ++i) {
        if (isMatch(s + i + 1, p + 2)) {
          return true;
        }
      }
      return false;
    }
  }
};

