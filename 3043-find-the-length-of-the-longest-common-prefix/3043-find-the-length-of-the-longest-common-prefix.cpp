class Trie {
    public:

    bool leaf;
    Trie* children[10];

    Trie() {
        this->leaf = false;
        for (int i=0; i<10; i++) {
            this->children[i] = nullptr;
        }
    }

    void insert(string s) {
        Trie* node = this;

        for (int i=0; i<(int)s.size(); i++) {
            int idx = s[i] - '0';
            if (node->children[idx] == nullptr) node->children[idx] = new Trie();
            node = node->children[idx];
        }
        node->leaf = true;
    }

    int search(string key) {
        Trie* node = this;
        int ret = 0;
        for (int i = 0; i <(int)key.size(); i++) {
            int idx = key[i] - '0';
            if (!node->children[idx]) return ret;
            node = node->children[idx];
            ret++;
        }
        return ret;
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& a, vector<int>& b) {
        auto tr = new Trie();
        for (auto x : a) {
            string s = to_string(x);
            tr->insert(s);
        }
        int ans = 0;
        for (auto x : b) {
            string s = to_string(x);
            ans = max(ans, tr->search(s));
        }
        return ans;
    }
};