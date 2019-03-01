class Solution {
public:
    std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
        std::unordered_map<int, size_t> counter;
        for (auto num : nums) {
            ++counter[num];
        }
        std::priority_queue<std::pair<size_t, int>, std::vector<std::pair<size_t, int>>, std::greater<std::pair<size_t, int>>> auto_heap;
        for (auto kv : counter) {
            auto_heap.push({kv->second, kv->first});
            while (auto_heap.size() > k) {
                auto_heap.pop();
            }
        }
        std::vector<int> res;
        res.reserve(k);
        while (not auto_heap.empty()) {
            res.emplace_back(auto_heap.top().second);
            auto_heap.pop();
        }
        return res;
    }
};

