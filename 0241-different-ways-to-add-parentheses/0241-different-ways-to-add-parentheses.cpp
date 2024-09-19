vector<string> split_str(string s, const char delim = ' ') {
    vector<string> ret;
    stringstream ss(s);
    string t;
    while (getline(ss, t, delim)) {
        ret.push_back(t);
    }
    return ret;
}

using vs = vector<string>;

class Solution {
public:
    vector<int> diffWaysToCompute(string ex) {
        string ops = "+-*";
        set<char> sc(ops.begin(),ops.end());
        vector<string> a;
        for (auto c : ex) {
            if (a.empty() || sc.count(c) || sc.count(a.back()[0])) a.push_back(string(1,c));
            else a.back() += c;
        }
        set<string> ss;
        function<void(vs)> f = [&] (vs b) {
            int n = b.size();
            if (n==1) {
                ss.insert(b.front());
                return;
            }
            
            for (int i=0; i<n; i++) {
                char c = b[i].back();
                if (sc.count(c)) {
                    string l = "(" + b[i-1];
                    string r = b[i+1] + ")";
                    auto d = b;
                    for (int j=i+1; j>=i-1; j--) {
                        d.erase(d.begin()+j);
                    }
                    d.insert(d.begin()+(i-1), l + string(1,c) + r);
                    f(d);
                }
            }
        };
        f(a);
        vector<int> ans;
        auto g = [&] (string s) {
            string t;
            for (auto c : s) {
                if (c == ')') {
                    string u;
                    while (t.size()) {
                        if (t.back() == '(') {
                            t.pop_back();
                            break;
                        }
                        else {
                            u += t.back();
                            t.pop_back();
                        }
                    }
                    reverse(u.begin(), u.end());
                    int idx = -1, m = u.size();
                    for (int j=1; j<m; j++) {
                        auto c = u[j];
                        if (sc.count(c)) {
                            idx = j;
                            break;
                        }
                    }
                    int x = stoi(u.substr(0,idx)), y = stoi(u.substr(idx+1,m-(idx+1)));
                    int z = -1;
                    char op = u[idx];
                    if (op=='+') z = x + y;
                    if (op=='-') z = x - y;
                    if (op=='*') z = x * y;
                    t += to_string(z);
                }
                else t += c;
            }
            return stoi(t);
        };
        for (auto s : ss) ans.push_back(g(s));
        
        return ans;
    }
};