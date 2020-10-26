// Time:  O((d + n) * 2^n)
// Space: O(d)

// optimized from Solution2
class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        vector<int> diffs;
        dictionary_to_diffs(target, dictionary, &diffs);
        if (empty(diffs)) {
            return to_string(size(target));
        }
        int total = 1 << size(target);
        int result = total - 1;
        for (int mask = 0; mask < total; ++mask) {
            if (all_of(cbegin(diffs), cend(diffs), [&mask](int d) { return d & mask; })) {
                if (bits_to_abbr_len(target, mask) < bits_to_abbr_len(target, result)) {
                    result = mask;
                }
            }
        }
        return bits_to_abbr(target, result);
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

    int bits_to_abbr_len(const string& target, int bits) {
        int total = 0;
        for (int i = 0, pre = 0; i < size(target); ++i, bits >>= 1) {
            if (bits & 1) {
                if (i - pre > 0) {
                    total += size(to_string(i - pre));
                }
                pre = i + 1;
                ++total;
            } else if (i == size(target) - 1) {
                total += size(to_string(i - pre + 1));
            }
        }
        return total;
    }
    
    string bits_to_abbr(const string& target, int bits) {
        string abbr;
        for (int i = 0, pre = 0; i < size(target); ++i, bits >>= 1) {
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

// Time:  O((d + n) * 2^n)
// Space: O(d + n)
class Solution2 {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        vector<int> diffs;
        dictionary_to_diffs(target, dictionary, &diffs);
        if (empty(diffs)) {
            return to_string(size(target));
        }
        int total = 1 << size(target);
        string result = target;
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
        for (int i = 0, pre = 0; i < size(target); ++i, bits >>= 1) {
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
