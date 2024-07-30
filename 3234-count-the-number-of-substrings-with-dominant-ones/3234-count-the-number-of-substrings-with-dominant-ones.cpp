using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using ti3 = tuple<ll,ll,ll>;
using vs = vector<string>;

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

class Solution {
public:
    int numberOfSubstrings(string s) {
        ll n = s.size();
        vi idx;
        idx.push_back(-1);
        for (int i=0; i<n; i++) {
            if (s[i] == '0') idx.push_back(i);
        }
        vvi t;
        for (int i=0; i<n; i++) {
            if (t.empty()) t.push_back({i});
            else {
                int idx = t.back().back();
                if (s[i] == s[idx]) t.back().push_back(i);
                else t.push_back({i});
            }
        }
        ll sz = idx.size();
        idx.push_back(n);
        
        ll lim = sqrt(n) + 1;

        ll ans = 0;
        for (ll len=1; len<=lim; len++) {
            for (int i=1; i+len-1<sz; i++) {
                ll l = idx[i];
                ll r = idx[i+len-1];
                ll ones = r-l+1 - len;

                if (len*len <= ones) {
                    ll left = (l-idx[i-1]);
                    ll right = (idx[i+len]-r);
                    ans += left * right;
                }
                else {
                    ll diff = len*len - ones;
                    ll left = (l-idx[i-1]-1);
                    ll right = (idx[i+len]-r-1);
                    if (left+right >= diff) {
                        ll init = max(0ll, diff-right);
                        for (ll x=init; x<=left; x++) {
                            ans += right - max(diff-x,0ll) + 1;
                        }
                    }
                }

            }
            
        }
        for (auto v : t) {
            if (s[v.back()] == '0') continue;
            int sz = v.size();
            ans += sz*(sz+1)/2;
        }
        return ans;

        
    }
};