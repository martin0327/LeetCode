class Solution {
public:
    int captureForts(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        for (int i=0; i<n; i++) {
            if (a[i]==1) {
                for (int j=i+1; j<n; j++) {
                    if (a[j]==-1) {
                        ans = max(ans, j-i-1);
                        break;
                    }
                    else if (a[j]==1) break;
                }
                for (int j=i-1; j>=0; j--) {
                    if (a[j]==-1) {
                        ans = max(ans, i-j-1);
                        break;
                    }
                    else if (a[j]==1) break;
                }
            }
        }
        return ans;
    }
};