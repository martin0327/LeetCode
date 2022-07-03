class Solution {
public:
    int minMoves2(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        int m = n / 2;
        int t = -1;
        if (n&1) {
            t = a[m];    
            int ans = 0;
            for (auto x : a) {
                ans += abs(t-x);
            }
            return ans;
        }
        else {
            t = a[m] + a[m-1];
            if (t&1) {
                t /= 2;
                int ans = 0;
                for (auto x : a) {
                    ans += abs(t-x);
                }
                return ans;
            }
            else {
                t /= 2;
                int ans = 0;
                for (auto x : a) {
                    ans += abs(t-x);
                }
                return ans;
            }
        }
        
        
        
    }
};