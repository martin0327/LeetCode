using ll = long long;
using ld = long double;
using vi = vector<int>;
using vvi = vector<vi>;
// using vm = vector<mint>;
// using vvm = vector<vm>;
using pii = pair<int,int>;
using vp = vector<pii>;
using vvp = vector<vp>;
using vs = vector<string>;
using vvs = vector<vs>;
using ti3 = tuple<int,int,int>;
using vti3 = vector<ti3>;

template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

class Solution {
public:
    int maximumLength(vector<int>& a) {
        map<ll,ll> mp;
        for (auto x : a) mp[x]++;
        ll ans = 1;
        if (mp.count(1)) {
            ll y = mp[1];
            if (y%2==0) y--;
            ans = max(ans,y);
        }
        for (auto [x,cnt] : mp) {
            if (x==1) continue;
            if (cnt >= 2) {
                ll len = 1;
                ll y = x;
                while (mp.count(y) && mp[y] >= 2) {
                    y = y*y;
                    if (mp.count(y)) {
                        len++;
                    }
                    else break;
                }
                ans = max(ans, 2*len-1);
            }
        }
        return ans;

        
    }
};
