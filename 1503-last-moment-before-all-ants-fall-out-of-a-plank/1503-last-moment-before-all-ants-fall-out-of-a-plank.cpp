class Solution {
public:
    int getLastMoment(int n, vector<int>& l, vector<int>& r) {
        int minr = r.size() ? *min_element(r.begin(), r.end()) : n;
        int maxl = l.size() ? *max_element(l.begin(), l.end()) : 0;
        return max(n-minr, maxl);
    }
};