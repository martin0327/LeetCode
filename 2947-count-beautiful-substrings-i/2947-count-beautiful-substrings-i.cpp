class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        string v = "aeiou";
        set<char> sc(v.begin(), v.end());
        
        int n = s.size(), ans = 0;
        for (int i=0; i<n; i++) {
            int x = 0, y = 0;
            for (int j=i; j<n; j++) {
                if (sc.count(s[j])) x++;
                else y++;
                if (x == y && (x*y)%k == 0) ans++;
            }
        }
        
        return ans;
    }
};