class Solution {
public:
    int solve(string s) {
        if (s.size()==2) return 1;
        int cur = 0;
        int cnt = 0;
        vector<pair<int,int>> a;
        int n = s.size();
        for (int i=0; i<n; i++) {
            if (s[i] == '(') cnt++;
            else cnt--;
            if (cnt==0) {
                a.emplace_back(cur,i);
                cur = i+1;
            }
        }
        
        if (a.size()==1) {
            return 2*solve(s.substr(1,n-2));
        }
        int ret = 0;
        for (auto [l,r] : a) {
            ret += solve(s.substr(l,r-l+1));
        }
        return ret;        
    }
    int scoreOfParentheses(string s) {
        int ans = solve(s);
        return ans;        
    }
};