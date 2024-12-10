class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        map<string,int> mp;
        for (int i=0; i<n; i++) {
            for (int j=i; j<n; j++) {
                string t = s.substr(i,j-i+1);
                set<char> sc(t.begin(), t.end());
                if (sc.size()==1) mp[t]++;
            }
        }
        int ans = -1;
        for (auto [t,cnt] : mp) {
            if (cnt >= 3) {
                int sz = t.size();
                ans = max(ans, sz);
            }
        }
        return ans;
    }
};