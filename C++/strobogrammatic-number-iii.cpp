// Time:  O(5^n)
// Space: O(n)

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int count = countStrobogrammaticUntil(high, false) -
                    countStrobogrammaticUntil(low, false) +
                    isStrobogrammatic(low);
        return count >= 0 ? count : 0;
    }

    int countStrobogrammaticUntil(string num, bool canStartWith0) {
        int count = 0;
        if (num.length() == 1) {
            for (const auto& c : {'0', '1', '8'}) {
                if (num.front() >= c) {
                    ++count;
                }
            }
            return count;
        }
        
        for (const auto& kvp : lookup) {
            if (canStartWith0 || kvp.first != '0') { 
                if (num.front() > kvp.first) {
                    if (num.length() == 2) {  // num is like "21"
                        ++count;
                    } else {  // num is like "201"
                        count += countStrobogrammaticUntil(string(num.length() - 2, '9'), true);
                    }
                } else if (num.front() == kvp.first) {
                    if (num.length() == 2) {  // num is like 12".
                        count += num.back() >= kvp.second;
                    } else {
                        if (num.back() >= kvp.second) {  // num is like "102".
                            count += countStrobogrammaticUntil(getMid(num), true);
                        } else if (getMid(num) != string(num.length() - 2, '0')) {  // num is like "110".
                            count += countStrobogrammaticUntil(getMid(num), true);
                        }
                    }
                }
            }
        }

        if (!canStartWith0) { // Sum up each length.
            for (int i = num.length() - 1; i > 0; --i) {
                count += countStrobogrammaticByLength(i);
            }
        }

        return count;
    }

    string getMid(const string& num) {
        return num.substr(1, num.length() - 2);
    }

    int countStrobogrammaticByLength(int n) {
        switch (n) {
            case 1:
                return 3;
            case 2:
                return 4;
            case 3:
                return 4 * 3;
            default:
                return 5 * countStrobogrammaticByLength(n - 2);
        }
    }

    bool isStrobogrammatic(const string& num) {
        const int n = num.size();
        for (int i = 0; i <= n - 1 - i; ++i) {
            const auto it = lookup.find(num[n - 1 - i]);
            if (it == lookup.end() || num[i] != it->second) {
                return false;
            }
        }
        return true;
    }

private:
    const unordered_map<char, char> lookup{{'0', '0'}, {'1', '1'},
                                           {'6', '9'}, {'8', '8'}, 
                                           {'9', '6'}};
};
