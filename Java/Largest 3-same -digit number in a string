class Solution {
    private List<String> sameDigitNumbers = List.of("999", "888", "777", "666", "555", "444", "333", "222", "111", "000");

    // Check whether the 'num' string contains the 'sameDigitNumber' string or not.
    private boolean contains(String sameDigitNumber, String num) {
        for (int index = 0; index <= num.length() - 3; ++index) {
            if (num.charAt(index) == sameDigitNumber.charAt(0) &&
                num.charAt(index + 1) == sameDigitNumber.charAt(1) &&
                num.charAt(index + 2) == sameDigitNumber.charAt(2)) {
                return true;
            }
        }
        return false;
    }

    public String largestGoodInteger(String num) {
        // Iterate on all 'sameDigitNumbers' and check if the string 'num' contains it.
        for (String sameDigitNumber : sameDigitNumbers) {
            if (contains(sameDigitNumber, num)) {
                // Return the current 'sameDigitNumbers'.
                return sameDigitNumber;
            }
        }
        // No 3 consecutive same digits are present in the string 'num'.
        return "";
    }
}
