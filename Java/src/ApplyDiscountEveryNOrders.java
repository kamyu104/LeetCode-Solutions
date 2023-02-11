import java.util.HashMap;
import java.util.Map;

class ApplyDiscountEveryNOrders {
    private int n;
    private int discount;
    private int curr;
    private Map<Integer, Integer> lookup;
    public ApplyDiscountEveryNOrders(int n, int discount, int[] products, int[] prices) {
        this.n = n;
        this.discount = discount;
        this.curr = 0;
        this.lookup = new HashMap<>();

        // Map<Integer, Integer> lookup = new HashMap<>();
        for (int i = 0; i < products.length; i++) {
        lookup.put(products[i], prices[i]);
        }

    }
    
    public double getBill(int[] product, int[] amount) {
        this.curr = (this.curr+1) % this.n;
        double result = 0.0;
        for (int i = 0; i < product.length; i++) {
            int p = product[i];
            Integer pp = this.lookup.get(p);
            if(pp != null){
                result += pp * amount[i];
            }
        }
        return result * (curr == 0 ? (1.0 - (double)discount/100.0) : 1.0);
    }
}

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj.getBill(product,amount);
 */