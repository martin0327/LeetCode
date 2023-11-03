class Solution {
public:
    vector<string> buildArray(vector<int>& a, int n) {
        int cur = 1;
        vector<string> ans;
        for (auto x : a) {
            while (cur < x) {
                ans.push_back("Push");
                ans.push_back("Pop");
                cur++;
            }
            cur++;
            ans.push_back("Push");
        }
        return ans;
    }
};