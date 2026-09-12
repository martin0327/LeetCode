template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using vi = vector<int>;
const int sz = 1e5+1;
const int inf = 0x3f3f3f3f;
vi b;
int dp[sz];
class Solution {
public:
    int minDays(int n) {
        if (b.empty()) {
            b = {1};
            for (int i=2;;i++) {
                b.push_back(b.back() + i);
                if (b.back() > sz) break;
            }
            int m = b.size();
            memset(dp,0x3f,sizeof(dp));
            for (int i=0; i<m; i++) {
                auto &x = b[i];
                if (x >= sz) break;
                dp[x] = i+1;
            }
            for (int i=0; i<m; i++) {
                int x = b[i], cost = i+2;
                for (int j=1; j<sz; j++) {
                    int nj = j + x;
                    if (nj >= sz) continue;
                    chmin(dp[nj],dp[j]+cost);
                }
            }
        }
        return dp[n];
    }
};