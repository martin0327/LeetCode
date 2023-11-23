using ti3 = tuple<int,int,int>;
const int inf = 1e9;

class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& a, vector<int>& ql, vector<int>& qr) {
        int n = a.size(), q = ql.size(), sz = sqrt(n);
        map<int,vector<ti3>> mo;
        for (int i=0; i<q; i++) {
            int l = ql[i], r = qr[i];
            mo[l/sz].push_back({r,l,i});
        }
        int i=0, j=0;
        map<int,int> mp, d;
        int mul_cnt = 0;
        mp[a[0]]++;

        auto inc1 = [&] (int x) { if (++mp[x] == 2) mul_cnt++; };
        auto dec1 = [&] (int x) {
            if (mp[x] == 2) mul_cnt--;
            if (--mp[x] == 0) mp.erase(x);
        }; 

        auto inc2 = [&] (int x) {d[x]++;};
        auto dec2 = [&] (int x) { if (--d[x] == 0) d.erase(x); };

        auto push = [&] (int x) {
            auto it1 = mp.lower_bound(x);
            auto it2 = mp.upper_bound(x);
            int l = (it1 == mp.begin()) ? inf : prev(it1)->first;
            int r = (it2 == mp.end()) ? inf : it2->first;
            if (mp.count(x)) inc1(x);
            else {
                if (l != inf && r != inf) {
                    dec2(r-l);
                    inc2(r-x);
                    inc2(x-l);
                    inc1(x);
                }
                else if (l != inf) {
                    inc2(x-l);
                    inc1(x);
                }
                else if (r != inf) {
                    inc2(r-x);
                    inc1(x);
                }
                else inc1(x);
            }
        };

        auto pop = [&] (int x) {
            auto it1 = mp.lower_bound(x);
            auto it2 = mp.upper_bound(x);
            int l = (it1 == mp.begin()) ? inf : prev(it1)->first;
            int r = (it2 == mp.end()) ? inf : it2->first;
            if (mp[x] > 1) dec1(x);
            else {
                if (l != inf && r != inf) {
                    dec2(x-l);
                    dec2(r-x);
                    inc2(r-l);
                    dec1(x);
                }
                else if (l != inf) {
                    dec2(x-l);
                    dec1(x);
                }
                else if (r != inf) {
                    dec2(r-x);
                    dec1(x);
                }
                else dec1(x);
            }
        };
        
        vector<bool> ans(q);
        for (auto &[_,rli] : mo) {
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