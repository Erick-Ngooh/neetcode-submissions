class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;
        vector<vector<int>> freq(n + 1);
        vector<int> res;

        for (auto num : nums) {
            count[num]++;
        }
        for (auto it : count) {
            freq[it.second].push_back(it.first);
        }
        //std::cout << freq[2] << "   " << n << '\n';
        for (int i = n; i >= 0; i--) {
            if (!freq[i].empty()) {
                for (auto num : freq[i]) {
                    res.push_back(num);
                }
            }
            if (res.size() == k)
                return res;
        }
        return {0};
    }
};
