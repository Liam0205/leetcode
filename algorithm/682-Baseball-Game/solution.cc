class Solution {
public:
    int calPoints(std::vector<std::string>& ops) {
        std::deque<int> scores;
        for (auto op : ops) {
            if (op == CANCLE_) {
                scores.pop_back();
            } else if (op == DOUBLE_) {
                scores.push_back(2 * scores.back());
            } else if (op == PLUS_) {
                scores.push_back(scores.back() + *(scores.rbegin() + 1));
            } else {
                scores.push_back(std::atoi(op.c_str()));
            }
        }
        return std::accumulate(scores.begin(), scores.end(), 0);
    }

private:
    const std::string CANCLE_ = "C";
    const std::string DOUBLE_ = "D";
    const std::string PLUS_   = "+";
};

