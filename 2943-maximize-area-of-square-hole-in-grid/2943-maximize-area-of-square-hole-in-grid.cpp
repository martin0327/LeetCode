using ll = long long;

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& a, vector<int>& b) {
        ll mx1 = 1, mx2 = 1;
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        {
            ll cnt = 0;
            for (int i=0; i<a.size(); i++) {
                if (cnt==0) {
                    cnt++;
                }
                else {
                    if (a[i]-a[i-1]==1) cnt++;
                    else cnt = 1;
                }
                mx1 = max(mx1, cnt);
            }
        }
        {
            ll cnt = 0;
            for (int i=0; i<b.size(); i++) {
                if (cnt==0) {
                    cnt++;
                }
                else {
                    if (b[i]-b[i-1]==1) cnt++;
                    else cnt = 1;
                }
                mx2 = max(mx2, cnt);
            }
        }
        ll s = min(mx1,mx2);
        s++;
        return s*s;        
        
    }
};