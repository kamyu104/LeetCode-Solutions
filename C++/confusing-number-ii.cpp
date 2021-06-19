// Time:  O(logn)
// Space: O(logn)

class Solution {
public:
    int confusingNumberII(int n) {
        return totalCount(n) - validCountInLessLength(n) - validCountInFullLength(n);
    }
    
private:
    int totalCount(int n) {  // count all numbers in the pattern of [01689]{1,len(n)} in the range of [1, n]
        const auto& s = to_string(n);
        int total = 0;
        int p = pow(lookup.size(), s.length() - 1);
        for (int i = 0; i <= s.length(); ++i, p /= lookup.size()) {
            if (i == s.length()) {
                ++total;
                break;
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
        return total - 1;  // exclude 0
    }
    
    int validCountInLessLength(int n) {  // count unconfusing numbers in the pattern of [01689]{1,len(n)-1} in the range of [1, n]
        const auto& s = to_string(n);
        int valid = 0;
        int total = centers.size();
        for (int i = 1; i < s.length(); i += 2) {  // count unconfusing numbers for each odd length less than s
            if (i == 1) {
                valid += accumulate(cbegin(centers), cend(centers), 0,
                                    [](const auto& total, const auto& kvp) {
                                        return total + (kvp.first != '0');
                                    });
            } else {
                valid += total * (lookup.size() - 1);
                total *= lookup.size();
            }
        }
        total = 1;
        for (int i = 2; i < s.length(); i += 2) {  // count unconfusing numbers for each even length less than s
            valid += total * (lookup.size() - 1);
            total *= lookup.size();
        }
        return valid;
    }
    
    int validCountInFullLength(int n) {  // count unconfusing numbers in the pattern of [01689]{len(n)} in the range of [1, n]
        const auto& s = to_string(n);
        const auto& half_s = s.substr(0, (s.length() + 1) / 2);
        int total = 0;
        const auto& choices = (s.length() % 2) ? centers : lookup;
        int p = pow(lookup.size(), int(half_s.length()) - 2) * choices.size();
        for (int i = 0; i < half_s.length(); ++i, p /= lookup.size()) {
            if (i == half_s.length() - 1) {
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
                if (stoull(tmp) <= n && n != 0) {
                    ++total;
                }
                break;
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


// Time:  O(logn)
// Space: O(logn)
class Solution2 {
public:
    int confusingNumberII(int n) {
        return f(n) - f(0);  // f(0) is always 0 and could be ignored
    }
    
private:
    int f(int n) {  // count confusing numbers in the range of [0, n]
        return totalCount(n) - validCountInLessLength(n) - validCountInFullLength(n);
    }

    int totalCount(int n) {  // count all numbers in the pattern of [01689]{1,len(n)} in the range of [0, n]
        const auto& s = to_string(n);
        int total = 0;
        int p = pow(lookup.size(), s.length() - 1);
        for (int i = 0; i <= s.length(); ++i, p /= lookup.size()) {
            if (i == s.length()) {
                ++total;
                break;
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
    
    int validCountInLessLength(int n) {  // count unconfusing numbers in the pattern of [01689]{1,len(n)-1} in the range of [0, n]
        const auto& s = to_string(n);
        int valid = 0;
        int total = centers.size();
        for (int i = 1; i < s.length(); i += 2) {  // count unconfusing numbers for each odd length less than s
            if (i == 1) {
                valid += centers.size();
            } else {
                valid += total * (lookup.size() - 1);
                total *= lookup.size();
            }
        }
        total = 1;
        for (int i = 2; i < s.length(); i += 2) {  // count unconfusing numbers for each even length less than s
            valid += total * (lookup.size() - 1);
            total *= lookup.size();
        }
        return valid;
    }
    
    int validCountInFullLength(int n) {  // count unconfusing numbers in the pattern of [01689]{len(n)} in the range of [0, n]
        const auto& s = to_string(n);
        const auto& half_s = s.substr(0, (s.length() + 1) / 2);
        int total = 0;
        const auto& choices = (s.length() % 2) ? centers : lookup;
        int p = pow(lookup.size(), int(half_s.length()) - 2) * choices.size();
        for (int i = 0; i < half_s.length(); ++i, p /= lookup.size()) {
            if (i == half_s.length() - 1) {
                for (const auto& kvp : choices) {
                    if (kvp.first == '0' && s.length() == 2) {
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
                if (stoull(tmp) <= n) {
                    ++total;
                }
                break;
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
