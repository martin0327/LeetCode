class Solution {
public:
    int buyChoco(vector<int>& a, int k) {
        sort(a.begin(), a.end());
        int s = a[0] + a[1];
        return k >= s ? k - s : k;
    }
};