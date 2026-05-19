using ll = long long;
using pii = pair<int,int>;
const int sz = 1e5+1;
int c1[sz], c2[sz];
class Solution {
public:
    long long countSubarrays(vector<int>& a, int k, int m) {
        ll n = a.size(), ans = 0;
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        set<pii> s1, s2;
        auto f = [&] (int x) {
            pii tg1 = {c1[x],x};
            pii tg2 = {c2[x],x};
            if (s1.count(tg1)) s1.erase(tg1);
            if (s2.count(tg2)) s2.erase(tg2);
            s1.insert({++c1[x],x});
            s2.insert({++c2[x],x});
        };
        
        auto g1 = [&] (int x) {
            pii tg = {c1[x],x};
            if (s1.count(tg)) s1.erase(tg);
            if (--c1[x] > 0) {
                s1.insert({c1[x],x});
            }
        };

        auto g2 = [&] (int x) {
            pii tg = {c2[x],x};
            if (s2.count(tg)) s2.erase(tg);
            if (--c2[x] > 0) {
                s2.insert({c2[x],x});
            }
        };

        for (int i=0,l=0,r=0; i<n; i++) {
            f(a[i]);
            while (s2.size() > k) g2(a[r++]);
            while (s2.size() == k && (s2.begin()->first) >= m) {
                if (c2[a[r]] > m) g2(a[r++]);
                else break;
            }

            while (s1.size() > k) g1(a[l++]);
            if (s2.size() == k && (s2.begin()->first) >= m) {
                ans += r-l+1;
            }
        }
        return ans;
    }
};