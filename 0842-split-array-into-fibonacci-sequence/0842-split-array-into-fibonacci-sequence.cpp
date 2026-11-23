using ll = long long;
using vi = vector<ll>;
class Solution {
public:
    vector<int> splitIntoFibonacci(string s) {
        ll n = s.size(), lim = (1ll<<31);
        for (int i=0; i<n; i++) {
            auto x = stoll(s.substr(0,i+1));
            if (x >= lim) break;
            if (to_string(x).size() != i+1) break;
            for (int j=i+1; j<n; j++) {
                auto y = stoll(s.substr(i+1,j-i));
                if (y >= lim) break;
                if (to_string(y).size() != j-i) break;
                vi a = {x,y};
                int l = j+1;
                bool ok = true;
                while (l < n) {
                    int sz = a.size();
                    auto z = a[sz-1] + a[sz-2];
                    if (z >= lim) {
                        ok = false;
                        break;
                    }
                    auto t = to_string(z);
                    if (t == s.substr(l,t.size())) {
                        a.push_back(z);
                        l += t.size();
                    }
                    else {
                        ok = false;
                        break;
                    }
                }
                if (ok && a.size() > 2) {
                    vector<int> ans(a.begin(), a.end());
                    return ans;
                }
            }
        }
        vector<int> ans;
        return ans;
    }
};