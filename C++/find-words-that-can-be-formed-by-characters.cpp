// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        const auto& count = counter(chars);
        int result = 0;
        for (const auto& word : words) {
            if (check(word, count)) {
                result += word.length();
            }
        }
        return result;
    }

private:
    unordered_map<char, int> counter(const string& s) {
        unordered_map<char, int> result;
        for (const auto& c : s) {
            ++result[c];
        }
        return result;
    }
    
    bool check(const string& s,
               const unordered_map<char, int>& count2) {
        unordered_map<char, int> count1;
        for (const auto& c : s) {
            ++count1[c];
            if (!count2.count(c) || count2.at(c) < count1[c]) {
                return false;
            }
        }
        return true;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    int countCharacters(vector<string>& words, string chars) {
        const auto& count = counter(chars);
        int result = 0;
        for (const auto& word : words) {
            if (check(counter(word), count)) {
                result += word.length();
            }
        }
        return result;
    }

private:
    unordered_map<char, int> counter(const string& s) {
        unordered_map<char, int> result;
        for (const auto& c : s) {
            ++result[c];
        }
        return result;
    }
    
    bool check(const unordered_map<char, int>& count1,
               const unordered_map<char, int>& count2) {
        for (const auto& [k, v] : count1) {
            if (!count2.count(k) || count2.at(k) < v) {
                return false;
            }
        }
        return true;
    }
};
