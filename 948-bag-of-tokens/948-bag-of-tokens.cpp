class Solution {
public:
    int bagOfTokensScore(vector<int>& a, int p) {
        sort(a.begin(), a.end());
        deque<int> dq;
        for (auto x : a) dq.push_back(x);
        int ans = 0;
        int cur = 0;
        while (dq.size()) {
            if (p >= dq.front()) {
                p -= dq.front();
                dq.pop_front();
                cur++;
                ans = max(ans, cur);
            }
            else if (cur > 0) {
                cur--;
                p += dq.back();
                dq.pop_back();
            }
            else break;
        }
        return ans;
    }
};