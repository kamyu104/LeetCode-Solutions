// Time:  O(n + c * n * 2^c), try all the possible game strings,
//                            and each string would have c choices to become the next string 
// Space: O(n * 2^c), keep all the possible game strings

// hash solution.
class Solution {
public:
    bool canWin(string s) {
        if (!lookup_.count(s)) {
            const int n = s.length();
            bool is_win = false; 
            for (int i = 0; !is_win && i < n - 1; ++i) {
                if (s[i] == '+') {
                    for (; !is_win && i < n - 1 && s[i + 1] == '+'; ++i) {
                        s[i] = s[i + 1] = '-';
                        is_win = !canWin(s); 
                        s[i] = s[i + 1] = '+';
                        lookup_[s] = is_win;
                    }
                }
            }
        }
        return lookup_[s];  
    }
private:
    unordered_map<string, bool> lookup_;
};


// Time:  O(n * c!), n is length of string, c is count of "++"
// Space: O(c), recursion would be called at most c in depth.
//              Besides, no extra space in each depth for the modified string.
class Solution2 {
public:
    bool canWin(string s) {
        const int n = s.length();
        bool is_win = false; 
        for (int i = 0; !is_win && i < n - 1; ++i) {  // O(n) time
            if (s[i] == '+') {
                for (; !is_win && i < n - 1 && s[i + 1] == '+'; ++i) {  // O(c) time
                    s[i] = s[i + 1] = '-';
                    // t(n, c) = c * t(n, c - 1) + n = ... = c! * t(n, 0) + n * c! * (1/0! + 1/1! + ... 1/c!)
                    // = n * c! + n * c! * O(e) = O(n * c!)
                    is_win = !canWin(s); 
                     s[i] = s[i + 1] = '+';
                }
            }
        }
        return is_win;  
    }
};
