class Solution {
public:
    int numRescueBoats(vector<int>& a, int w) {
        sort(a.rbegin(), a.rend());
        int i,j;
        
        for (i=0, j=a.size()-1; i<=j; i++) {
            if(a[i]+a[j]<=w) j--;
        }
        
        return i;
    }
};