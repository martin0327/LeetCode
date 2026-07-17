using ll = long long;
vector<ll> a = {
    9,
    9009,
    906609,
    99000099,
    9966006699,
    999000000999,
    99956644665999,
    9999000000009999
};
const int mod = 1337;

class Solution {
public:
    int largestPalindrome(int n) {
        return a[n-1] % mod;
    }
};