vector<string> split_str(string s, const char delim = ' ') {
    vector<string> ret;
    stringstream ss(s);
    string t;
    while (getline(ss, t, delim)) {
        ret.push_back(t);
    }
    return ret;
}

class Solution {
public:
    string complexNumberMultiply(string s, string t) {
        auto a = split_str(s,'+');
        auto b = split_str(t,'+');
        a[1].pop_back();
        b[1].pop_back();
        auto x1 = stoi(a[0]), x2 = stoi(a[1]);
        auto y1 = stoi(b[0]), y2 = stoi(b[1]);
        int rl = x1*y1 - x2*y2;
        int im = x1*y2 + x2*y1;
        string ans = to_string(rl) + "+" + to_string(im) + "i";
        return ans;
    }
};