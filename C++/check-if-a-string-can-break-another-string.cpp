// Time:  O(n)
// Space: O(1)

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        const auto& count1 = counter(s1), &count2 = counter(s2);
        return isBreak(count1, count2) || isBreak(count2, count1);
    }

private:
    bool isBreak(const vector<int>& count1, const const vector<int>& count2) {
        int curr1 = 0, curr2 = 0;
        for (int c = 0; c < 26; ++c) {
            curr1 += count1[c];
            curr2 += count2[c];
            if (curr1 < curr2) {
                return false;
            }
        }
        return true;
    }
    
    vector<int> counter(const string& word) {
        vector<int> count(26);
        for (const auto& c : word) {
            ++count[c - 'a'];
        }
        return count;
    }
};

// Time:  O(nlogn)
// Space: O(1)
class Solution2 {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(begin(s1), end(s1)), sort(begin(s2), end(s2));
        bool flag1 = true, flag2 = true;
        for (int i = 0; i < s1.length(); ++i) {
            if (s1[i] < s2[i]) {
                flag1 = false;
            }
            if (s2[i] < s1[i]) {
                flag2 = false;
            }
            if (!flag1 && !flag2) {
                return false;
            }
        }
        return true;
    }
};

// Time:  O(nlogn)
// Space: O(1)
class Solution3 {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(begin(s1), end(s1)), sort(begin(s2), end(s2));
        return isBreak(s1, s2) || isBreak(s2, s1);
    }

private:
    bool isBreak(const string& s1, const string& s2) {
        int i = 0;
        for (; i < s1.length(); ++i) {
            if (!(s1[i] >= s2[i])) {
                break;
            }
        }
        return (i == s1.length());
    }
};
