class Solution {
public:
    int binaryGap(int N) {
        int res = 0;
        int last_meet_pos = -1;
        int cnt = 0;
        while (N) {
            if (N & 0x01) {
                if (-1 != last_meet_pos) {
                    res = std::max(res, cnt - last_meet_pos);
                }
                last_meet_pos = cnt;
            }
            N >>= 1;
            ++cnt;
        }
        return res;
    }
};
