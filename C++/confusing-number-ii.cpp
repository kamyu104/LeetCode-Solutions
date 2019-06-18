// Time:  O(logn)
// Space: O(logn)

class Solution {
public:
    int confusingNumberII(int N) {
        return totalCount(N) - validCountInLessLength(N) - validCountInFullLength(N);
    }
    
private:
    int totalCount(int N) {
        const auto& s = to_string(N);
        int total = 0;
        int p = pow(lookup.size(), s.length() - 1);
        for (int i = 0; i < s.length(); ++i, p /= lookup.size()) {
            if (i + 1 == s.length()) {
                for (const auto& kvp : lookup) {
                    total += int(kvp.first <= s[i]);
                }
                continue;
            }
            int smaller = 0;
            for (const auto& kvp : lookup) {
                smaller += int(kvp.first < s[i]);
            }
            total += smaller * p;
            if (!lookup.count(s[i])) {
                break;
            }
        }
        return total;
    }
    
    int validCountInLessLength(int N) {
        const auto& s = to_string(N);
        int valid = 0;
        int total = centers.size();
        for (int i = 1; i < s.length(); i += 2) {
            if (i == 1) {
                valid += total;
            } else {
                valid += total * (lookup.size() - 1);
                total *= lookup.size();
            }
        }
        total = 1;
        for (int i = 2; i < s.length(); i += 2) {
            valid += total * (lookup.size() - 1);
            total *= lookup.size();
        }
        return valid;
    }
    
    int validCountInFullLength(int N) {
        const auto& s = to_string(N);
        const auto& half_s = s.substr(0, (s.length() + 1) / 2);
        int total = 0;
        int p = (s.length() % 2) ? pow(lookup.size(), half_s.length() - 2) * centers.size() : 
                                   pow(lookup.size(), half_s.length() - 1);
        const auto& choices = (s.length() % 2) ? centers : lookup;
        for (int i = 0; i < half_s.length(); ++i, p /= lookup.size()) {
            if (i + 1 == half_s.length()) {
                for (const auto& kvp : choices) {
                    if (kvp.first == '0' && i == 0) {
                        continue;
                    }
                    total += int(kvp.first < half_s[i]);
                }
                if (!choices.count(half_s[i])) {
                    break;
                }
                string tmp(half_s);
                for (int i = half_s.length() - 1 - (s.length() % 2); i >= 0; --i) {
                    tmp.push_back(lookup.at(half_s[i]));
                }
                if (stoull(tmp) <= N) {
                    ++total;
                }
                continue;
            }
            int smaller = 0;
            for (const auto& kvp : lookup) {
                if (kvp.first == '0' && i == 0) {
                    continue;
                }
                smaller += int(kvp.first < half_s[i]);
            }
            total += smaller * p;
            if (!lookup.count(half_s[i])) {
                break;
            }
        }
        return total;
    }
    
    const unordered_map<char, char> lookup = {{'0', '0'}, {'1', '1'}, {'6', '9'},
                                              {'8', '8'}, {'9', '6'}};
    const unordered_map<char, char> centers = {{'0', '0'}, {'1', '1'}, {'8', '8'}};
};
