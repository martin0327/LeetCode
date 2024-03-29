class Solution {
public:
    bool validUtf8(vector<int>& a) {
        int n = a.size();
        int i = 0;
        while (i < n) {
            int pos = -1;
            for (int j=0; j<8; j++) {
                if (!((a[i]>>j)&1)) pos = j;
            }
            if (pos==7) i++;
            else {
                int m = 6 - pos;
                if (m>3 || m==0) return false;
                for (int j=i+1; j<=i+m; j++) {
                    if (j >= n) return false;
                    if ((a[j]>>6)&1) return false;
                    if (!((a[j]>>7)&1)) return false;
                }
                i += m + 1;
            }
        }
        return true;
    }
};