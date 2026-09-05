class Solution {
public:
    string optimalDivision(vector<int>& a) {
        int n = a.size();
        if (n == 1) return to_string(a[0]);
        if (n == 2) return to_string(a[0]) + "/" + to_string(a[1]);
        string ans = to_string(a[0]) + "/(";
        for (int i=1; i<n; i++) {
            ans += to_string(a[i]) + '/';
        }
        ans.pop_back();
        ans += ')';
        return ans;
    }
};