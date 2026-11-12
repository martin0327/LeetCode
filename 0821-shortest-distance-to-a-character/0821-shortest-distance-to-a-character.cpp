using vi = vector<int>;
void chmin(int &x, int y) { x = min(x,y); }
class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vi idx, ans(n, n);
        for (int i=0; i<n; i++) {
            if (s[i] == c) idx.push_back(i);
        }
        for (int i=0; i<n; i++) {
            auto it = lower_bound(idx.begin(), idx.end(), i);
            if (it != idx.end()) chmin(ans[i], *it - i);
            if (it != idx.begin()) chmin(ans[i], i - *prev(it));
        }
        return ans;
    }
};