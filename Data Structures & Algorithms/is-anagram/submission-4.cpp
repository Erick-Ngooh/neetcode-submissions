class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size())
            return false;
        unordered_map<char, int> mapS;
        unordered_map<char, int> mapT;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            mapS[s[i]] += 1;
            mapT[t[i]] += 1;            
        }
        return mapS == mapT;
    }
};
