class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> a = {1};
        for (int i=0;i<n; i++) {
            vector<int> b = {1};
            for (int i=1; i<a.size(); i++) {
                b.push_back(a[i]+a[i-1]);
            }
            b.push_back(1);
            a = b;
        }
        return a;
    }
};