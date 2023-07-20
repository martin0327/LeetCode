class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        vector<int> st;
        for (auto x : a) {
            bool push = true;
            while (st.size()) {
                int y = st.back();
                if (y > 0 && x < 0) {
                    if (abs(y) <= abs(x)) st.pop_back();
                    if (abs(y) >= abs(x)) {
                        push = false;
                        break;
                    }
                }
                else break;
            }
            if (push) st.push_back(x);
        }
        return st;
    }
}; 