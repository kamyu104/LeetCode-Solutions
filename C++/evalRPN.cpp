// Time Space: O(n)
// Space Space: O(logn)

class Solution {
    public:
        int evalRPN(vector<string> &tokens) {
            stack<string> s;
            for(auto tok : tokens) {
                if(!is_operator(tok)) {
                    s.push(tok);
                }
                else {
                    int y = stoi(s.top());
                    s.pop();
                    int x = stoi(s.top());
                    s.pop();
                    if(tok[0] == '+') x += y;
                    else if (tok[0] == '-') x -= y;
                    else if (tok[0] == '*') x *= y;
                    else x /= y;
                    s.push(to_string(x));
                }
            }
            return stoi(s.top());
        }
    private:
        bool is_operator(const string &op) {
            return op.length() == 1 && string("+-*/").find(op) != string::npos;
        }
};
