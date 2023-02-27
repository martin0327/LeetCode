/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
using vi = vector<int>;
using vvi = vector<vi>;

class Solution {
public:
  vvi a;
  int n;  
  
  Node* f(int r1, int r2, int c1, int c2) {
    if (r2-r1==1) {
      Node* ret = new Node(a[r1][c1], true);
      return ret;
    }
    int rm = (r1+r2)/2;
    int cm = (c1+c2)/2;
    vvi rr = {{r1,rm},{rm,r2}};
    vvi cc = {{c1,cm},{cm,c2}};
    vector<Node*> vv;
    for (auto r : rr) {
      for (auto c : cc) {
        vv.push_back(f(r[0],r[1],c[0],c[1]));
      }
    }
    bool leaf = true;
    int cnt = 0;
    for (auto v : vv) {
      if (!v->isLeaf) leaf = false;
      cnt += v->val;
    }
    leaf &= (cnt==0 || cnt==4);
    Node* ret = new Node();
    if (leaf) {
      ret->isLeaf = true;
      ret->val = (cnt==4);
    }
    else {
      ret->topLeft = vv[0];
      ret->topRight = vv[1];
      ret->bottomLeft = vv[2];
      ret->bottomRight = vv[3];
    }
    return ret;
  }
  Node* construct(vector<vector<int>>& grid) {
    a = grid;
    n = a.size();
    Node* ret = f(0,n,0,n);
    return ret;        
  }
};