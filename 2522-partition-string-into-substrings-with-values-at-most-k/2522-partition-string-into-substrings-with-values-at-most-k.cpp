using ll = long long;
class Solution {
public:
    int minimumPartition(string s, int k) {
        int n = s.size();
        if (k < 10) {
            for (auto c : s) {
                if (c-'0' > k) return -1;
            }
        }
        ll cur = 0;
        ll cnt = 0;
        for (int i=0; i<n; i++) {
            int x = s[i] - '0';
            if (cur*10 + x > k) {
                cur = x;
                cnt++;
            }
            else cur = cur*10 + x; 
        }
        if (cur) cnt++;
        return cnt;
    }
};