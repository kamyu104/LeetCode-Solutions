package net.kenyang.algorithm;

/**
 * Reverse digits of an integer.
 * </br></br>
 * Example1: x = 123, return 321 </br>
 * Example2: x = -123, return -321
 * @author Ken Yang
 *
 */
public class ReverseInteger {
    public int reverse(int x){
        int newValue = 0;
        while (x!=0) {
            int mod = x % 10;
            newValue = newValue*10 + mod;
            x /=10;
        }
        return newValue;
    }
}
