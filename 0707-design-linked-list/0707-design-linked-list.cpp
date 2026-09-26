struct LL {
    int val;
    LL* nxt = nullptr;
    LL* prv = nullptr;
    LL () {}
    LL (int val) {
        this->val = val;
    }
};

class MyLinkedList {
public:
    LL* head;
    int sz;
    MyLinkedList() {
        head = nullptr;
        sz = 0;
    }
    
    int get(int idx) {
        if (idx >= sz) return -1;
        auto it = head;
        int t = idx;
        while (t--) it = it->nxt;
        return it->val;
    }
    
    void addAtHead(int val) {
        if (!head) {
            head = new LL(val);
            sz++;
            return;
        }
        auto nh = new LL(val);
        nh->nxt = head;
        head->prv = nh;
        head = nh;
        sz++;
    }
    
    void addAtTail(int val) {
        if (!head) {
            head = new LL(val);
            sz++;
            return;
        }
        auto tail = new LL(val);
        auto it = head;
        int t = sz-1;
        while (t--) it = it->nxt;
        it->nxt = tail;
        tail->prv = it;
        sz++;
    }
    
    void addAtIndex(int idx, int val) {
        if (idx == 0) {
            addAtHead(val);
            return;
        }
        if (idx == sz) {
            addAtTail(val);
            return;
        }
        if (idx > sz) {
            return; 
        }
        auto it = head;
        int t = idx-1;
        while (t--) it = it->nxt;
        auto L = it;
        auto R = it->nxt;
        auto node = new LL(val);
        node->prv = L;
        node->nxt = R;
        L->nxt = node;
        R->prv = node;
        sz++;
    }
    
    void deleteAtIndex(int idx) {
        if (0 <= idx && idx < sz) {
            if (idx == 0) {
                auto it = head;
                if (head->nxt) {
                    head = it->nxt;
                    head->prv = nullptr;
                    delete it;
                    sz--;
                }
                else {
                    auto t = head;
                    delete t;
                    head = nullptr;
                    sz--;
                }
            }
            else if (idx == sz-1) {
                auto it = head;
                int t = idx;
                while (t--) it = it->nxt;
                auto nt = it->prv;
                nt->nxt = nullptr;
                delete it;
                sz--;
            }
            else {
                auto it = head;
                int t = idx;
                while (t--) it = it->nxt;
                auto L = it->prv;
                auto R = it->nxt;
                L->nxt = R;
                R->prv = L;
                delete it;
                sz--;
            }
        }
    }
};