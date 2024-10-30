using vi = vector<int>;

void debug(vi a) {
    for (auto x : a) cout << x << " ";
    cout << endl;
}

class Solution {
public:
    int minimumMountainRemovals(vector<int>& a) {
        int n = a.size(), ans = n;
        
        auto f = [&] (vi &a) {
            int n = a.size();
            vi b;
            for (int i=0; i<n; i++) {
                int x = a[i];        
                auto it = lower_bound(b.begin(), b.end(), x);
                if (it == b.end()) b.push_back(x);
                else *it = x;
            }
            int ret = b.size();
            return ret;
        };
                
        for (int i=1; i+1<n; i++) {
            vi b, c;
            for (int j=0; j<i; j++) {
                if (a[j] < a[i]) b.push_back(a[j]);
            }
            for (int j=n-1; j>i; j--) {
                if (a[j] < a[i]) c.push_back(a[j]);
            }
            if (!b.empty() && !c.empty()) {
                // vi temp = {f(b),f(c)};
                // debug(temp);
                ans = min(ans, n-1-f(b)-f(c));            
            }
        }
        return ans;
        // vi b = a;
        // reverse(b.begin(), b.end());
        // auto c = f(a);
        // auto d = f(b);
        // reverse(d.begin(), d.end());
        // int ans = n-c.back();
        // for (int i=0; i+1<n; i++) {
        //     int l = i+1-c[i];
        //     int r = n-i-d[i];
        //     cout << l << " " << r << endl;
        //     ans = min(ans, l+r);
        // }
        // debug(c);
        // debug(d);
        return ans;
    }
};