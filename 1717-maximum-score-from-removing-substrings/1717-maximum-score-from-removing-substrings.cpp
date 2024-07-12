using ll = long long;
using vi = vector<ll>;

class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        vi a(n);
        for (int i=0; i<n; i++) a[i] = s[i] - 'a';
        
        ll ans = 0;
        
        if (x < y) {
            swap(x,y);
            for (auto &z : a) {
                if (z<=1) {
                    z ^= 1;
                }
            }
        }
        
        vi b;
        
        for (auto z : a) {
            if (z == 1 && !b.empty() && !b.back()) {
                b.pop_back();
                ans += x;
            }
            else b.push_back(z);
        }
        
        a.clear();
        for (auto z : b) {
            if (!z && !a.empty() && a.back()==1) {
                a.pop_back();
                ans += y;
            }
            else a.push_back(z);
        }
        
        return ans;
        
        
    }
};
