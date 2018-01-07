// Time:  f(n) = k * f(n/k) + n/k * klogk <= O(logn * nlogk) <= O(n^2)
//        n is the length of S, k is the max number of special strings in each depth
// Space: O(n)

class Solution {
public:
    string makeLargestSpecial(string S) {
        vector<string> result;
        int anchor = 0, count = 0;
        for (int i = 0; i < S.length(); ++i) {
            (S[i] == '1') ? ++count : --count;
            if (count == 0) {
                result.emplace_back("1");
                result.back() += makeLargestSpecial(S.substr(anchor + 1, i - anchor - 1));
                result.back() += "0";
                anchor = i + 1;
            }
        }
        sort(result.begin(), result.end(), greater<string>());
        return accumulate(result.begin(), result.end(), string());
    }
};
