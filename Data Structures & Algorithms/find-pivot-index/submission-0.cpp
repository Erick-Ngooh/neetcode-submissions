class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> prefix;
        int right = 0;
        int total = 0;

        for (auto num : nums) {
            total += num;
            prefix.push_back(total);
        }
        int left = 0;
        for (int i = 0; i < nums.size(); i++) {
            right = total - left - nums[i];
            if (right == left)
                return i;
            left += nums[i];
        }
        return -1;
    }
};