// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        const int cols = size(encodedText) / rows;
        int k = size(encodedText);
        for (int i = cols - 1; i >= 0 && k == size(encodedText); --i) {
            for (int j = i + ((size(encodedText) - 1) - i) / (cols + 1) * (cols + 1); j >= i; j -= cols + 1) {
                if (encodedText[j] != ' ') {
                    k = j;
                    break;
                }
            }
        }
        string result;
        for (int i = 0; i < cols && k != -1; ++i) {
            for (int j = i; j < size(encodedText); j += cols + 1) {
                result.push_back(encodedText[j]);
                if (j == k) {
                    k = -1;
                    break;
                }
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    string decodeCiphertext(string encodedText, int rows) {
        const int cols = size(encodedText) / rows;
        string result;
        for (int i = 0; i < cols; ++i) {
            for (int j = i; j < size(encodedText); j += cols + 1) {
                result.push_back(encodedText[j]);
            }
        }
        while (!empty(result) && result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }
};
