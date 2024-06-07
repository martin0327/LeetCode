class Trie {
    public:

    bool leaf;
    Trie* ch[26];

    Trie() {
        this->leaf = false;
        for (int i=0; i<26; i++) {
            this->ch[i] = nullptr;
        }
    }
    
    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (ch[i]) delete ch[i];
        }
    }

    void insert(string s) {
        Trie* node = this;

        for (int i=0; i<(int)s.size(); i++) {
            int idx = s[i] - 'a';
            if (node->ch[idx] == nullptr) node->ch[idx] = new Trie();
            node = node->ch[idx];
        }
        node->leaf = true;
    }

    string search(string key) {
        Trie* node = this;
        for (int i = 0; i <(int)key.size(); i++) {
            int idx = key[i] - 'a';
            if (!node->ch[idx]) return key;
            node = node->ch[idx];
            if (node->leaf) {
                string ret = key.substr(0,i+1);
                return ret;
            }
        }
        return key;
    }
};

vector<string> split_str(string s, const char delim = ' ') {
    vector<string> ret;
    stringstream ss(s);
    string t;
    while (getline(ss, t, delim)) {
        ret.push_back(t);
    }
    return ret;
}

class Solution {
public:
    string replaceWords(vector<string>& dict, string st) {
        auto tr = new Trie();
        for (auto s : dict) tr->insert(s);
        auto a = split_str(st);
        string ans;
        for (auto s : a) {
            ans += tr->search(s) + ' ';
        }
        ans.pop_back();
        return ans;
    }
};