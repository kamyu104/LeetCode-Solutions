// Time:  O(n)
// Space: O(1)

// string
class Solution {
public:
    string convertNumber(string s) {
        static const unordered_map<string, char> LOOKUP = {
            {"zero", '0'}, {"one", '1'}, {"two", '2'}, {"three", '3'}, {"four", '4'},
            {"five", '5'}, {"six", '6'}, {"seven", '7'}, {"eight", '8'}, {"nine", '9'}
        };

        string result;
        for (int i = 0; i < size(s);) {
            int l = 3;
            for (; l <= 5; ++l) {
                const auto& t = s.substr(i, l);
                if (LOOKUP.count(t)) {
                    result.push_back(LOOKUP.at(t));
                    break;
                }
            }
            i += l <= 5 ? l : 1;
        }
        return result;
    }
};
