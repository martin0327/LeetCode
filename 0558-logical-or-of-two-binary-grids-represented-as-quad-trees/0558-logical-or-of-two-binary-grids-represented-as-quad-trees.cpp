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

class Solution {
public:
    Node* intersect(Node* a, Node* b) {
        if (a->isLeaf) {
            if (a->val) {
                auto ret = new Node(true,true);
                return ret;
            }
            else return b;
        }
        if (b->isLeaf) {
            if (b->val) {
                auto ret = new Node(true,true);
                return ret;
            }
            else return a;
        }
        // cout << a->isLeaf << endl;
        // assert(a->topLeft);
        // assert(b->topLeft);
        // assert(a->topRight);
        // assert(b->topRight);
        // assert(a->bottomLeft);
        // assert(b->bottomLeft);
        // assert(a->bottomRight);
        // assert(b->bottomRight);
        auto tl = intersect(a->topLeft,b->topLeft);
        auto tr = intersect(a->topRight,b->topRight);
        auto bl = intersect(a->bottomLeft,b->bottomLeft);
        auto br = intersect(a->bottomRight,b->bottomRight);
        if (tl->isLeaf && tr->isLeaf && bl->isLeaf && br->isLeaf) {
            set<bool> t = {tl->val, tr->val, bl->val, br->val};
            if (t.size() == 1) {
                auto ret = new Node(tl->val,true);
                return ret;
            }
        }
        auto ret = new Node(false,false,tl,tr,bl,br);
        return ret;
    }
};