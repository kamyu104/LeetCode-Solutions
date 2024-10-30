// Time:  O(n)
// Space: O(1)

// array
class Solution {
public:
    int possibleStringCount(string word) {
        int result = size(word);
        for (int i = 0; i + 1 < size(word); ++i) {
            if (word[i] != word[i + 1]) {
                --result;
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
// array
class Solution2 {
public:
    int possibleStringCount(string word) {
        int result = 1;
        for (int i = 0, curr = 0; i < size(word); ++i) {
            ++curr;
            if (i + 1 == size(word) || word[i + 1] != word[i]) {
                result += curr - 1;
                curr = 0;
            }
        }
        return result;
    }
};
