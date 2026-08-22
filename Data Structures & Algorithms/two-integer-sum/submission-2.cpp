class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mapT;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int complement = target - nums[i];
            if (mapT.contains(complement)) {
                return {mapT[complement], i};
            }
            mapT[nums[i]] = i;
        }
        return {};
    }
};
