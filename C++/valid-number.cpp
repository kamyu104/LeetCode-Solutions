// Time:  O(n)
// Space: O(1)

// automata: http://images.cnitblog.com/i/627993/201405/012016243309923.png
class Solution {
public:
    bool isNumber(string s) {
        enum InputType {
            INVALID,    // 0
            SPACE,      // 1
            SIGN,       // 2
            DIGIT,      // 3
            DOT,        // 4
            EXPONENT,   // 5
            NUM_INPUTS  // 6
        };
        int transitionTable[][NUM_INPUTS] = {
            -1,  0,  3,  1,  2, -1,     // next states for state 0
            -1,  8, -1,  1,  4,  5,     // next states for state 1
            -1, -1, -1,  4, -1, -1,     // next states for state 2
            -1, -1, -1,  1,  2, -1,     // next states for state 3
            -1,  8, -1,  4, -1,  5,     // next states for state 4
            -1, -1,  6,  7, -1, -1,     // next states for state 5
            -1, -1, -1,  7, -1, -1,     // next states for state 6
            -1,  8, -1,  7, -1, -1,     // next states for state 7
            -1,  8, -1, -1, -1, -1,     // next states for state 8
        };

        int state = 0;
        for (const auto& c: s) {
            InputType inputType = INVALID;
            if (isspace(c)) {
                inputType = SPACE;
            } else if (c == '+' || c == '-') {
                inputType = SIGN;
            } else if (isdigit(c)) {
                inputType = DIGIT;
            } else if (c == '.') {
                inputType = DOT;
            } else if (c == 'e' || c == 'E') {
                inputType = EXPONENT;
            }
            // Get next state from current state and input symbol
            state = transitionTable[state][inputType];

            // Invalid input
            if (state == -1) {
                return false;
            }
        }
        // If the current state belongs to one of the accepting (final) states,
        // then the number is valid
        return state == 1 || state == 4 || state == 7 || state == 8;
    }
};

#include <regex>
class Solution_TLE {
public:
    bool isNumber(string s) {
        regex e("^\\s*[\\+-]?((\\d+(\\.\\d*)?)|\\.\\d+)([eE][\\+-]?\\d+)?\\s*$");
        return regex_match(s, e);
    }
};
