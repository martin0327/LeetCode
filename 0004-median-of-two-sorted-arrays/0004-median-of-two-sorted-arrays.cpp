class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        vector<int> c;
        for (auto x : a) c.push_back(x);
        for (auto x : b) c.push_back(x);
        sort(c.begin(), c.end());
        int n = c.size();
        double ans;
        if (n%2==0) {
            ans = (c[n/2] + c[n/2-1]) / 2.0;
        }
        else {
            ans = c[n/2];
        }
        return ans;
    }
};