// Time:  O(r + n * c)
// Space: O(n)

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        vector<int> wc(sentence.size());
        for (int i = 0; i < sentence.size(); ++i) {
            wc[i] = wordsFit(sentence, i, cols);
        }

        int words = 0, start = 0;
        for (int i = 0; i < rows; ++i) {
            words += wc[start];
            start = (start + wc[start]) % sentence.size();
        }
        return words / sentence.size();
    }

private:
    int wordsFit(const vector<string>& sentence, int start, int cols) {
        if (sentence[start].length() > cols) {
            return 0;
        }

        int sum = sentence[start].length(), count = 1;
        for (int i = (start + 1) % sentence.size();
             sum + 1 + sentence[i].length() <= cols;
             i = (i + 1) % sentence.size()) {
            sum += 1 + sentence[i].length();
            ++count;
        }
        return count;
    }
};
