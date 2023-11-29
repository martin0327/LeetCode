const int inf = 1e9;
class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
        int n = a.size(), ans = inf;
        {
            int cnt = 0;
            for (int i=0; i<n; i++) {
                if (a[i] <= a.back() && b[i] <= b.back()) continue;
                if (b[i] <= a.back() && a[i] <= b.back()) cnt++;
                else {
                    cnt = inf;
                    break;
                }
            }
            ans = min(ans, cnt);
        }
        {
            int cnt = 1;
            swap(a.back(), b.back());
            for (int i=0; i<n; i++) {
                if (a[i] <= a.back() && b[i] <= b.back()) continue;
                if (b[i] <= a.back() && a[i] <= b.back()) cnt++;
                else {
                    cnt = inf;
                    break;
                }
            }
            ans = min(ans, cnt);            
        }
        if (ans == inf) ans = -1;
        return ans;
    }
};