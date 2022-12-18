class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        int n = a.size();
        vector<pair<int,int>> b;
        vector<int> ans(n);
        for (int i=0; i<n; i++) {
            while (b.size()) {
                auto [x,j] = b.back();
                if (x < a[i]) {
                    ans[j] = i - j;
                    b.pop_back();
                }
                else break;
            }
            b.push_back({a[i],i});
        }
        return ans;
    }
};