class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& a) {
      vector<string> codes = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
      set<string> s;
      for (auto x : a) {
        string t;
        for (auto c : x) {
          t += codes[c - 'a'];
        }
        s.insert(t);
      }
      return s.size();
    }
};