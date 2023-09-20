class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans = 0;
        for (int i=low; i<=high; i++) {
            string s = to_string(i);
            int n = s.size();
            if (n&1) continue;
            int l = 0, r = 0;
            for (int i=0; i<n/2; i++) l += s[i]-'0';
            for (int i=n/2; i<n; i++) r += s[i]-'0';            
            if (l==r) ans++;
        }
        return ans;
    }
};