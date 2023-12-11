using ll = long long;
using vi = vector<ll>;

class Solution {
public:
    long long countSubarrays(vector<int>& a, int k) {
        ll n = a.size(), mx = *max_element(a.begin(), a.end());

//        vi b = {-1};
        vi b;
        for (int i=0; i<n; i++) {
            if (a[i] == mx) b.push_back(i);
        }
 //       b.push_back(n);
        ll m = b.size(), ans = 0;
        for (int i=0; i<m; i++) {
            if (i+k-1 >= m) break;
            ll l = b[i] - (i > 0 ? b[i-1] : -1);
            ll r = n - b[i+k-1];
            ans += l*r;
        }
        
        return ans;
        

    }
};


// o o o o o o o o o o o o

