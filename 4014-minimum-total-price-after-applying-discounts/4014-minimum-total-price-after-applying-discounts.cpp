template<typename T>
void asort(vector<T> &a) {sort(a.begin(), a.end());}
template<typename T>
void dsort(vector<T> &a) {sort(a.rbegin(), a.rend());}
using ld = long double;
class Solution {
public:
    double minPrice(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        dsort(a);
        dsort(b);
        ld ans = 0;
        for (int i=0; i<n; i++) {
            ld x = a[i];
            if (i < m) {
                x *= (100.0 - b[i]) / 100.0;
            }
            ans += x;
        }
        return ans;
    }
};