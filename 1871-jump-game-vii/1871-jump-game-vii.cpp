using vi = vector<int>;
const int sz = 1e5+1;
class Solution {
public:
    bool canReach(string s, int lo, int hi) {
        int n = s.size();
        vi a = {0};
        for (int i=1; i<n; i++) {
            if (s[i] == '1') continue;
            int tg = i - hi;
            auto it = lower_bound(a.begin(), a.end(), tg);
            if (it != a.end() && *it <= i-lo) a.push_back(i);
        }
        return a.back() == n-1;
    }
};