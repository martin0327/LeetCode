class Solution {
public:
    string addSpaces(string s, vector<int>& sp) {
        string ans;
        set<int> idx(sp.begin(), sp.end());
        for (int i=0; i<s.size(); i++) {
            if (idx.count(i)) ans += ' ';
            ans += s[i];
        }
        return ans;
    }
};