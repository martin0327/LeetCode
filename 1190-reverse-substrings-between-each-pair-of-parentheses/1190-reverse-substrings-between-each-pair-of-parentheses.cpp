class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.size();
        vector<int> cp(n, -1);
        stack<int> st;
        for (int i=0; i<n; i++) {
            if (s[i] == '(') st.push(i);
            if (s[i] == ')') {
                int j = st.top();
                cp[i] = j, cp[j] = i;
                st.pop();
            }
        }
        string ans;
        set<char> paren;
        {
            string s = "()";
            paren = set<char>(s.begin(), s.end());
        }

        function<void(int,int,bool)> f = [&] (int l, int r, int d) {
            if (l > r) return;
            if (d == 1) {
                if (paren.count(s[l])) {
                    f(l+1,cp[l]-1,d^1);
                    f(cp[l]+1,r,d);
                }
                else {
                    ans += s[l];
                    f(l+1,r,d);
                }
            }
            else {
                if (paren.count(s[r])) {
                    f(cp[r]+1,r-1,d^1);
                    f(l,cp[r]-1,d);
                }
                else {
                    ans += s[r];
                    f(l,r-1,d);
                }
            }
        };

        f(0,n-1,1);

        return ans;
    }
};