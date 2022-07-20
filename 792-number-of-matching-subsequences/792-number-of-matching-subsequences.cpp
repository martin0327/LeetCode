class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char,vector<int>> mp;
        int n = s.size();
        for (int i=0; i<n; i++) {
            mp[s[i]].push_back(i);
        }
        int ans = 0;
        for (auto w : words) {
            bool flag = true;
            int idx = -1;
            for (auto c : w) {
                auto it = upper_bound(mp[c].begin(), mp[c].end(), idx);
                if (it == mp[c].end()) {
                    flag = false;
                    break;
                }
                else idx = *it;
            }
            if (flag) ans++;
        }
        return ans;
    }
};