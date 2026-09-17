template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T>
void asort(vector<T> &a) {sort(a.begin(), a.end());}
template<typename T>
void dsort(vector<T> &a) {sort(a.rbegin(), a.rend());}

using ll = long long;
using vi = vector<ll>;
using vs = vector<string>;
using vvs = vector<vs>;
vvs b;
vi odd,even;
const int sz = 11;
class Solution {
public:
    long long minOperations(vector<int>& aa) {
        vi a(aa.begin(), aa.end());
        int n = a.size();
        if (b.empty()) {
            b.assign(sz, vs());
            for (int i=0; i<10; i++) {
                b[1].push_back(to_string(i));
                b[2].push_back(to_string(i) + to_string(i));
            }
            for (int i=3; i<sz; i++) {
                for (auto &s : b[i-2]) {
                    for (int j=0; j<10; j++) {
                        b[i].push_back(to_string(j) + s + to_string(j));
                    }
                }
            }
            for (int i=1; i<sz; i++) {
                for (auto &s : b[i]) {
                    if (s.front() == '0') continue;
                    auto x = stoll(s);
                    if (x&1) odd.push_back(x);
                    else even.push_back(x);
                }
            }
            asort(odd);
            asort(even);
        }
        ll ans = 0;
        for (auto x : a) {
            auto &v = (x&1)?odd:even;
            auto it = lower_bound(v.begin(), v.end(), x);
            ll d = 2e9;
            if (it != v.end()) {
                chmin(d, abs(x-*it)/2);
            }
            if (it != v.begin()) {
                chmin(d, abs(x-*prev(it))/2);
            }
            ans += d;
        }
        return ans;
    }
};