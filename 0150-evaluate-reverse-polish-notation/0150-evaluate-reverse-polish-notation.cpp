using ll = long long;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<ll> a;
        set<string> ss = {"+", "-", "*", "/"};
        for (auto s : tokens) {
            if (ss.count(s)) {
                ll y = a.back();
                a.pop_back();
                ll x = a.back();
                a.pop_back();
                if (s == "+") a.push_back(x+y);
                if (s == "-") a.push_back(x-y);
                if (s == "*") a.push_back(x*y);
                if (s == "/") a.push_back(x/y);
            }
            else a.push_back(stoll(s));
        }
        return a[0];
    }
};