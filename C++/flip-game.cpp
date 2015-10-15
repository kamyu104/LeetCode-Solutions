 // Time:  O(n)
 // Space: O(1)
 
 class Solution {
  public:
      vector<string> generatePossibleNextMoves(string s) {
          vector<string> res;
          int n = s.length();
          for (int i = 0; i < n - 1; ++i) {
              if (s[i] == '+') {
                  for (;i < n - 1 && s[i + 1] == '+'; ++i) {
                      s[i] = s[i + 1] = '-';
                      res.emplace_back(s);
                      s[i] = s[i + 1] = '+';
                  }
              }
          }
          return res;
      }
  };
