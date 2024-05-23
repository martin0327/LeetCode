class Solution {
public:
    int beautifulSubsets(vector<int>& a, int k) {
        int n = a.size();
        sort(a.begin(), a.end());
        vector<int> b;
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (a[j] - a[i] == k) {
                    b.push_back((1<<i) + (1<<j));
                }
            }
        }
        
        int ans = 0;
        for (int mask=1; mask<(1<<n); mask++) {
            bool ok = true;
            for (auto x : b) {
                if ((mask&x) == x) ok = false;
            }
            if (ok) ans++;
        }
        return ans;
    }
};