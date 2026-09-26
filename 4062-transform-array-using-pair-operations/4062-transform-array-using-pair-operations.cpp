using ll = long long;
class Solution {
public:
    bool canTransform(vector<int>& a, vector<int>& b) {
        ll x = accumulate(a.begin(), a.end(), 0ll);
        ll y = accumulate(b.begin(), b.end(), 0ll);
        return x == y;
    }
};