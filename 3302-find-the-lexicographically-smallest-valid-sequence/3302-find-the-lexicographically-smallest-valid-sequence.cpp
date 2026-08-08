
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
using vi = vector<int>;
using vvi = vector<vi>;
using pii = pair<ll,ll>;
using vp = vector<pii>;
using vvp = vector<vp>;
using ti3 = tuple<ll,ll,ll>;
using vti3 = vector<ti3>;
using vs = vector<string>;

class Solution {
public:
    vector<int> validSequence(string s, string t) {
        int n = s.size(), m = t.size();
        int sz = 26;
        vvi idx(sz);
        for (int i=0; i<n; i++) {
            idx[s[i]-'a'].push_back(i);
        }
        vi b(m,-1);
        for (int i=m-1, cur=n; i>=0; i--) {
            auto &v = idx[t[i]-'a'];
            auto it = lower_bound(v.begin(), v.end(), cur);
            if (it == v.begin()) break;
            else {
                auto j = *prev(it);
                b[i] = cur = j;
            }
        }
        vi ans;
        for (int j=0, i=0; j<m; j++) {
            if (i < n && s[i] == t[j]) {
                ans.push_back(i++);
            }
            else if (j == m-1) {
                if (i < n) ans.push_back(i);
            }
            else if (b[j+1] > i) {
                ans.push_back(i++);
                j++;
                while (j < m) {
                    auto &v = idx[t[j]-'a'];
                    auto it = lower_bound(v.begin(), v.end(), i);
                    assert(it != v.end());
                    ans.push_back(*it);
                    i = ans.back() + 1;
                    j++;
                }
                break;
            }
            else {
                auto &v = idx[t[j]-'a'];
                auto it = lower_bound(v.begin(), v.end(), i);
                if (it == v.end()) {
                    break;
                }
                ans.push_back(*it);
                i = ans.back() + 1;
            }
        }
        if (ans.size() == m) return ans;
        ans.clear();
        return ans;
    }
};