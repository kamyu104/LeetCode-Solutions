// Time:  O(logn) = O(1)
// Space: O(1)

class Solution {
public:
    int reverse(int x) {
        long long ans = 0;
        
        if(x/10 == 0)
            return x;
        
        while(x){
            ans = ans*10 + x%10;
            x = x/10;
        }
        
        return (ans > INT_MAX || ans < INT_MIN) ? 0 : ans;
    }
};
