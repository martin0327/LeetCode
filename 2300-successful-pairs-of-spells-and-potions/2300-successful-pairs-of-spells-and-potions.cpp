class Solution {
public:
  vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {

    sort(potions.begin(), potions.end());
    vector<int> res(spells.size(), 0);
    int n = potions.size();
    for (int i = 0; i < spells.size(); ++i) {
    
      auto it = lower_bound(potions.begin(), potions.end(), spells[i], [&success](const int& lhs, const int& rhs) {
        return static_cast<long long>(lhs) * rhs < success;
      });

      res[i] = n - (it - potions.begin());
    }
    return res;
  }
};