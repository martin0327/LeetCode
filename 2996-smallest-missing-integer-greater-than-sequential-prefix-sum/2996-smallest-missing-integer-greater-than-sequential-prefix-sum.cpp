class Solution {
public:
    int missingInteger(vector<int>& a) {
        int n = a.size();
        set<int> s(a.begin(), a.end());
        int x = a[0];
        for (int i=1; i<n && a[i] == a[i-1]+1; i++) x += a[i];
        while (s.count(x)) x++;
        return x;
    }
};