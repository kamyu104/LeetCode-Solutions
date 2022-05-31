// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string result;
        for (int i = 0, j = -1; i < size(sentence); i = j + 1) {
            j = sentence.find(' ', i);
            if (j == string::npos) {
                j = size(sentence);
            }
            if (sentence[i] == '$' && j - (i + 1) > 0 && all_of(cbegin(sentence) + i + 1, cbegin(sentence) + j, ::isdigit)) {
                const auto& integers = to_string(stoll(x) * (100 - discount) / 100);
                const auto& decimals = to_string(stoll(x) * (100 - discount) % 100);
                const auto& paddings = string(2 - size(decimals), '0');
                result += "$";
                result += integers;
                result += ".";
                result += paddings;
                result += decimals;
            } else {
                for (int k = i; k < j; ++k) {
                    result.push_back(sentence[k]);
                }
            }
            if (j != size(sentence)) {
                result.push_back(' ');
            }
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// string
class Solution2 {
public:
    string discountPrices(string sentence, int discount) {
        string result;
        for (const auto& x : split(sentence, ' ')) {
            if (x[0] == '$' && size(x) - 1 > 0 && all_of(cbegin(x) + 1, cend(x), ::isdigit)) {
                const auto& integers = to_string(stoll(x) * (100 - discount) / 100);
                const auto& decimals = to_string(stoll(x) * (100 - discount) % 100);
                const auto& paddings = string(2 - size(decimals), '0');
                result += "$";
                result += integers;
                result += ".";
                result += paddings;
                result += decimals;
            } else {
                result += x;
            }
            result.push_back(' ');
        }
        result.pop_back();
        return result;
    }

private:
    vector<string> split(const string& s, const char delim) {
        vector<string> tokens;
        stringstream ss(s);
        string token;
        while (getline(ss, token, delim)) {
            if (!empty(token)) {
                tokens.emplace_back(token);
            }
        }
        return tokens;
    }
};
