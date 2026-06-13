class Solution {
public:
    string mapWordWeights(vector<string>& a, vector<int>& b) {
        string ans;
        for (auto s : a) {
            int res = 0;
            for (auto ch : s) {
                res += b[ch - 'a'];
            }
            res %= 26;
            ans += 'a' + (25 - res);
        }
        return ans;
    }
};