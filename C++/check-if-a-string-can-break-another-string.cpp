// Time:  O(nlogn)
// Space: O(1)

class Solution {
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
class Solution2 {
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
