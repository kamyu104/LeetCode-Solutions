// Time:  O(n^(c+1)), n is length of string, c is count of "++"
// Space: O(c), recursion would be called at most c in depth.

class Solution {
public:
    bool canWin(string s) {
          int n = s.length();
          bool other_win = true; 
          for (int i = 0; other_win && i < n - 1; ++i) {  // O(n) time
              if (s[i] == '+') {
                  for (; other_win && i < n - 1 && s[i + 1] == '+'; ++i) {  // O(c) time
                      s[i] = s[i + 1] = '-';
                      other_win = canWin(s);  // F(n, c) = n * F(n, c - 1) = ... = n^c * F(n, 0) = n^(c+1)
                      s[i] = s[i + 1] = '+';
                  }
              }
          }
          return !other_win;  
    }
};
