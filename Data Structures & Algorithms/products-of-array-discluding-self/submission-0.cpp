class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int prefix = 1;
        int postfix = 1;
        int n = nums.size();
        vector<int> output(n, 1);

        for (int i = 0, j = n - 1; i < n; i++, j--) {
                output[i] *= prefix;
                prefix *= nums[i]; 
                output[j] *= postfix;
                postfix *= nums[j];
        } 
        return output;
    }
};
