using pnn = pair<Node*,Node*>;
class Solution {
public:
    Node* flatten(Node* head) {
        function<pnn(Node*)> f = [&] (Node* u) {
            pnn ret;
            if (!u) return ret;
            auto nb = u->next;
            if (u->child) {
                auto v = u->child;
                u->child = nullptr;
                auto [l,r] = f(v);
                u->next = l;
                l->prev = u;

                if (r && nb) {
                    r->next = nb;
                    nb->prev = r;
                }
                else if (r) nb = r;
            }
            ret.first = u;
            if (nb) ret.second = f(nb).second;
            else ret.second = u;
            
            return ret;
        };
        auto [l,r] = f(head);
        return l;
    }
};