class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int counter_one  = 0;
        int counter_flip = 0;
        for (auto ch : S) {
            counter_flip += '1' - ch;
            counter_one  += ch - '0';
            counter_flip = std::min(counter_one, counter_flip);
        }
        return counter_flip;
    }
};
