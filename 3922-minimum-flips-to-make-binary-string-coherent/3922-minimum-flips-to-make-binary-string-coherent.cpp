template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        if (n < 3) return 0;
        
        int cnt = 0;
        for (auto ch : s) if (ch == '1') cnt++;

        int ans = n - cnt;
        chmin(ans, cnt);
        if (cnt >= 1) chmin(ans, cnt-1);
        string t(n, '0');
        t.front() = t.back() = '1';
        cnt = 0;
        for (int i=0; i<n; i++) {
            if (s[i] != t[i]) cnt++;
        }
        chmin(ans, cnt);
        return ans;
    }
};