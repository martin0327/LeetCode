class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& a) {
        int n = a.size();
        sort(a.begin(), a.end());
        set<int> s;
        for (int i=1; i<n; i++) {
            s.insert(a[i]-a[i-1]);
            if (s.size() > 1) return false;
        }
        return true;
    }
};