class Solution {
public:
    int missingInteger(vector<int>& a) {
        int n = a.size();
        set<int> s(a.begin(), a.end());
        int x = a[0];
        for (int j=1; j<n; j++) {
            if (a[j] == a[j-1]+1) x += a[j];
            else break;
        }
        while (s.count(x)) x++;
        return x;
    }
};