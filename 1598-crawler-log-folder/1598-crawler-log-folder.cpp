class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for (auto s : logs) {
            if (s.substr(0,2) == "..") ans--;
            else if (s[0] == '.') continue;
            else ans++;
            ans = max(ans, 0);
        }
        return ans;
    }
};