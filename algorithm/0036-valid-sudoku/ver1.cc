static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 private:
  const size_t size_ = 9;
  const size_t block_size_ = 3;

 public:
  bool isValidSudoku(const std::vector<std::vector<char>>& m) {
    for (size_t i = 0; i != size_; ++i) {  // validate rows
      int32_t flag = 0x0;
      for (size_t j = 0; j != size_; ++j) {
        char c = m[i][j];
        if (c != '.') {
          int32_t mask = (1 << (c - '0' - 1));
          if (flag & mask) {
            return false;
          } else {
            flag |= mask;
          }
        } else /* lbi */;
      }
    }
    for (size_t j = 0; j != size_; ++j) {  // validate columns
      int32_t flag = 0x0;
      for (size_t i = 0; i != size_; ++i) {
        char c = m[i][j];
        if (c != '.') {
          int32_t mask = (1 << (c - '0' - 1));
          if (flag & mask) {
            return false;
          } else {
            flag |= mask;
          }
        } else /* lbi */;
      }
    }
    for (size_t i = 0; i != block_size_; ++i) {  // validate blocks
      for (size_t j = 0; j != block_size_; ++j) {
        int32_t flag = 0x0;
        for (size_t ii = 0; ii != block_size_; ++ii) {
          for (size_t jj = 0; jj != block_size_; ++jj) {
            char c = m[(i * block_size_ + ii)][j * block_size_ + jj];
            if (c != '.') {
              int32_t mask = (1 << (c - '0' - 1));
              if (flag & mask) {
                return false;
              } else {
                flag |= mask;
              }
            } else /* lbi */;
          }
        }
      }
    }
    return true;
  }
};

