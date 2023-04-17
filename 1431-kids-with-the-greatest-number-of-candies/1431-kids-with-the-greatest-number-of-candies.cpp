class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& a, int k) {
        int n = a.size();
        int mx = *max_element(a.begin(), a.end());
        vector<bool> ret(n);
        for (int i=0; i<n; i++) {
            ret[i] = a[i]+k >= mx;
        }
        return ret;
    }
};