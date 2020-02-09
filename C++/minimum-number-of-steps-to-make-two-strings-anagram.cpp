// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int minSteps(string s, string t) {
        const auto& count1 = counter(s);
        const auto& count2 = counter(t);
        int result = 0;
        for (int i = 0; i < count1.size(); ++i) {
            result += max(count1[i] - count2[i], 0);
        }
        return result;
    }
    
private:
    vector<int> counter(const string& s) const {
        vector<int> count(26);
        for (const auto& c : s) {
            ++count[c - 'a'];
        }
        return count;
    }
};
