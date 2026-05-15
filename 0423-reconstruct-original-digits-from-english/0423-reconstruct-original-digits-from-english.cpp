
template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

template<typename T1, typename T2>
void chmax(T1 &x, T2 y) { if (x < y) x = y; }
template<typename T1, typename T2>
void chmin(T1 &x, T2 y) { if (x > y) x = y; }
template<typename T>
void asort(vector<T> &a) {sort(a.begin(), a.end());}
template<typename T>
void dsort(vector<T> &a) {sort(a.rbegin(), a.rend());}
template<typename T>
void reverse(vector<T> &a) {reverse(a.begin(), a.end());}

template<typename T>
vector<T> get_unique(vector<T> a) {
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    return a;
}

using ll = long long;
using vi = vector<ll>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;
using vs = vector<string>;

class Solution {
public:
    string originalDigits(string s) {
        vs b = {
            "zero",
            "six",
            "two",
            "four",
            "eight",
            "five",
            "three",
            "seven",
            "one",
            "nine"
        };
        vi a = {0,6,2,4,8,5,3,7,1,9};
        map<char,int> mp;
        for (auto ch : s) mp[ch]++;
        vi cnt(10);
        for (int i=0; i<10; i++) {
            auto t = b[i];
            map<char,int> mul;
            for (auto ch : t) mul[ch]++;
            int min_cnt = 2e9;
            for (auto [key,val] : mul) {
                int tg = mp[key] / val;
                chmin(min_cnt, tg);
            }
            for (auto [key,val] : mul) {
                mp[key] -= val * min_cnt;
            }
            cnt[a[i]] += min_cnt;
        }
        string ans;
        for (int i=0; i<10; i++) {
            int t = cnt[i];
            char ch = '0' + i;
            while (t--) ans += ch;
        }
        return ans;
    }
};