class Solution {
public:
    bool makesquare(vector<int>& a) {
        int n = a.size();
        int tot = 0;
        for (auto x : a) tot += x;
        if (tot%4) return false; // the total sum of lengths should be divisible by 4
        
        for (int m=0; m<(1<<(n-1)); m++) {
            int part = 0;
            for (int i=0; i<n; i++) {
                if ((m>>i)&1) part += a[i];
            }
            if (part != tot/2) continue;  // we first check if the matches can be divided into two partitions with equal sums.
            
            bool b1 = false;
            bool b2 = false;
            
            for (int s=m; s>0; s=(s-1)&m) {  // submask enumeration
                int part = 0;
                for (int i=0; i<n; i++) {
                    if ((s>>i)&1) part += a[i];
                }
                if (part == tot/4) {
					b1 = true;  // we found a submask, sum of which is tot / 4
					break;
				}
            }
            int m2 = m^((1<<n)-1);  // m2 is a 'flip' of mask m
            for (int s=m2; s>0; s=(s-1)&m2) {  // second submask enumeration
                int part = 0;
                for (int i=0; i<n; i++) {
                    if ((s>>i)&1) part += a[i];
                }
                if (part == tot/4) {
					b2 = true; // we found another submask, sum of which is tot / 4
					break;
				}
            }
            if (b1&&b2) return true;  // we found the desired partition :)
        }        
        
        return false; // we failed to find the desired partition :(
    }
};
