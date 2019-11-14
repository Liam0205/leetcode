class Solution {
public:
    bool judgeCircle(string moves) {
        size_t lcnt = 0, rcnt = 0, ucnt = 0, dcnt = 0;
        for (const auto& c : moves) {
            switch (c) {
                case 'L':
                    ++lcnt;
                    break;
                case 'R':
                    ++rcnt;
                    break;
                case 'U':
                    ++ucnt;
                    break;
                case 'D':
                    ++dcnt;
                    break;
                default:
                    break;
            }
        }
        return lcnt == rcnt and ucnt == dcnt;
    }
};
