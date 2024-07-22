class Solution {
public:
    vector<string> sortPeople(vector<string>& a, vector<int>& b) {
        int n = a.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&] (int i, int j) {
            return b[i] > b[j];
        });
        auto ans = a;
        for (int i=0; i<n; i++) {
            ans[i] = a[idx[i]];
        }
        return ans;
    }
};