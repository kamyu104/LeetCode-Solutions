// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        return stoi(firstWord) + stoi(secondWord) == stoi(targetWord);
    }

private:
    int stoi(const string& s) {
        int result = 0;
        for (const auto& c : s) {
            result = result * 10 + c - 'a';
        }
        return result;
    }
};
