class MagicDictionary {
public:
    set<string> ss;
    MagicDictionary() {
        
    }
    
    void buildDict(vector<string> d) {
        for (auto s : d) ss.insert(s);
    }
    
    bool search(string s) {
        int n = s.size(), sz = 26;
        for (int i=0; i<n; i++) {
            for (int j=0; j<sz; j++) {
                auto t = s;
                t[i] = 'a' + j;
                if (s == t) continue;
                if (ss.count(t)) return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */