using vi = vector<int>;
int sm(int x, int k) {
    x %= k;
    if (x < 0) x += k;
    return x;
}
class Solution {
public:
    int longestSubarray(vector<int>& a, int k) {
        int n = a.size();
        a.insert(a.begin(),0);
        vi d(n+1);
        for (int i=1; i<=n; i++) {
            d[i] = -2*a[i];
            a[i] = sm(a[i],k);
            d[i] = sm(-2*a[i],k);
        }
        vi pre(n+1);
        for (int i=1; i<=n; i++) {
            pre[i] = sm(pre[i-1]+a[i],k);
        }
        int ans = 0;
        for (int i=0; i<=n; i++) {
            set<int> s = {0};
            for (int j=i-1; j>=0; j--) {
                s.insert(d[j+1]);
                auto tg = sm(pre[j]-pre[i],k);
                if (s.count(tg)) ans = max(ans, i-j);
            }
        }
        return ans;
    }
};