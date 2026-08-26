class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagrp;
        vector<vector<string>> result;

        for (auto str : strs) {
            vector<int> signature(26, 0);
            for (auto c : str) {
                signature[c - 'a']++;
            }
            string key = "";
            for (auto n : signature) {
                key += to_string(n) + ',';
            }
            anagrp[key].push_back(str);
        }

        for (auto it : anagrp) {
            result.push_back(it.second);
        }

        return result;

    }
};
