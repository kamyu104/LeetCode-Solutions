// Time:  O(2^n)
// Space: O(n)

class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        vector<int> bits_dict;
        int bit_candidates = 0;
        dict_to_bits_dict(target, dictionary, &bits_dict, &bit_candidates);

        int min_len = numeric_limits<int>::max(), min_abbr = 0;
        dfs(target, bit_candidates, 1, 0, &bits_dict, &min_len, &min_abbr);

        return bits_to_abbr(target, min_abbr);
    }

private:
    void dfs(const string& target, int bit_candidates, int bit, int mask,
             vector<int> *bits_dict, int *min_len, int *min_abbr) {

        const auto len = abbr_len(target, mask);
        if (len >= *min_len) {
            return;
        }

        bool match = true;
        for (const auto& d : *bits_dict) {
            if ((mask & d) == 0) {
                match = false;
                break;
            }
        }
        if (match) {
            *min_len = len;
            *min_abbr = mask;
        } else {
            for (int b = bit; b < (1 << target.length()); b <<= 1) {
                if (bit_candidates & b) {
                    dfs(target, bit_candidates, b << 1, mask | b, bits_dict, min_len, min_abbr);
                }
            }
        }
    }

    void dict_to_bits_dict(const string& target, const vector<string>& dictionary,
                         vector<int> *bits_dict, int *bit_candidates) {
        for (const auto& w : dictionary) {
            int word = 0;
            if (w.length() != target.length()) {
                continue;
            }
            for (int i = target.length() - 1, bit = 1; i >= 0; --i, bit <<= 1) {
                if (target[i] != w[i]) {
                    word |= bit;
                }
            }
            bits_dict->emplace_back(word);
            *bit_candidates |= word;
        }
    }

    int abbr_len(const string& target, int mask) {
        int count = 0;
        for (int b = 1; b < (1 << target.length());) {
            if ((mask & b) == 0) {
                for (; b < (1 << target.length()) && (mask & b) == 0; b <<= 1);
            } else {
                b <<= 1;
            }
            ++count;
        }
        return count;
    }

    string bits_to_abbr(const string& target, int min_abbr) {
        vector<string> tmp;
        for (int i = target.length() - 1, pre = i; i >= 0; --i, min_abbr >>= 1) {
            if (min_abbr & 1) {
                if (pre - i > 0) {
                    tmp.emplace_back(to_string(pre - i));
                }
                pre = i - 1;
                tmp.emplace_back(string(1, target[i]));
            } else if (i == 0) {
                tmp.emplace_back(to_string(pre - i + 1));
            }
        }
        reverse(tmp.begin(), tmp.end());

        string abbr;
        for (const auto& s : tmp) {
            abbr += s;
        }
        return abbr;
    }
};
