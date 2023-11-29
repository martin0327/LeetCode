using ll = long long;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& a, vector<int>& b) {
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        auto f = [&] (vector<int> a) {
            ll cnt = 0, ret = 1;
            for (int i=0; i<a.size(); i++) {
                if (cnt==0) cnt++;
                else {
                    if (a[i]-a[i-1]==1) cnt++;
                    else cnt = 1;
                }
                ret = max(ret, cnt);
            }
            return ret;
        };        
        ll s = min(f(a),f(b))+1;
        return s*s;
    }
};