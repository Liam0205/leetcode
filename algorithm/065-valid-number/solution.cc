class Solution {
public:
  bool isNumber (string s) {
    size_t sz_len = s.size(), sz_i = 0;
    if (sz_len < 1) return false;
    // skip leading spaces
    for (; sz_i != sz_len && isspace(s.at(sz_i)); ++sz_i) {}
    // skip pm sign
    if (sz_i != sz_len && (s.at(sz_i) == '+' || s.at(sz_i) == '-')) ++sz_i;
    // there should be at least 1 digit and at most 1 dot
    // in the `x.y' part
    int int_cnt_dot = 0, int_cnt_digit = 0;
    for (; sz_i != sz_len; ++sz_i) {
      if (isdigit(s.at(sz_i))) ++int_cnt_digit;
      else if (s.at(sz_i) == '.') ++int_cnt_dot;
      else break;
    }
    if (int_cnt_dot > 1 || int_cnt_digit < 1) return false;
    // if exp, there must be at least 1 digit after `e'
    if (sz_i != sz_len && (s.at(sz_i) == 'e' || s.at(sz_i) == 'E')) {
      ++sz_i; // read next
      // skip pm sign
      if (sz_i != sz_len && (s.at(sz_i) == '+' || s.at(sz_i) == '-')) ++sz_i;
      int_cnt_digit = 0;
      for (; sz_i != sz_len; ++sz_i) {
        if (isdigit(s.at(sz_i))) ++int_cnt_digit;
        else break;
      }
      if (int_cnt_digit < 1) return false;
    }
    // skip the tailing spaces
    for (; sz_i != sz_len && isspace(s.at(sz_i)); ++sz_i) {}
    // if hit the end, return true, else, return false
    return (sz_i == sz_len);
  }
};
