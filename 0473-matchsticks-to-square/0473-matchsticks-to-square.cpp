class Solution {
public:
    bool makesquare(vector<int>& a) {
        int n = a.size();
        int tot = 0;
        for (auto x : a) tot += x;
        if (tot%4) return false; // the total sum of lengths should be divisible by 4
        
        auto f = [&] (int m) {
            for (int s=m; s>0; s=(s-1)&m) {  // submask enumeration
                int part = 0;
                for (int i=0; i<n; i++) {
                    if ((s>>i)&1) part += a[i];
                }
                if (part == tot/4)  return true;
            }
            return false;
        };
        
        for (int m=0; m<(1<<(n-1)); m++) {
            int part = 0;
            for (int i=0; i<n; i++) {
                if ((m>>i)&1) part += a[i];
            }
            if (part != tot/2) continue;  // we first check if the matches can be divided into two partitions with equal sums.
            
            bool b1 = f(m);  // first submask enumeration
            bool b2 = f(m^((1<<n)-1)); // second submask enumeration
            
            if (b1&&b2) return true;  // we found the desired partition :)
        }        
        
        return false; // we failed to find the desired partition :(
    }
};
