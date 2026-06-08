using vi = vector<int>;
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vi a,b,c;
        for (auto x : nums) {
            if (x < pivot) a.push_back(x);
            if (x==pivot) b.push_back(x);
            if (x>pivot) c.push_back(x);
        }
        for (auto x : b) a.push_back(x);
        for (auto x : c) a.push_back(x);
        return a;
    }
};