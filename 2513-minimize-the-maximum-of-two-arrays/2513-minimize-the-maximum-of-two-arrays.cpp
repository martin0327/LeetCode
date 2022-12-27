using ll = long long;
class Solution {
public:
    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        ll d1 = divisor1, d2 = divisor2;
        ll cnt1 = uniqueCnt1, cnt2 = uniqueCnt2;
        
        ll lo = 1, hi = 9e9;
        ll ans = -1;
        while (lo <= hi) {
            ll m = (lo + hi) / 2;
            ll a = m / d1;
            ll b = m / d2;
            ll ab = m / lcm(d1,d2);
            
            ll temp1 = max(cnt1 - (b - ab), 0ll);
            ll temp2 = max(cnt2 - (a - ab), 0ll);
            temp1 = max(temp1, 0ll);
            temp2 = max(temp2, 0ll);
            if (temp1 + temp2 <= m - (a+b-ab)) {
                ans = m;
                hi = m - 1;
            }
            else lo = m + 1;
        }
        return ans;
    }
};