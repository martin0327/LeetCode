class Solution {
public:
    int minimumAddedCoins(vector<int>& a, int t) {
        sort(a.rbegin(), a.rend());
        long long ans = 0, acc = 0;
        for (int i=1; i<=t; i++) {
            while (a.size() && a.back() <= acc+1) {
                acc += a.back();
                a.pop_back();
            }
            if (i > acc) {
                acc += i;
                ans++;
            }
        }
        return ans;
    }
};