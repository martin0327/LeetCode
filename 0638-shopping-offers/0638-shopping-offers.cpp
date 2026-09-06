template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using vi = vector<int>;
const int sz = 11;
const int inf = 0x3f3f3f3f;
int dp[sz][sz][sz][sz][sz][sz];
class Solution {
public:
    int shoppingOffers(vector<int>& c, vector<vector<int>>& offer, vector<int>& a) {
        memset(dp,0x3f,sizeof(dp));
        while (a.size() < 6) {
            a.push_back(0);
            c.push_back(0);
        }
        int n = offer.size();
        vi sp(n);
        for (int i=0; i<n; i++) {
            auto &v = offer[i];
            sp[i] = v.back();
            v.pop_back();
            while (v.size() < 6) {
                v.push_back(0);
            }
        }

        dp[0][0][0][0][0][0] = 0;
        for (int i0=0; i0<=a[0]; i0++) {
            for (int i1=0; i1<=a[1]; i1++) {
                for (int i2=0; i2<=a[2]; i2++) {
                    for (int i3=0; i3<=a[3]; i3++) {
                        for (int i4=0; i4<=a[4]; i4++) {
                            for (int i5=0; i5<=a[5]; i5++) {
                                auto &cur = dp[i0][i1][i2][i3][i4][i5];
                                if (cur == inf) continue;
                                for (int j=0; j<n; j++) {
                                    auto &v = offer[j];
                                    int ni0 = i0 + v[0];
                                    int ni1 = i1 + v[1];
                                    int ni2 = i2 + v[2];
                                    int ni3 = i3 + v[3];
                                    int ni4 = i4 + v[4];
                                    int ni5 = i5 + v[5];
                                    if (ni0 > a[0]) continue;
                                    if (ni1 > a[1]) continue;
                                    if (ni2 > a[2]) continue;
                                    if (ni3 > a[3]) continue;
                                    if (ni4 > a[4]) continue;
                                    if (ni5 > a[5]) continue;
                                    chmin(dp[ni0][ni1][ni2][ni3][ni4][ni5], cur + sp[j]);
                                }
                            }
                        }
                    }
                }
            }
        }

        int ans = inf;
        for (int i0=0; i0<=a[0]; i0++) {
            for (int i1=0; i1<=a[1]; i1++) {
                for (int i2=0; i2<=a[2]; i2++) {
                    for (int i3=0; i3<=a[3]; i3++) {
                        for (int i4=0; i4<=a[4]; i4++) {
                            for (int i5=0; i5<=a[5]; i5++) {
                                auto t = dp[i0][i1][i2][i3][i4][i5];
                                t += (a[0]-i0) * c[0];
                                t += (a[1]-i1) * c[1];
                                t += (a[2]-i2) * c[2];
                                t += (a[3]-i3) * c[3];
                                t += (a[4]-i4) * c[4];
                                t += (a[5]-i5) * c[5];
                                chmin(ans, t);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    }
};