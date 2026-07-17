
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
    NestedInteger deserialize(string s) {
        int n = s.size();
        map<int,pii> br;
        map<int,vi> dl;
        vi st;
        for (int i=0; i<n; i++) {
            auto ch = s[i];
            if (ch == '[') {
                st.push_back(i);
            }
            else if (ch == ']') {
                br[st.back()] = {st.size(),i};
                st.pop_back();
            }
            else if (ch == ',') {
                dl[st.size()].push_back(i);
            }
        }
        function<NestedInteger(int,int)> f = [&](int l, int r) {
            if (s[l] == '[') {
                assert(s[r] == ']');
                auto ret = NestedInteger();
                if (l+1 == r) return ret;
                auto [lv,_r] = br[l];
                vi b;
                auto &idx = dl[lv];
                auto it = lower_bound(idx.begin(), idx.end(), l);
                while (it != idx.end()) {
                    if (*it < r) {
                        b.push_back(*it);
                    }
                    it++;
                }
                int pr = l;
                for (auto i : b) {
                    ret.add(f(pr+1,i-1));
                    pr = i;
                }
                ret.add(f(pr+1,r-1));
                return ret;
            }
            else {
                string t;
                for (int i=l; i<=r; i++) {
                    // int x = s[i] - '0';
                    t += s[i];
                }
                auto x = stoi(t);
                auto ret = NestedInteger(x);
                return ret;
            }
            auto ret = NestedInteger();
            return ret;
        };
        // debug(br);
        // debug(dl);
        auto ret = f(0,n-1);
        return ret;
    }
};