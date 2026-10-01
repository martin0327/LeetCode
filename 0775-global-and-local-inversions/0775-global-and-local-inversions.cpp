using pii = pair<int,int>;
class Solution {
public:
    bool isIdealPermutation(vector<int>& a) {
        int n = a.size();
        vector<pii> b(n);
        for (int i=0; i<n; i++) {
            b[i] = {a[i],i};
        }
        sort(b.begin(), b.end());
        for (int i=0; i<n; i++) {
            auto [x,j] = b[i];
            if (abs(i-j) > 1) return false;
        }
        return true;
    }
};