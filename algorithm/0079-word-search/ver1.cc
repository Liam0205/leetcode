static const auto io_sync_off = []() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  return nullptr;
}();

class Solution {
 public:
  bool exist(std::vector<std::vector<char>>& board, const std::string& word) {
    const int m = board.size(), n = board[0].size();
    const int l = word.size();
    if (m * n < l) {
      return false;
    }
    for (int i = 0; i != m; ++i) {
      for (int j = 0; j != n; ++j) {
        if (backtracking(board, word, m, n, l, i, j, 0)) {
          return true;
        }
      }
    }
    return false;
  }

 private:
  bool backtracking(std::vector<std::vector<char>>& board, const std::string& word, const int m, const int n,
                    const int l, int i /* row index */, int j /* column index */, int k /* word offset */) {
    if (k == l) {
      return true;
    } else if (!(0 <= i && i < m) || !(0 <= j && j < n)) {
      return false;
    } else if (board[i][j] != word[k]) {
      return false;
    } else {
      board[i][j] = '\0';  // mark as matched.
      bool ret = backtracking(board, word, m, n, l, i + 1, j, k + 1) ||
                 backtracking(board, word, m, n, l, i, j + 1, k + 1) ||
                 backtracking(board, word, m, n, l, i - 1, j, k + 1) ||
                 backtracking(board, word, m, n, l, i, j - 1, k + 1);
      board[i][j] = word[k];
      return ret;
    }
  }
};
