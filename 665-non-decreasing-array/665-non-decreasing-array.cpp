class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        int n = a.size();
        vector<int> b = a;
        int cnt1 = 0, cnt2 = 0;
        for (int i=0; i<n-1; i++) {
            if (a[i] > a[i+1]) {
                if (i==0) {
                    a[i] = a[i+1];
                    cnt1++;
                }
                else {
                    a[i+1] = a[i];
                    cnt1++;
                }
            }
            if (b[n-2-i] > b[n-1-i]) {
                if (i==0) {
                    b[n-1-i] = b[n-2-i];
                    cnt2++;
                }
                else {
                    b[n-2-i] = b[n-1-i];
                    cnt2++;
                }
            }
        }
        
        
        return cnt1 <= 1 || cnt2 <=1;
    }
};