class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        const size_t rowsz = board.size(), colsz = board[0].size();
        int res = 0;
        for (size_t i = 0; i != rowsz; ++i) {
            for (size_t j = 0; j != colsz; ++j) {
                if (board[i][j] == 'X' and
                    (i == 0 or (board[i - 1][j] != 'X')) and
                    (j == 0 or (board[i][j - 1] != 'X'))) {
                    ++res;
                }
            }
        }
        return res;
    }
};
