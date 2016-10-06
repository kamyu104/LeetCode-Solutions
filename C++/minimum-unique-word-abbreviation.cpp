// Time:  O(2^n)
// Space: O(n)

class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        vector<int> diffs;
        dictionary_to_diffs(target, dictionary, &diffs);

        if (diffs.empty()) {
            return to_string(target.length());
        }

        int bits = (1 << target.length()) - 1;
        for (int i = 0; i < (1 << target.length()); ++i) {
            if (all_of(diffs.begin(), diffs.end(), [&i](int d) { return d & i; } )) {
                if (bits_len(target, i) > bits_len(target, bits)) {
                    bits = i;
                }
            }
        }

        return bits_to_abbr(target, bits);
    }

private:
    void dictionary_to_diffs(const string& target, const vector<string>& dictionary,
                             vector<int> *diffs) {

        for (const auto& word : dictionary) {
            if (word.length() != target.length()) {
                continue;
            }

            int bits = 0;
            for (int i = 0; i < word.length(); ++i) {
                if (target[i] != word[i]) {
                    bits |= 1 << i;
                }
            }
            diffs->emplace_back(bits);
        }
    }

    int bits_len(const string& target, int bits) {
        int sum = 0;

        for (int i = 0; i < target.length() - 1; ++i) {
            if (((bits >> i) & 3) == 0) {
                ++sum;
            }
        }

        return sum;
    }

    string bits_to_abbr(const string& target, int bits) {
        string abbr;

        int pre = 0;
        for (int i = 0, prev = 0; i < target.length(); ++i, bits >>= 1) {
            if (bits & 1) {
                if (i - pre > 0) {
                    abbr += to_string(i - pre);
                }
                pre = i + 1;
                abbr.push_back(target[i]);
            } else if (i == target.length() - 1) {
                abbr += to_string(i - pre + 1);
            }
        }

        return abbr;
    }
};
