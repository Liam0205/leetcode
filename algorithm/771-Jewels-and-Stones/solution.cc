class Solution {
public:
    int numJewelsInStones(string J, string S) {
        std::unordered_set<char> jewels(J.begin(), J.end());
        int count = 0;
        for (auto c : S) {
            auto search = jewels.find(c);
            auto found  = search != jewels.end();
            if (found) {
                ++count;
            }
        }
        return count;
    }
};
