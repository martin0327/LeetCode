class Solution {
public:
    vector<int> concatWithReverse(vector<int>& a) {
        int n = a.size();
        for (int i=0; i<n; i++) {
            a.push_back(a[n-1-i]);
        }
        return a;
    }
};