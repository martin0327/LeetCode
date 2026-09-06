class Solution {
public:
    int countRotations(string s, int k) {
        int n = s.size();
        auto f = [&] (string t) {
            int n = t.size();
            int ret = 0;
            for (int i=1; i<n; i++) {
                if (t[i] == t[i-1]) ret++;
            }
            return ret;
        };
        int ans = 0;
        for (int i=0; i<n; i++) {
            auto t = s.substr(i,n-i);
            t += s.substr(0,i);
            auto x = f(t);
            if (x == k) ans++;
        }
        return ans;
    }
};