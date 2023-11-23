using ll = long long;
using ti3 = tuple<ll,ll,ll>;
using vi = vector<ll>;
const ll inf = 2e18;


class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& a, vector<int>& ql, vector<int>& qr) {
        ll n = a.size(), q = ql.size(), sz = sqrt(n);
        map<ll,vector<ti3>> mo;
        for (int i=0; i<q; i++) {
            ll l = ql[i], r = qr[i];
            mo[l/sz].push_back({r,l,i});
        }
        ll i=0, j=0;
        map<ll,ll> mp, d;
        ll mul_cnt = 0;
        mp[a[0]]++;

        auto inc = [&] (int x) { if (++mp[x] == 2) mul_cnt++; };

        auto dec = [&] (int x) {
            if (mp[x] == 2) mul_cnt--;
            if (--mp[x] == 0) mp.erase(x);
        }; 

        auto incd = [&] (int x) {d[x]++;};
        auto decd = [&] (int x) { if (--d[x] == 0) d.erase(x); };

        auto push = [&] (int x) {
            auto it1 = mp.lower_bound(x);
            auto it2 = mp.upper_bound(x);
            ll l = (it1 == mp.begin()) ? inf : prev(it1)->first;
            ll r = (it2 == mp.end()) ? inf : it2->first;
            if (mp.count(x)) inc(x);
            else {
                if (l != inf && r != inf) {
                    decd(r-l);
                    incd(r-x);
                    incd(x-l);
                    inc(x);
                }
                else if (l != inf) {
                    incd(x-l);
                    inc(x);
                }
                else if (r != inf) {
                    incd(r-x);
                    inc(x);
                }
                else inc(x);
            }
        };

        auto pop = [&] (int x) {
            auto it1 = mp.lower_bound(x);
            auto it2 = mp.upper_bound(x);
            ll l = (it1 == mp.begin()) ? inf : prev(it1)->first;
            ll r = (it2 == mp.end()) ? inf : it2->first;
            if (mp[x] > 1) dec(x);
            else {
                if (l != inf && r != inf) {
                    decd(x-l);
                    decd(r-x);
                    incd(r-l);
                    dec(x);
                }
                else if (l != inf) {
                    decd(x-l);
                    dec(x);
                }
                else if (r != inf) {
                    decd(r-x);
                    dec(x);
                }
                else dec(x);
            }
        };
        
        vector<bool> ans(q);
        for (auto &[qt,rli] : mo) {
            sort(rli.begin(), rli.end());
            for (auto [r,l,idx] : rli) {
                while (i!=l || j!=r) {
                    if (r>j) push(a[++j]);
                    else if (l<i) push(a[--i]);
                    else if (r<j) pop(a[j--]);
                    else if (l>i) pop(a[i++]);
                }
                if (mul_cnt == 0) {
                    if (d.size()==1) ans[idx] = 1;
                }
                else if (mul_cnt == 1) {
                    if (mp.size()==1) ans[idx] = 1;
                }
            }
        }
        return ans;
    }
};