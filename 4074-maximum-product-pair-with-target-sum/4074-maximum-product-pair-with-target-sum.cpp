
class Solution {
public:
    vector<int> maxProductPair(vector<int>& a, int tg) {
        int n = a.size(), mx = -2e9;
        vector<int> ans = {-1,-1};
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (a[i] + a[j] == tg) {
                    if (a[i] > a[j]) {
                        auto z = a[i] * a[j];
                        if (z > mx) {
                            mx = z;
                            ans = {i,j};
                        }
                    }
                }
            }
        }
        return ans;
    }
};