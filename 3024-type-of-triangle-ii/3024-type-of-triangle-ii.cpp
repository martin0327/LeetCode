class Solution {
public:
    string triangleType(vector<int>& a) {
        set<int> s(a.begin(), a.end());
        int mx = 0, tot = 0;
        for (auto x : a) mx = max(mx,x);
        for (auto x : a) tot += x;
        if (mx >= tot-mx) return "none";
        int sz = s.size();
        if (sz==1) return "equilateral";
        if (sz==2) return "isosceles";
        return "scalene";
    }
};