// Time:  O(n)
// Space: O(26) = O(1)

class Solution {
public:
    bool checkIfPangram(string sentence) {
        return size(unordered_set<int>(cbegin(sentence), cend(sentence))) == 26;
    }
};
