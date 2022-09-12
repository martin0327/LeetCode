class Solution {
public:
    int bagOfTokensScore(vector<int>& a, int p) {
        sort(a.begin(), a.end());
        int l = 0, r = a.size()-1, ans = 0, cur = 0;
        while (l<=r) {
            if (p >= a[l]) {
                p -= a[l++];
                ans = max(ans, ++cur);
            }
            else if (cur--) p += a[r--];
            else break;
        }
        return ans;
    }
}; 