class Solution {
public:
    bool isValid(string s) {
        string t = "({[)}]";
        unordered_map<char,int> mp;
        for (int i=0; i<t.size(); i++) mp[t[i]] = i;
        int n = s.size();
        stack<int> st;
        for (int i=0; i<n; i++) {
            int x = mp[s[i]];
            if (st.size() && x-st.top() == 3) st.pop();
            else st.push(x);
        }
        if (st.empty()) return true;
        else return false;
    }
};