using ll = long long;
class Solution {
public:
    int chalkReplacer(vector<int>& a, int k) {
        ll s = 0;
        for (auto x : a) s += x;
        k %= s;
        for (int i=0; i<a.size(); i++) {
            if (a[i] > k) return i;
            k -= a[i];
        }
        return -1;
    }
};