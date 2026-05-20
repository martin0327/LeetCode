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

class Solution {
public:
    int maxXor(vector<int>& a, int k) {
        int n = a.size();
        vi pre(n+1);
        for (int i=1; i<=n; i++) {
            pre[i] = pre[i-1] ^ a[i-1];
        }
        map<int,int> mp;
        auto tr = Trie();
        tr.insert(0);
        int ans = 0;
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
            ans = max(ans, tr.get_mx(pre[i]));
        }
        return ans;
    }
};