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
        auto tl = intersect(a->topLeft,b->topLeft);
        auto tr = intersect(a->topRight,b->topRight);
        auto bl = intersect(a->bottomLeft,b->bottomLeft);
        auto br = intersect(a->bottomRight,b->bottomRight);
        vector<Node*> c = {tl,tr,bl,br};
        if (all_of(c.begin(), c.end(), [&] (Node* v) { return v->isLeaf; })) {
            if (all_of(c.begin(), c.end(), [&] (Node* v) { return v->val == c.front()->val; })) {
                auto ret = new Node(tl->val,true);
                return ret;
            }
        }
        auto ret = new Node(false,false,tl,tr,bl,br);
        return ret;
    }
};