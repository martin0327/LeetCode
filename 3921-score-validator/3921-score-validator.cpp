class Solution {
public:
    vector<int> scoreValidator(vector<string>& a) {
        int t = 0, c = 0;
        for (auto s : a) {
            int x = s[0] - '0';
            if (0 <= x && x <= 6) {
                t += x;
            }
            else {
                if (s == "W") c++;
                else t++;
            }
            if (c == 10) break;
        }
        vector<int> ans = {t,c};
        return ans;
    }
};