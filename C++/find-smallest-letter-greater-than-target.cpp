// Time:  O(logn)
// Space: O(1)

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        const auto cit = upper_bound(letters.cbegin(), letters.cend(), target);
        return cit != letters.cend() ? *cit : letters.front();
    }
};
