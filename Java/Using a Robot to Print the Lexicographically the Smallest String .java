class Solution 
{
    public String robotWithString(String s) 
    {
        int n = s.length();

        // Step 1: Initialize min_suffix array
        char[] minSuffix = new char[n];
        minSuffix[n - 1] = s.charAt(n - 1);

        // Step 2: Fill min_suffix from right to left
        for (int i = n - 2; i >= 0; i--) 
        {
            minSuffix[i] = (char)Math.min(s.charAt(i), minSuffix[i + 1]);
        }

        // Step 3: Initialize result and stack
        Deque<Character> stack = new ArrayDeque<>();
        StringBuilder result = new StringBuilder();
        int i = 0;

        // Step 4: Process characters from s
        while (i < n) 
        {
            stack.push(s.charAt(i++)); // Push to t

            // Step 4 (cont.): Pop from t to result if top is safe
            while (!stack.isEmpty() && stack.peek() <= minSuffix[i == n ? n - 1 : i]) 
            {
                result.append(stack.pop());
            }
        }

        // Step 5: Clean remaining stack
        while (!stack.isEmpty()) 
        {
            result.append(stack.pop());
        }

        // Step 6: Return result
        return result.toString();
    }
}
