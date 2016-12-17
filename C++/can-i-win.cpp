// Time:  O(n!)
// Space: O(n)

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if ((1 + maxChoosableInteger) * (maxChoosableInteger / 2) < desiredTotal) {
            return false;
        }
        unordered_map<int, int> lookup;
        return canIWinHelper(maxChoosableInteger, desiredTotal, 0, &lookup);
    }

private:
    int canIWinHelper(int maxChoosableInteger, int desiredTotal,
                      int visited, unordered_map<int, int> *lookup) {

        if  (lookup->find(visited) != lookup->end()) {
            return (*lookup)[visited];
        }
        int mask = 1;
        for (int i = 0; i < maxChoosableInteger; ++i) {
            if (!(visited & mask)) {
                if (i + 1 >= desiredTotal ||
                    !canIWinHelper(maxChoosableInteger, desiredTotal - (i + 1), visited | mask, lookup)) {
                    (*lookup)[visited] = true;
                    return true;
                }
            }
            mask <<= 1;
        }
        (*lookup)[visited] = false;
        return false;
    }
};
