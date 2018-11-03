// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> numeral_map = {{'I',    1}, {'V',   5}, {'X',  10},
                                                {'L',   50}, {'C', 100}, {'D', 500},
                                                {'M', 1000}};
        return accumulate(s.crbegin() , s.crend() , 0 , [&numeral_map](int sum , char c){
            return sum += ((numeral_map[c] * 5 <= sum) && (c!= 'M') ?  -numeral_map[c]: numeral_map[c]);
        });
    }
};
