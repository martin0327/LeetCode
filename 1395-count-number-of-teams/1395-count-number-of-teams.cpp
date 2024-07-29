class Solution {
public:
    int numTeams(vector<int>& a) {
        int n = a.size();
        int ans = 0;
        for (int i=1; i+1<n; i++) {
            int lgt = 0, llt = 0;
            int rgt = 0, rlt = 0;
            for (int j=0; j<i; j++) {
                if (a[j] < a[i]) llt++;
                else lgt++;
            }
            for (int j=i+1; j<n; j++) {
                if (a[j] < a[i]) rlt++;
                else rgt++;
            }
            ans += lgt * rlt + rgt * llt;
        }
        return ans;        
    }
};