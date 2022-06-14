// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        static const unordered_set<char> SPECIAL = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '+'};
        
        return size(password) >= 8 &&
               any_of(cbegin(password), cend(password), ::islower) &&
               any_of(cbegin(password), cend(password), ::isupper) &&
               any_of(cbegin(password), cend(password), ::isdigit) &&
               any_of(cbegin(password), cend(password), [&](const auto& c) { return SPECIAL.count(c); }) &&
               adjacent_find(cbegin(password), cend(password)) == cend(password);
    }
};
