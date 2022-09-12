class Solution {
public:
    int bagOfTokensScore(vector<int>& a, int p) {
        int n = a.size();
        sort(a.begin(), a.end());
        int l = 0, r = n-1, ans = 0, cur = 0;
        while (l<=r) {
            if (p >= a[l]) {
                p -= a[l++];
                ans = max(ans, ++cur);
            }
            else if (cur-- > 0) p += a[r--];
            else break;
        }
        return ans;
    }
}; 