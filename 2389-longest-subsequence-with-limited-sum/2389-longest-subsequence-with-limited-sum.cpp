using ll = long long;
class Solution {
public:
    vector<int> answerQueries(vector<int>& a, vector<int>& b) {
        sort(a.begin(), a.end());
        vector<int> ans;
        for (auto x : b) {
            ll temp = 0;
            ll cnt = 0;
            for (auto y : a) {
                temp += y;
                if (temp > x) break;
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};