// Time:  O(n), n is the length of sequence
// Space: O(m), m is the length of word

// optimized kmp solution
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        if (size(sequence) < size(word)) {
            return 0;
        }
        const vector<int> prefix = getPrefix(word);
        int result = 0, count = 0, j = -1, prev = -1;
        for (int i = 0; i < size(sequence); ++i) {
            while (j > -1 && word[j + 1] != sequence[i]) {
                j = prefix[j];
            }
            if (word[j + 1] == sequence[i]) {
                ++j;
            }
            if (j + 1 == size(word)) {
                count = (i - prev == size(word)) ? count + 1 : 1;
                result = max(result, count);
                j = -1, prev = i;
            }
        }
        return result;
    }

private:
    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(size(pattern), -1);
        int j = -1;
        for (int i = 1; i < size(pattern); ++i) {
            while (j > -1 && pattern[j + 1] != pattern[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }
};

// Time:  O(n), n is the length of sequence
// Space: O(n)
// kmp solution
class Solution2 {
public:
    int maxRepeating(string sequence, string word) {
        if (size(sequence) < size(word)) {
            return 0;
        }
        string new_word;
        for (int i = 0; i < size(sequence) / size(word); ++i) {
            new_word += word;
        }
        const vector<int> prefix = getPrefix(new_word);
        int result = 0, j = -1;
        for (int i = 0; i < size(sequence); ++i) {
            while (j > -1 && new_word[j + 1] != sequence[i]) {
                j = prefix[j];
            }
            if (new_word[j + 1] == sequence[i]) {
                ++j;
            }
            result = max(result, j + 1);
            if (j + 1 == size(new_word)) {
                break;
            }
        }
        return result / size(word);
    }

private:
    vector<int> getPrefix(const string& pattern) {
        vector<int> prefix(size(pattern), -1);
        int j = -1;
        for (int i = 1; i < size(pattern); ++i) {
            while (j > -1 && pattern[j + 1] != pattern[i]) {
                j = prefix[j];
            }
            if (pattern[j + 1] == pattern[i]) {
                ++j;
            }
            prefix[i] = j;
        }
        return prefix;
    }
};
