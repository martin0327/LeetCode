// // sort first
// // you can't iterate in a nested for loops
// // if your number x can be divided by y and z (y < z)
// // and y and z are also in the array
// // then replacing x with y is always better than replacing x with z 
// // harmonic sum? 
// // 1 + 1/2 + 1/3 + 1/4 + ... + 1/n ~ log(n)
// // n + n/2 + n/3 + n/4 + ... + n/n = n(1 + 1/2 + 1/3 + ... + 1/n) ~ n*log(n)

// // if 1 is in my array, then every number can be replaced by 1
// // if 2 is in my array, then every even number can be replaced by 2
// // if 3 is in my array, then every multiple of 3 can be replaced by 3

// // when m = 1e5, 
// // how many x <= n are multiple of 1? n
// // how many x <= n are multiple of 2? approximately n/2
// // how many x <= n are multiple of 3? approximately n/3
// // ...
// // how many x <= n are multiple of n? 1

// // check the existience of certain number O(N)
// // iterate over all multiples O(m*log(m))

// O(n + m*log(m))


// // I check if there is 7 or not in my array
// // if there is 7, then 7, 14, 21, 28 can all be replaced by 7 
// // to[i] = i can be replaced to a number as small as to[i]


// sz = 1e5

// 1 2 3 4 5 6 7 ... 100000  

// 1 2 3 4 5 6 7...            sz
// 2 4 6 8 ...                 sz/2 (approximately)

// 4 8 12 16 ....              sz/4 (approximately)
// ...



// some number x -> how small can it be? to[x] 


template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
using ll = long long;
using vi = vector<ll>;
const int sz = 1e5+1;
bool check[sz];
class Solution {
public:
    long long minArraySum(vector<int>& a) {
        int n = a.size();
        memset(check, 0, sizeof(check));
        for (auto x : a) check[x] = 1;
        // vi min_possible(sz,sz);
        unordered_map<ll,ll> min_possible;
        for (int i=1; i<sz; i++) min_possible[i] = i;
        for (int i=1; i<sz; i++) {
            if (!check[i]) continue;
            for (int j=i; j<sz; j+=i) chmin(min_possible[j],i);
        }
        ll ans = 0;
        for (auto x : a) ans += min_possible[x];
        return ans;
    }
};


// how do I know certain complexity algo passes or not

// competitive programming setting, 1e8 number of operations is generally allowed.
// consersavatively, 5e7 is safe. 
// if N is 1e5, then what is N*log(N)?
// 1e6 ~ 2^20
// 1000 ~ 1024 = 2^10 
// 1e5 < 1e6
// log(N) < log(1e6) < 20
// N * log(N) < N * 20 = 2e6