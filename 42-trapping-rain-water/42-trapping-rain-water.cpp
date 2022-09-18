class Solution {
public:
  int trap(vector<int>& a) {
    using ll = long long;
    int n = a.size();
    stack<int> st;
    ll ans = 0;
    for (int i=0; i<n; i++) {
      while (st.size() && a[st.top()] <= a[i]) {
        int j = st.top();
        st.pop();
        if (st.empty()) break;
        int h = min(a[st.top()], a[i]) - a[j];
        int w = i - st.top() - 1;
        ans += h*w;
      }
      st.push(i);
    }
    return ans;
  }
};