class Solution {
public:

    string encode(vector<string>& strs) {
        string res;

        for (auto str : strs) {
            res += to_string(str.size()) + '#';
            res += str;
        }

        return res;
    }

    int first_diez(string str, int i) {
        for (int j = i; j < str.size(); j++) {
            if (str[j] == '#') {
                return j;
            }
        }
        return i;
    }


    vector<string> decode(string s) {
        vector<string> res;

        int i = 0;
        int jDiez = 0;
        int len = 0;
        while (i < s.size()) {
            jDiez = first_diez(s, i);
            string num;
            while (i < s.size() && i < jDiez) {
                num += s[i];
                i++;
            }
            i++;
            len = stoi(num) + i;
            string word;
            while (i < s.size() && i < len) {
                word += s[i];
                i++;
            }
            res.push_back(word);
        }
        return res;
    }
};
