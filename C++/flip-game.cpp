 // Time:  O(n^2)
 // Space: O(1), no extra space except that result requires at most O(n^2) space
 
 class Solution {
  public:
      vector<string> generatePossibleNextMoves(string s) {
          vector<string> res;
          int n = s.length();
          for (int i = 0; i < n - 1; ++i) {  // n times
              if (s[i] == '+') {
                  for (;i < n - 1 && s[i + 1] == '+'; ++i) {
                      s[i] = s[i + 1] = '-';
                      res.emplace_back(s);  // O(n) to copy a string
                      s[i] = s[i + 1] = '+';
                  }
              }
          }
          return res;
      }
  };
