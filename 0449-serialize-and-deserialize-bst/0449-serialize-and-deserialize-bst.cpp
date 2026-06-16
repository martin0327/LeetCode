using vs = vector<string>;
vs g(string s) {
    vector<string> ret;
    string t = "!@#";
    set<char> sc(t.begin(), t.end());
    for (auto c : s) {
        if (ret.empty()) ret.push_back(string(1,c));
        else {
            if (sc.count(ret.back().back()) || sc.count(c)) ret.push_back(string(1,c));
            else ret.back() += c;
        }
    }
    return ret;
}

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        if (!root) return s;
        function<void(TreeNode*)> f = [&] (TreeNode* v) {
            s += to_string(v->val);
            if (v->left) {
                s += '!';
                f(v->left);
            }
            if (v->right) {
                s += '@';
                f(v->right);
            }
            s += '#';
            return;
        };
        f(root);
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        if (s.empty()) return nullptr;
        auto a = g(s);
        auto ret = new TreeNode();
        int n = a.size(), i = 0;
        function<void(TreeNode*)> f = [&] (TreeNode* v) {
            if (i >= n) return;
            
            if (a[i] == "!") {
                v->left = new TreeNode();
                i++;
                f(v->left);
                f(v);
            }
            else if (a[i] == "@") {
                v->right = new TreeNode();
                i++;
                f(v->right);
                f(v);
            }
            else if (a[i] == "#") {
                i++;
                return;
            }
            else {
                v->val = stoi(a[i]);
                i++;
                f(v);
            }
        };
        f(ret);
        return ret;
    }
};