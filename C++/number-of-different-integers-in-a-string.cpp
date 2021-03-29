// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int numDifferentIntegers(string word) {
        word.push_back(' ');
        unordered_set<string> result;
        string num;
        for (const auto& c : word) {
            if (isdigit(c)) {
                if (!empty(num) && num[0] == '0') {
                    num[0] = c;
                } else {
                    num.push_back(c);
                }
            } else if (!empty(num)) {
                result.emplace(move(num));
            }
        }
        return size(result);
    }
};
