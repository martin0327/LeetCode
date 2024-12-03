class Solution {
public:
    string addSpaces(string s, vector<int>& sp) {
        string ans;
        int n = s.size();
        set<int> ss(sp.begin(), sp.end());
        if (ss.count(0)) ans += ' ';
        for (int i=0; i<n; i++) {
            ans += s[i];
            if (ss.count(i+1)) ans += ' ';
        }
        return ans;        
    }
};