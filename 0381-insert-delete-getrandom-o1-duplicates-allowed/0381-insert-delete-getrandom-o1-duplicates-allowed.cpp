#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Define the ordered multiset using a pair
typedef tree<
    pair<int, int>,          // Pair of <Value, Unique_ID>
    null_type,               // Mapped type (null_type for sets)
    less<pair<int, int>>,    // Comparator
    rb_tree_tag,             // Red-Black tree
    tree_order_statistics_node_update // Enables order statistics
> ordered_multiset;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

class RandomizedCollection {
public:
    ordered_multiset s;
    int idx;
    RandomizedCollection() {
        idx = 0;
    }
    
    bool insert(int val) {
        auto it = s.lower_bound({val, -1}); 
        bool ret = (it == s.end() || it->first != val);
        s.insert({val,idx++});
        return ret;
    }
    
    bool remove(int val) {
        auto it = s.lower_bound({val, -1}); 
        if (it != s.end() && it->first == val) {
            s.erase(it); 
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int n = s.size();
        uniform_int_distribution<int> dist(0, n - 1);
        int k = dist(rng);
        return s.find_by_order(k)->first;
    }
};