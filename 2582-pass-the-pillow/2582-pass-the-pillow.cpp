class Solution {
public:
    int passThePillow(int n, int t) {
        int r = t % (2*n-2);
        
        if (r >= n) {
            r = n-1 - (r - (n-1) );
        }
        return r+1;
        
        
        
    }
};
// 1 2 3 4 3 2 
    
// 0 1 2 3 2 1 
// 0 1 2 3 4 5 