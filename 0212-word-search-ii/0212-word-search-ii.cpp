using vi = vector<int>;
using vvi = vector<vi>;

class Trie {
  public:

  string res;
  Trie* children[26];

  Trie() {
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
    node->res = s;
  }
};

class Solution {
public:

  int n,m;
  vector<vector<char>> a;
  vector<string> ans;
  vvi check;
  vi dr = {0,-1,0,1};
  vi dc = {1,0,-1,0};

  void f(int r, int c, Trie *node) {
    int idx = a[r][c] - 'a';
    if (!node->children[idx]) return;
    node = node->children[idx];
    check[r][c] = 1;
    if (node->res != "") {
      ans.push_back(node->res);
      node->res = "";
    }
    for (int d=0; d<4; d++) {
      int nr = r + dr[d];
      int nc = c + dc[d];
      if (nr < 0 || nr >= n) continue;
      if (nc < 0 || nc >= m) continue;
      if (check[nr][nc]) continue;
      f(nr,nc,node);
    }
    check[r][c] = 0;
  }

  vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

    a = board;
    n = a.size();
    m = a[0].size();
    check = vvi(n, vi(m));

    Trie trie = Trie();
    for (auto s : words) trie.insert(s);

    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        f(i,j,&trie);
      }
    }  
    
    return ans;
  }
};  