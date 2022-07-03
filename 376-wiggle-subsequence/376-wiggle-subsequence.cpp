class Solution {
public:
    int wiggleMaxLength(vector<int>& a) {
        int flag = 0;
        int n = a.size();
        int ans = 1;
        
        for (int i=1; i<n; i++) {
            if (flag == 0 && a[i] != a[i-1]) {
                ans++;
                flag = a[i] > a[i-1] ? 1 : -1;
            }
            else if (flag * a[i] < flag * a[i-1]) {
                ans++;
                flag *= -1;
            }
        }
        return ans;
    }
};