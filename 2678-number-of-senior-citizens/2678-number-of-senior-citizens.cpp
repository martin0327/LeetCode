class Solution {
public:
    int countSeniors(vector<string>& d) {
        int ans = 0;
        for (auto s : d) {
            auto t = s.substr(11,2);
            if (stoll(t) > 60) ans++;
        }
        return ans;
    }
};