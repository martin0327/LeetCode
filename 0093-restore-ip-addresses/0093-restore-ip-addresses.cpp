class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        int m = n-1;
        vector<string> ans;
        for (int msk=0; msk<1<<m; msk++) {
            if (__builtin_popcount(msk)!=3) continue;
            vector<string> a = {string(1, s[0])};
            for (int i=0; i<m; i++) {
                if (msk>>i&1) a.push_back(string(1,s[i+1]));
                else a.back().push_back(s[i+1]);
            }
            string t;
            bool ok = true;
            for (auto x : a) {
                if (x.front()=='0' && x.size()>1) ok = false;
                if (stoll(x) > 255) ok = false;
                if (ok) t += x + '.';                
            }
            if (ok) {
                t.pop_back();
                ans.push_back(t);
            }
        }
        return ans;
    }
};