// Time:  O(n * 2^n)
// Space: O(n)

class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        vector<int> diffs;
        dictionary_to_diffs(target, dictionary, &diffs);
        if (empty(diffs)) {
            return to_string(size(target));
        }
        string result = target;
        int total = 1 << size(target);
        for (int mask = 0; mask < total; ++mask) {
            if (all_of(cbegin(diffs), cend(diffs), [&mask](int d) { return d & mask; })) {
                auto abbr = bits_to_abbr(target, mask);
                if (size(abbr) < size(result)) {
                    result = move(abbr);
                }
            }
        }
        return result;
    }

private:
    void dictionary_to_diffs(const string& target, const vector<string>& dictionary,
                             vector<int> *diffs) {

        for (const auto& word : dictionary) {
            if (size(word) != size(target)) {
                continue;
            }
            int bits = 0;
            for (int i = 0; i < size(word); ++i) {
                if (target[i] != word[i]) {
                    bits |= 1 << i;
                }
            }
            diffs->emplace_back(bits);
        }
    }

    string bits_to_abbr(const string& target, int bits) {
        string abbr;
        int pre = 0;
        for (int i = 0, prev = 0; i < size(target); ++i, bits >>= 1) {
            if (bits & 1) {
                if (i - pre > 0) {
                    abbr += to_string(i - pre);
                }
                pre = i + 1;
                abbr.push_back(target[i]);
            } else if (i == size(target) - 1) {
                abbr += to_string(i - pre + 1);
            }
        }
        return abbr;
    }
};
