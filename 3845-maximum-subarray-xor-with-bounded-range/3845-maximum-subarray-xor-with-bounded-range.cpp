template<typename T>
using min_pq = priority_queue<T, vector<T>, greater<T>>;
template<typename T>
using max_pq = priority_queue<T>;

using vi = vector<int>;
class Trie {
    public:

    Trie* ch[2];
    int cnt[2];
    int sz = 32;

    Trie() {
        for (int i=0; i<2; i++) {
            this->ch[i] = nullptr;
            this->cnt[i] = 0;
        }
    }

    void insert(int x) {
        Trie* node = this;

        for (int i=sz-1; i>=0; i--) {
            int idx = (x>>i&1);
            if (node->ch[idx] == nullptr) node->ch[idx] = new Trie();
            node->cnt[idx]++;
            node = node->ch[idx];
        }
    }

    int get_mx(int x) {
        Trie* node = this;
        int ret = 0;
        for (int i=sz-1; i>=0; i--) {
            int idx = (x>>i&1);
            if ((node->cnt[1^idx]) > 0) {
                node = node->ch[1^idx];
                ret += (1<<i);
            }
            else {
                assert((node->cnt[idx]) > 0);
                node = node->ch[idx];
            }
        }
        return ret;
    }

    void erase(int x) {
        Trie* node = this;
        for (int i=sz-1; i>=0; i--) {
            int idx = (x>>i&1);
            node->cnt[idx]--;
            node = node->ch[idx];
        }
    }
};

const int sz = 4e4 + 5;
int cnt[sz], pre[sz];

void validate(min_pq<int> &pq) {
    while (!pq.empty()) {
        auto x = pq.top();
        if (cnt[x] > 0) break;
        else pq.pop();
    }
}

void validate(max_pq<int> &pq) {
    while (!pq.empty()) {
        auto x = pq.top();
        if (cnt[x] > 0) break;
        else pq.pop();
    }
}

class Solution {
public:
    int maxXor(vector<int>& a, int k) {
        memset(cnt, 0 , sizeof(cnt));
        memset(pre, 0 , sizeof(pre));
        
        int n = a.size(), ans = 0;
        for (int i=1; i<=n; i++) {
            pre[i] = pre[i-1] ^ a[i-1];
        }
        
        min_pq<int> pq1;
        max_pq<int> pq2;
        auto tr = Trie();
        tr.insert(0);
        
        for (int j=0,i=1; i<=n; i++) {
            auto x = a[i-1];
            cnt[x]++;
            pq2.push(x);
            pq1.push(x);
            tr.insert(pre[i]);
            while (pq2.size()) {
                validate(pq2);
                validate(pq1);
                auto mx = pq2.top();
                auto mn = pq1.top();
                if (mx - mn > k) {
                    cnt[a[j]]--;
                    tr.erase(pre[j++]);
                }
                else break;
            }
            ans = max(ans, tr.get_mx(pre[i]));
        }
        return ans;
    }
};