class Solution {
public:
    vector<int> constructArray(int n, int k) {
        int m = k+1, d = 1;
        vector<int> a = {(m+1)/2};
        while (a.size() < m) {
            int sign = ((d&1)^(m&1))?1:-1;
            int x = a.back() + d * sign;
            a.push_back(x);
            d++;
        }
        while (a.size() < n) {
            a.push_back(a.back()+1);
        }
        return a;
    }
};