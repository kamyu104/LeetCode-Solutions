// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string removeVowels(string S) {
         return accumulate(S.cbegin(), S.cend(), string{},
                           [](const auto &a, const auto &b) {
                               static const unordered_set<char> lookup = {'a', 'e', 'i', 'o', 'u'};
                               if (!lookup.count(b)) {
                                   return a + b;
                               }
                               return a;
                           });
    }
};
