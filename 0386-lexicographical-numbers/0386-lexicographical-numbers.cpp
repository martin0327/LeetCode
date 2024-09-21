class Solution {
public:
    vector<int> lexicalOrder(int z) {
        string s = to_string(z);
        int n = s.size();
        vector<int> ans;
        string t;
        function<void(int)> f = [&] (int i) {
            if (i == n) {
                return;
            }
            for (int j=0; j<=9; j++) {
                if (j == 0 && t.empty()) continue;
                t += '0' + j;
                int x = stoi(t);
                if (x <= z) ans.push_back(x);
                f(i+1);
                t.pop_back();
            }
        };
        f(0);
        return ans;
    }
};
