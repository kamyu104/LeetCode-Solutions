// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        string result;
        const auto& counter = counts(licensePlate);
        for (const auto& word : words) {
            if ((result.empty() || word.length() < result.length()) &&
               contains(counter, word)) {
                result = word;
            }
        }
        return result;
    }
    
private:
    bool contains(const vector<int>& counter1, const string& w2) const {
        const auto& counter2 = counts(w2);
        for (int i = 0; i < counter2.size(); ++i) {
            if (counter1[i] > counter2[i]) {
                return false;
            }
        }
        return true;
    }
    
    vector<int> counts(const string& s) const {
        vector<int> count(26);
        for (const auto& c : s) {
            if (isalpha(c)) {
                ++count[tolower(c) - 'a'];
            }
        }
        return count;
    }
};
