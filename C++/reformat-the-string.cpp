// Time:  O(n)
// Space: O(1)

class Solution {
public:
    string reformat(string s) {
        unordered_map<char, int> count;
        int alpha_cnt = 0;
        for (const auto& c : s) {
            ++count[c];
            if (isalpha(c)) {
                ++alpha_cnt;
            }
        }
        if (abs(int(s.length()) - 2 * alpha_cnt) > 1) {
            return "";
        }
        
        char a = 'a', a_end = 'z';
        char b = '0', b_end = '9';
        if (alpha_cnt < s.length() - alpha_cnt) {
            swap(a, b);
            swap(a_end, b_end);
        }
        string result;
        while (result.length() < s.length()) {
            result.push_back(a = next_char(a, a_end, &count));
            result.push_back(b = next_char(b, b_end, &count));
        }
        if (result.back() == '\0') {
            result.pop_back();
        }
        return result;
    }

private:
    char next_char(char start, char end, unordered_map<char, int> *count) {
        for (char c = start; c <= end; ++c) {
            if ((*count)[c]) {
                --(*count)[c];
                return c;
            }
        }
        return '\0';
    }
};
