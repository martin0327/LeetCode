using ll = long long;
using pii = pair<ll,ll>;
const ll inf = 1e9;
pii z;

class Trie {
    public:

    Trie* ch[26];
    pii val;

    Trie() {
        this->val = {inf,inf};
        for (int i=0; i<26; i++) {
            this->ch[i] = nullptr;
        }
    }
    
    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (ch[i]) delete ch[i];
        }
    }

    void insert(string s, pii x) {
        Trie* node = this;
        // debug(s,x);

        for (int i=0; i<(int)s.size(); i++) {
            int idx = s[i] - 'a';
            // debug(idx);
            if (node->ch[idx] == nullptr) node->ch[idx] = new Trie();
            node = node->ch[idx];
            node->val = min(node->val, x);
            // debug(node->val);
        }
    }

    pii search(string key) {
        // debug(key);
        Trie* node = this;
        pii ret = z; 
        for (int i = 0; i <(int)key.size(); i++) {
            // debug(i);
            int idx = key[i] - 'a';
            // debug(!node->ch[idx]);
            if (!node->ch[idx]) return ret;
            node = node->ch[idx];
            ret = node->val;
            // debug(node->val);
        }
        return ret;
    }
};

class Solution {
public:
    vector<int> stringIndices(vector<string>& wc, vector<string>& wq) {
        auto tr = new Trie();
        {
            vector<pii> t;
            for (int i=0; i<wc.size(); i++) {
                auto s = wc[i];
                t.push_back({s.size(),i});
            }
            z = *min_element(t.begin(), t.end());
        }
        for (int i=0; i<wc.size(); i++) {
            auto s = wc[i];
            reverse(s.begin(), s.end());
            pii x = {s.size(), i};
            tr->insert(s,x);
        }
        vector<int> ans;
        for (auto s : wq) {
            reverse(s.begin(), s.end());
            auto [sz,i] = tr->search(s);
            ans.push_back(i);
        }
        return ans;
    }
};