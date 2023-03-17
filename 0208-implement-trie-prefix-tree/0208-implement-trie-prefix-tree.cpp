class Trie {
public:
    bool leaf;
    Trie* children[26];
    Trie() {
        this->leaf = false;
        for (int i=0; i<26; i++) {
            this->children[i] = nullptr;
        }
    }
    
    void insert(string s) {
        Trie* node = this;

        for (int i=0; i<(int)s.size(); i++) {
              int idx = s[i] - 'a';
              if (node->children[idx] == nullptr) node->children[idx] = new Trie();
              node = node->children[idx];
        }
        node->leaf = true;
    }
    
    bool search(string key) {
        Trie* node = this;
        for (int i = 0; i<(int)key.size(); i++) {
              int idx = key[i] - 'a';
              if (!node->children[idx]) return false;
              node = node->children[idx];
        }
        return (node->leaf);
    }
    
    bool startsWith(string prefix) {
        Trie* node = this;
        for (int i=0; i<(int)prefix.size(); i++) {
            int idx = prefix[i] - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */