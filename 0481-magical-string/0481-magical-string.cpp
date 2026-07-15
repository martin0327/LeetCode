class Solution {
public:
    int magicalString(int n) {
        if (n == 1) return 1;
        string s = "122";
        int i = 2;
        while (s.size() < 2*n) {
            auto cnt = s[i] - '0';
            char x = (s.back() == '1') ? '2' : '1';
            while (cnt--) {
                s += x;
            }
            i++;
        }
        int ans = 0;
        for (int i=0; i<n; i++) {
            ans += s[i] == '1';
        }
        return ans;
        
    }
};
