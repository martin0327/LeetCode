class Solution {
public:
    vector<int> constructRectangle(int x) {
        vector<int> ans;
        for (int i=1; i*i<=x; i++) {
            if (x % i == 0) {
                ans = {x/i,i};
            }
        }
        return ans;
    }
};