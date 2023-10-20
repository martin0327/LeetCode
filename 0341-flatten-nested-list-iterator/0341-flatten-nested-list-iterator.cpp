/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> a;
    int idx = 0, n = 0;
    
    void f(vector<NestedInteger> &nl) {
        for (auto x : nl) {
            if (x.isInteger()) {
                a.push_back(x.getInteger());
            }
            else {
                f(x.getList());
            }
        }
        n = a.size();
    } 
    NestedIterator(vector<NestedInteger> &nl) {
        f(nl);
    }
    
    int next() {
        return a[idx++];
    }
    
    bool hasNext() {
        return idx < n;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */