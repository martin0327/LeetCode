class Solution {
public:
    int minGroupsForValidAssignment(vector<int>& a) {
        map<int,int> mp;
        for (auto x : a) mp[x]++;
        vector<int> b;
        for (auto [k,v] : mp) b.push_back(v);
        set<int> s(b.begin(), b.end());
        int K = -1;
        for (int k=1; k<=*s.begin(); k++) {
            bool ok = true;
            for (auto x : s) {
                int q = x / k;
                if (q*(k+1) < x) ok = false;
            }
            if (ok) K = k;
        }
        int ans = 0;
        for (auto x : b) {
            for (int i=0; i<=x/K; i++) {
                if (i*K <= x && x<=i*(K+1)) {
                    ans += i;
                    break;
                }
            }
        }
        return ans;
    }
};
