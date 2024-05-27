class Solution {
public:
    int specialArray(vector<int>& a) {
        int n = a.size();
        for (int i=0; i<=n; i++) {
            int cnt = 0;
            for (auto x : a) {
                if (x >= i) cnt++;
            }
            if (cnt == i) return i;
        }
        return -1;
    }
};