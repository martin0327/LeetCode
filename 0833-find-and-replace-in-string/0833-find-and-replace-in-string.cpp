using pss = pair<string,string>;
class Solution {
public:
    string findReplaceString(string s, vector<int>& idx, vector<string>& src, vector<string>& tg) {
        int n = s.size(), k = idx.size();
        map<int,vector<pss>> mp;
        for (int i=0; i<k; i++) {
            auto j = idx[i];
            mp[j].push_back({src[i],tg[i]});
        }
        string ans;
        for (int i=0; i<n;) {
            bool found = false;
            if (mp.count(i)) {
                for (auto [src,tg] : mp[i]) {
                    int sz = src.size();
                    if (s.substr(i,sz) == src) {
                        ans += tg;
                        i += sz;
                        found = true;
                        break;
                    }
                }
            }
            if (!found) ans += s[i++];
        }
        return ans;
    }
};