/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

void debug(set<int> s) {
    for (auto x : s) {
        cout << x << " ";
    }   cout << endl;
}

TreeNode* f(set<int> &s) {
    map<int,TreeNode*> mp;
    for (auto x : s) mp[x] = new TreeNode();
    for (auto x : s) {
        if (s.count(2*x)) {
            mp[x]->left = mp[2*x];
            mp[x]->right = mp[2*x+1];
        }
    }
    return mp[1];
}

class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (!(n&1)) return {};        
        set<set<int>> ss = {{1}};
        for (int k=0; k<n/2; k++) {
            set<set<int>> ns;
            for (auto s : ss) {
                for (auto x : s) {
                    if (!s.count(2*x)) {
                        set<int> t = s;
                        t.insert(2*x);
                        t.insert(2*x+1);
                        if (!ns.count(t)) ns.insert(t);
                    }
                }
            }
            ss = ns;
        }        
        // for (auto s : ss) {
        //     debug(s);
        // }
        vector<TreeNode*> ret;
        for (auto s : ss) {
            ret.push_back(f(s));
        }
        return ret;
    }
};