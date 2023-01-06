class Solution {
public:
    int maxIceCream(vector<int>& a, int c) {
        sort(a.begin(), a.end());
        long long cum = 0, ans = 0;
        for (auto x : a) {
            cum += x;
            if (cum > c) break;
            ans++;
        }
        return ans;
    }
};