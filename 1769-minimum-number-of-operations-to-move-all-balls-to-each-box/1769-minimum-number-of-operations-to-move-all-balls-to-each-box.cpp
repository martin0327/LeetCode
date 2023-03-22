class Solution {
public:
    vector<int> minOperations(string s) {
        int n = s.size();
        vector<int> ans(n);
        // int l = 0, r = 0;
        int cnt = 0;
        for (int i=0; i<n; i++) {
            if (s[i] == '1') {
                ans[0] += i;
                // r++;
                cnt++;
            }
        }
        for (int i=0; i<n; i++) {
            // if (i) ans[i] = ans[i-1] + l - r;
            if (i) ans[i] = ans[i-1] - cnt;
            if (s[i] == '1') {
                // l++; r--;
                cnt -= 2;
            }
        }
        return ans;
    }
};


