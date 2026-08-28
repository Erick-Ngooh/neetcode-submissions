class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> mp;
        int len = 0;
        int res = 0;

        for (auto n : nums) {
            if (!mp[n]) {
                mp[n] = 1;
                len = mp[n - 1] + mp[n] + mp[n + 1];
                mp[n - mp[n - 1]] = len;
                mp[n + mp[n + 1]] = len;
                res = max(res, len);
            }
        }
        return res;
    }
};
