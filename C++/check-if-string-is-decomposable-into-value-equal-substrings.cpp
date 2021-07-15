// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool isDecomposable(string s) {
        if (size(s) % 3 != 2) {
            return false;
        }
        int left;
        for (left = 0; left < size(s); left += 3) {
            if (std::adjacent_find(cbegin(s) + left, cbegin(s) + min(left + 3, int(size(s))),
                                   std::not_equal_to<>()) != cbegin(s) + min(left + 3, int(size(s)))) {
                break;
            }
        }
        int right;
        for (right = size(s) - 1; right >= left + 1  ; right -= 3) {
            if (std::adjacent_find(cbegin(s) + max(right - 2, left), cbegin(s) + right + 1,
                                   std::not_equal_to<>()) != cbegin(s) + right + 1) {
                break;
            }
        }
        return (right + 3) - left == 1;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    bool isDecomposable(string s) {
        bool found = false;
        for (int i = 0, l; i < size(s); i += l) {
            l = 1;
            for (int j = i + 1; j < min(i + 3, int(size(s))); ++j, ++l) {
                if (s[j] != s[i]) {
                    break;
                }
            }
            if (l < 2) {
                return false;
            }
            if (l == 2) {
                if (found) {
                    return false;
                }
                found = true;
            }
        }
        return found;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution3 {
public:
    bool isDecomposable(string s) {
        bool found = false;
        for (int i = 0, l = 0; i < size(s); ++i) {
            if (!l || s[i] != s[i - 1]) {
                if (l) {
                    return false;
                }
                l = 1;
                continue;
            }
            ++l;
            if (l == 2) {
                if (i == size(s) - 1 || s[i] != s[i + 1]) {
                    if (found) {
                        return false;
                    }
                    found = true;
                    l = 0;
                }
            } else if (l == 3) {
                l = 0;
            }
        }
        return found;
    }
};
