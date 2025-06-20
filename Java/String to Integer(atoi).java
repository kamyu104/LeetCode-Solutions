class Solution {
    public int myAtoi(String s) {
        // Step 1: Trim leading/trailing whitespaces
        s = s.trim();

        // Initialize result
        int res = 0;
        int n = s.length();
        if (n < 1)
            return res; // return 0 for empty string

        // Step 2: Determine the sign
        int sign = 1;
        int base = 0;
        int i = 0;

        // Skip any leading spaces (already trimmed, but this is defensive)
        while (i < n && s.charAt(i) == ' ')
            i++;

        // Check if the next character is '+' or '-'
        if (i < n && (s.charAt(i) == '-' || s.charAt(i) == '+')) {
            if (s.charAt(i) == '-') {
                sign = -1;
            }
            i++;
        }

        // Step 3: Convert the numeric characters to integer
        while (i < n && s.charAt(i) >= '0' && s.charAt(i) <= '9') {
            int num = s.charAt(i) - '0';

            // Step 4: Check for overflow before it happens
            if (base > Integer.MAX_VALUE / 10 ||
                    (base == Integer.MAX_VALUE / 10 && num > 7)) {
                // Return max or min int depending on the sign
                return sign == 1 ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            }

            // Step 5: Append current digit
            base = base * 10 + num;
            i++;
        }

        // Step 6: Return final result with correct sign
        return base * sign;
    }
}

