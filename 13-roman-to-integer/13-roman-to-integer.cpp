class Solution {
public:
    int romanToInt(string s) {
        string a = "IVXLCDM";
        vector<int> b = {1,5,10,50,100,500,1000};
        unordered_map<char,int> mp;
        for (int i=0; i<7; i++) mp[a[i]] = b[i];
        int ans = 0;
        int n = s.size();
        for (int i=0; i<n; i++) {
            int mult = 1;
            if (i<n-1) {
                int q = mp[s[i+1]] / mp[s[i]];
                if (q==5 || q==10) mult = -1;
            }
            ans += mult*mp[s[i]];
        }
        return ans;
    }
};