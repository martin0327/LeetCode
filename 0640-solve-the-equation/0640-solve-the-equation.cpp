vector<string> split_str(string s, const char delim = ' ') {
    vector<string> ret;
    stringstream ss(s);
    string t;
    while (getline(ss, t, delim)) {
        ret.push_back(t);
    }
    return ret;
}
using vi = vector<int>;
using vs = vector<string>;
class Solution {
public:
    string solveEquation(string eq) {
        auto lr = split_str(eq,'=');
        auto L = lr[0];
        auto R = lr[1];
        auto f = [&] (string s) {
            vs a;
            for (auto ch : s) {
                if (a.empty() || ch == '+' || ch == '-') a.push_back(string(1,ch));
                else a.back() += ch;
            }
            return a;
        };
        auto a = f(L);
        auto b = f(R);
        auto g = [&] (vs b) {
            vi a(2);
            for (auto s : b) {
                bool neg = false;
                if (s[0] == '-') neg = true;
                int sign = neg?-1:1;
                if (s[0] == '-' || s[0] == '+') {
                    s.erase(s.begin());
                }
                if (s.back() == 'x') {
                    s.pop_back();
                    if (s.size()) a[0] += stoi(s) * sign;
                    else a[0] += sign;
                }
                else a[1] += stoi(s) * sign;
            }
            return a;
        };
        auto A = g(a);
        auto B = g(b);
        int num = B[1] - A[1];
        int den = A[0] - B[0];
        if (den == 0) {
            if (num == 0) return "Infinite solutions";
            else return "No solution";
        }
        assert(num % den == 0);
        string ans = "x=" + to_string(num / den);
        return ans;
    }
};