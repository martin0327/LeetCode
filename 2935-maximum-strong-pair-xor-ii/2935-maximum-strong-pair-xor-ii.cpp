using vi = vector<int>;
const int lim = 20;

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
        for (int i=lim-1; i>=0; i--) {
            int idx = x>>i&1;
            if (!node->ch[idx]) node->ch[idx] = new Trie();
            node = node->ch[idx];
        }
    }

    int search(int x) {
        Trie* node = this;
        int ret = 0;
        for (int i=lim-1; i>=0; i--) {
            int idx = (x>>i&1)^1;
            if (node->ch[idx]) {
                ret += (1<<i);
                node = node->ch[idx];
            } 
            else if (node->ch[idx^1]) node = node->ch[idx^1];
            else return 0;
        }
        return ret;
    }
    
    void remove(int x) {
        Trie* node = this;
        remove(node, x);
    }
    
  private:
    
    bool remove(Trie* node, int x, int dep = 0) {
        if (dep == lim) return true;
        int idx = (x>>(lim-dep-1)&1);
        if (node->ch[idx]) {
            if (remove(node->ch[idx],x,dep+1)) node->ch[idx] = nullptr;
            if (!node->ch[0] && !node->ch[1]) return true;
            else return false;
        }
        else return false;
    }
    
};



class Solution {
public:
    int maximumStrongPairXor(vector<int>& a) {
        int n = a.size();
        sort(a.rbegin(), a.rend());
        Trie *t = new Trie();
        int ans = 0;
        for (int i=0, j=0; j<n; j++) {
            while (a[i]-a[j] > a[j]) t->remove(a[i++]);
            t->insert(a[j]);
            ans = max(ans, t->search(a[j]));
        }
        return ans;
    }
};