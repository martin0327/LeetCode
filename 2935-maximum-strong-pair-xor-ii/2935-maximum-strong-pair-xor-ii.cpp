using vi = vector<int>;

class Trie {
    public:

    Trie* ch[2];

    Trie() {
        for (int i=0; i<2; i++) {
            this->ch[i] = nullptr;
        }
    }
    
    ~Trie() {
        for (int i = 0; i < 2; i++) {
            if (ch[i]) delete ch[i];
        }
    }

    void insert(int x) {
        Trie* node = this;
        vi a;
        for (int i=19; i>=0; i--) {
            a.push_back(x>>i&1);
        }
        for (int i=0; i<a.size(); i++) {
            int idx = a[i];
            if (!node->ch[idx]) node->ch[idx] = new Trie();
            node = node->ch[idx];
        }
    }

    int search(int x) {
        Trie* node = this;
        int ret = 0;
        vi a;
        for (int i=19; i>=0; i--) {
            a.push_back(x>>i&1);
        }
        for (int i=0; i<a.size(); i++) {
            int idx = a[i]^1;
            if (node->ch[idx]) {
                ret += (1<<(19-i));
                node = node->ch[idx];
            } 
            else if (node->ch[idx^1]) {
                node = node->ch[idx^1];
            }
            else return 0;
        }
        return ret;
    }
};

bool remove(Trie* node, int x, int dep) {
    if (dep == 20) {
        return true;
    }
    int idx = (x>>(19-dep)&1);
    if (node->ch[idx]) {
        if (remove(node->ch[idx],x,dep+1)) {
            node->ch[idx] = nullptr;
        }
        if (!node->ch[0] && !node->ch[1]) {
            return true;
        }
        else return false;
    }
    else return false;
}

class Solution {
public:
    int maximumStrongPairXor(vector<int>& a) {
        int n = a.size();
        sort(a.rbegin(), a.rend());
        Trie *t = new Trie();
        int ans = 0;
        set<int> ss;
        for (int i=0, j=0; j<n; j++) {
            while (a[i]-a[j] > a[j]) {
                remove(t,a[i++],0);
            }
            t->insert(a[j]);
            ans = max(ans, t->search(a[j]));
        }
        return ans;
    }
};