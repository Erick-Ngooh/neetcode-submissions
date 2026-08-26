class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int current = 0;
        int previous = 0;
        int count = 0;

        freq[0] = 1;
        for (auto num : nums) {
            current += num;
            previous = current - k;
            if (freq.find(previous) != freq.end()) {
                count += freq[previous];
            }
            freq[current]++;
        }
        return count;
    }
};