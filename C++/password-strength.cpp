// Time:  O(n)
// Space: O(1)

// string, hash table
class Solution {
public:
    int passwordStrength(string password) {
        int result = 0;
        for (const auto& x : unordered_set<char>(cbegin(password), cend(password))) {
            if (islower(x)) {
                result += 1;
            } else if (isupper(x)) {
                result += 2;
            } else if (isdigit(x)) {
                result += 3;
            } else {
                result += 5;
            }
        }
        return result;
    }
};
