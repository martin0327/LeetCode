class Solution {
public:
    int minimumOperations(string s) {
        int n = s.size();
        vector<bool> a(10);
        for (int i=n-1; i>=0; i--) {
            int x = s[i] - '0';
            if ((x==7 || x==2) && a[5]) return n-i-2;
            if ((x==5 || x==0) && a[0]) return n-i-2;
            a[x] = true;
        }
        return n-a[0];        
    }
};