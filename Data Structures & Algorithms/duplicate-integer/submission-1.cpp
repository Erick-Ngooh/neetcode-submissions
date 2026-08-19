class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> m;

        for (int i = 0; i < n; i++) {
            if (m.contains(nums[i]))
                return true;
            m[nums[i]] = i;
        }
        return false;
    }
};