using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
    int findTheLongestSubstring(string s) {
        string t = "aeiou";
        map<char,int> mp;
        int m = 5;
        for (int i=0; i<m; i++) {
            mp[t[i]] = i;
        }
        int n = s.size();
        vvi a(1<<m);
        int cur = 0;
        a[cur].push_back(0);
        
        for (int i=0; i<n; i++) {
            auto c = s[i];
            if (mp.count(c)) {
                cur ^= (1<<mp[c]);
            }
            a[cur].push_back(i+1);
        }
        int ans = 0;
        for (int i=0; i<(1<<m); i++) {
            if (a[i].size()) {
                int t = a[i].back() - a[i].front();
                ans = max(ans, t);
            }
        }
        return ans;
    }
};