class Solution {
public:
    int maxDistance(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        int i=0, j=0, ans=0;
        while (i<n) {
            if (i<n && j<m && i<=j && a[i] <= b[j]) ans = max(ans, j-i);
            if (i>=j || (j < m && a[i]<=b[j])) j++;
            else i++;
        }
        return ans;
    }
};