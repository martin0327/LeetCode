class Solution {
public:
    int minOperations(string s) {
        int cnt1=0, cnt2=0, n = s.size();
        for (int i=0; i<n; i++) {
            if ((i&1) ^ (s[i]=='1')) cnt1++;
            if ((i&1) ^ (s[i]=='0')) cnt2++;
        }
        return min(cnt1,cnt2);        
    }
};