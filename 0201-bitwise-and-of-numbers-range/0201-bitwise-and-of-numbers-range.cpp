class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
        int ans = 0;
        bool flag = false;
        for (int i=30; i>=0; i--) {
            bool x = l>>i&1;
            bool y = r>>i&1;
            if (y & !x) flag = true;
            if (!flag && (x&y)) ans += (1<<i);
        }
        return ans;
    }
};