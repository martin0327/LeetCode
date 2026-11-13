
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
    asort(a);
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

const ll inf = 2e18;


class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        int n = s.size();
        s = s.substr(1,n-2);
        n = s.size();
        vector<vs> a;
        for (int i=1; i<n; i++) {
            auto t = s.substr(0,i);
            auto u = s.substr(i,n-i);
            a.push_back({t,u});
        }
        auto g = [&] (string s) {
            bool has_dot = false;
            int n = s.size(), idx = -1;
            for (int i=0; i<n; i++) {
                if (s[i] == '.') {
                    idx = i;
                    break;
                }
            }
            if (idx == -1) {
                return s[0] != '0' || n == 1;
            }
            else {
                bool ret = true;
                if (idx == 0 || idx == n-1) return false;
                if (s[0] == '0') {
                    ret &= idx == 1;
                }
                if (s[n-1] == '0') ret = false;
                return ret;
            }
        };
        auto f = [&] (string s) {
            int n = s.size();
            vs ret;
            if (g(s)) ret.push_back(s);
            for (int i=0; i<n; i++) {
                auto t = s;
                t.insert(t.begin()+i,'.');
                if (g(t)) ret.push_back(t);
            }
            return ret;
        };
        vs ans;
        for (auto &tu : a) {
            auto t = tu[0], u = tu[1];
            auto b1 = f(t);
            auto b2 = f(u);
            // debug(t,u);
            // debug(b1);
            // debug(b2);
            for (auto t : b1) {
                for (auto u : b2) {
                    string s = "(";
                    s += t;
                    s += ", ";
                    s += u;
                    s += ')';
                    ans.push_back(s);
                }
            }
        }
        return ans;
    }
};
