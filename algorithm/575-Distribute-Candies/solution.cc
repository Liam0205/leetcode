class Solution {
public:
    int distributeCandies(std::vector<int>& candies) {
        std::unordered_set<int> uniqued(candies.begin(), candies.end());
        return std::min(uniqued.size(), candies.size() / 2);
    }
};

