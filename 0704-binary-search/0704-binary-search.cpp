class Solution {
public:
    int search(vector<int>& a, int t) {
        auto it = lower_bound(a.begin(), a.end(),t);
        if (it != a.end() && *it==t) return (int) (it - a.begin());
        else return -1;
    }
};