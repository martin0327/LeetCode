

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


class Trie {
    public:

    Trie* ch[2];
    ll cnt[2];
    ll sz = 32;

    Trie() {
        for (int i=0; i<2; i++) {
            this->ch[i] = nullptr;
            this->cnt[i] = 0;
        }
    }

    void insert(ll x) {
        Trie* node = this;

        for (int i=sz-1; i>=0; i--) {
            int idx = (x>>i&1);
            if (node->ch[idx] == nullptr) node->ch[idx] = new Trie();
            node->cnt[idx]++;
            node = node->ch[idx];
        }
    }

    ll get_mx(ll x) {
        Trie* node = this;
        ll ret = 0;
        for (int i=sz-1; i>=0; i--) {
            int idx = (x>>i&1);
            if ((node->cnt[1^idx]) > 0) {
                node = node->ch[1^idx];
                ret += (1ll<<i);
            }
            else {
                assert((node->cnt[idx]) > 0);
                node = node->ch[idx];
            }
        }
        return ret;
    }

    void erase(ll x) {
        Trie* node = this;
        for (int i=sz-1; i>=0; i--) {
            int idx = (x>>i&1);
            node->cnt[idx]--;
            node = node->ch[idx];
        }
    }
};

class Solution {
public:
    int maxXor(vector<int>& aa, int kk) {
        vi a(aa.begin(), aa.end());
        ll n = a.size(), k = kk;;
        vi pre(n+1);
        for (int i=1; i<=n; i++) {
            pre[i] = pre[i-1] ^ a[i-1];
        }
        map<ll,ll> mp;
        auto tr = Trie();
        tr.insert(0);
        ll ans = 0;
        for (int j=0,i=1; i<=n; i++) {
            mp[a[i-1]]++;
            tr.insert(pre[i]);
            while (mp.size()) {
                auto mx = mp.rbegin()->first;
                auto mn = mp.begin()->first;
                if (mx - mn > k) {
                    if (--mp[a[j]] == 0) mp.erase(a[j]);
                    tr.erase(pre[j++]);
                }
                else break;
            }
            if (i > j) chmax(ans, tr.get_mx(pre[i]));
        }
        return ans;
    }
};