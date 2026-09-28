class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int sz = s.size(), idx = -1;
        for (int i=0; i+1<sz; i++) {
            auto x = s[i], y = s[i+1];
            if (x > y) {
                idx = i;
                break;
            }
        }
        if (idx == -1) return stoi(s);
        int idx2 = idx;
        for (int i=idx; i>=0; i--) {
            auto x = s[i], y = s[idx];
            if (x == y) {
                idx2 = i;
            }
            else break;
        }
        s[idx2]--;
        for (int i=idx2+1; i<sz; i++) s[i] = '9';
        auto ans = stoi(s);
        return ans;
    }
};