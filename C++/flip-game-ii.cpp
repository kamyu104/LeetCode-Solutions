// Time:  O(n + c^3 * 2^c * logc), n is length of string, c is count of "++"
// Space: O(c * 2^c)

// hash solution.
class Solution {
public:
    struct multiset_hash {
        std::size_t operator() (const multiset<int>& set) const {
            string set_string;
            for (const auto& i : set) {
                set_string.append(to_string(i) + " ");
            }
            return hash<string>()(set_string); 
        }
    };

    bool canWin(string s) {
        const int n = s.length();
        multiset<int> consecutives;
        for (int i = 0; i < n - 1; ++i) {  // O(n) time
            if (s[i] == '+') {
                int c = 1;
                for (; i < n - 1 && s[i + 1] == '+'; ++i, ++c);
                if (c >= 2) {
                    consecutives.emplace(c);
                }
            }
        }
        return canWinHelper(consecutives);
    }

private:
    bool canWinHelper(const multiset<int>& consecutives) {  // O(2^c) time
        if (!lookup_.count(consecutives)) {
            bool is_win = false;
            for (auto it = consecutives.cbegin(); !is_win && it != consecutives.cend(); ++it) {  // O(c) time
                const int c = *it;
                multiset<int> next_consecutives(consecutives);
                next_consecutives.erase(next_consecutives.find(c));
                for (int i = 0; !is_win && i < c - 1; ++i) {  // O(clogc) time
                    if (i >= 2) {
                        next_consecutives.emplace(i);
                    }
                    if (c - 2 - i >= 2) {
                        next_consecutives.emplace(c - 2 - i);
                    }
                    is_win = !canWinHelper(next_consecutives);
                    if (i >= 2) {
                        next_consecutives.erase(next_consecutives.find(i));
                    }
                    if (c - 2 - i >= 2) {
                        next_consecutives.erase(next_consecutives.find(c - 2 - i));
                    }
                    lookup_[consecutives] = is_win;  // O(c) time
                }
            }
        }
        return lookup_[consecutives];
    }
    unordered_map<multiset<int>, bool, multiset_hash> lookup_;
};


// Time:  O(n + c * n * 2^c), try all the possible game strings,
//                            and each string would have c choices to become the next string 
// Space: O(n * 2^c), keep all the possible game strings
// hash solution.
class Solution2 {
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
class Solution3 {
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
