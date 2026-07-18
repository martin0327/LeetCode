class Solution {
public:
    int findGCD(vector<int>& a) {
        auto it = minmax_element(a.begin(), a.end());
        return gcd(*it.first, *it.second);
    }
};