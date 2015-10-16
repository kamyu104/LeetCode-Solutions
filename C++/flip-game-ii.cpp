// Time:  O(n * c!), n is length of string, c is count of "++"
// Space: O(c), recursion would be called at most c in depth.
//              Besides, no extra space in each depth for the modified string.

class Solution {
public:
    bool canWin(string s) {
          int n = s.length();
          bool is_win = false; 
          for (int i = 0; !is_win && i < n - 1; ++i) {  // O(n) time
              if (s[i] == '+') {
                  for (; !is_win && i < n - 1 && s[i + 1] == '+'; ++i) {  // O(c) time
                      s[i] = s[i + 1] = '-';
                      // t(n, c) = c * t(n, c - 1) + n = ... = c! * t(n, 0) + n * c! (1 + 1/2! + ... 1/c!)
                      // = n * c! + n * c! * O(e) = O(n * c!)
                      is_win = !canWin(s); 
                      s[i] = s[i + 1] = '+';
                  }
              }
          }
          return is_win;  
    }
};
