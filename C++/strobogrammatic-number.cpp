// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool isStrobogrammatic(string num) {
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
