class Solution {
    private Double[][] cache; // Memoization storage

    public double soupServings(int n) {
        // Large n behaves like probability 1
        if (n > 5000) return 1.0;

        int units = (int) Math.ceil(n / 25.0); // Convert mL → 25 mL units
        cache = new Double[units + 1][units + 1];

        return calcProb(units, units);
    }

    private double calcProb(int soupA, int soupB) {
        // Both soups empty → half probability
        if (soupA <= 0 && soupB <= 0) return 0.5;
        // A empty first
        if (soupA <= 0) return 1.0;
        // B empty first
        if (soupB <= 0) return 0.0;

        // If already computed, return cached result
        if (cache[soupA][soupB] != null) return cache[soupA][soupB];

        // Calculate and store probability
        double prob = 0.25 * (
            calcProb(soupA - 4, soupB) +
            calcProb(soupA - 3, soupB - 1) +
            calcProb(soupA - 2, soupB - 2) +
            calcProb(soupA - 1, soupB - 3)
        );

        cache[soupA][soupB] = prob;
        return prob;
    }
}
