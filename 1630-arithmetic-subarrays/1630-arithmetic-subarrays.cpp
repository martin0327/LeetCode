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
        
        int i=0, j=0, mul = 0;
        map<int,int> mp1, mp2;
        mp1[a[0]]++;

        auto inc1 = [&] (int x) { if (++mp1[x] == 2) mul++; };
        auto dec1 = [&] (int x) {
            if (mp1[x] == 2) mul--;
            if (--mp1[x] == 0) mp1.erase(x);
        }; 
        auto inc2 = [&] (int x) { mp2[x]++; };
        auto dec2 = [&] (int x) { if (--mp2[x] == 0) mp2.erase(x); };
        
        auto lr = [&] (int x) {
            auto it1 = mp1.lower_bound(x);
            auto it2 = mp1.upper_bound(x);
            int l = (it1 == mp1.begin()) ? inf : prev(it1)->first;
            int r = (it2 == mp1.end()) ? inf : it2->first;
            return make_pair(l,r);
        };

        auto push = [&] (int x) {
            auto [l,r] = lr(x);
            if (!mp1.count(x)) {
                if (l != inf) inc2(x-l);
                if (r != inf) inc2(r-x);
                if (l != inf && r != inf) dec2(r-l);
            }
            inc1(x);
        };

        auto pop = [&] (int x) {
            auto [l,r] = lr(x);
            if (mp1[x] == 1) {
                if (l != inf) dec2(x-l);
                if (r != inf) dec2(r-x);
                if (l != inf && r != inf) inc2(r-l);
            }
            dec1(x);
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
                if (mul+mp2.size()==1) ans[idx] = 1;
            }
        }
        return ans;
    }
}; 