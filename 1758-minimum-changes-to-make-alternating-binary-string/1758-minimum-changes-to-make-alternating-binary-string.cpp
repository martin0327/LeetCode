class Solution {
public:
    int minOperations(string s) {
        int cnt=0, n = s.size();
        for (int i=0; i<n; i++) {
            if ((i&1) ^ (s[i]=='1')) cnt++;
        }
        return min(cnt,n-cnt);        
    }
};