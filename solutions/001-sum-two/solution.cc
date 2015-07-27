class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> working_map;
        vector<int> result;
        for(int i = 0; i < nums.size(); ++i){
            if (working_map.find(nums[i]) == working_map.end() ) { 
                // if nums[i] is not in the map, 
                // then take its friend as the key and its position as the value.
                working_map[target - nums[i]] = i; 
            }else { 
                // if nums[i] is in the map,
                // it means that, its friend has been encountered by us, and its position is working_map[nums[i]]
                // push them back to the result vector.
                result.push_back(working_map[nums[i]] + 1);
                result.push_back(i + 1);
                break;
            }
        }
        return result;
    }
};
