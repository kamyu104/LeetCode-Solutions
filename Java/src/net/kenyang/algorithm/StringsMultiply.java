
import java.util.*;

public class StringsMultiply {

    public static String multiply(String num1, String num2) {
        Map<Integer, Integer> map = new TreeMap<>();
        StringBuilder sBuilder = new StringBuilder();
        num1 = new StringBuilder(num1).reverse().toString();
        num2 = new StringBuilder(num2).reverse().toString();
        for (int i = 0; i < num1.length(); i++) {
            for (int j = 0; j < num2.length(); j++) {
                int num1Int = Integer.parseInt(String.valueOf(num1.charAt(i)));
                int num2Int = Integer.parseInt(String.valueOf(num2.charAt(j)));
                int result = num1Int * num2Int;
                if (result > 9){
                    int firstDigit = result % 10;
                    int secondDigit = result / 10;
                    addToMap(map, i + j, firstDigit);
                    addToMap(map, i + j + 1, secondDigit);
                } else {
                    addToMap(map, i + j, result);
                }
            }
        }

        Iterator<Map.Entry<Integer, Integer>> iterator = map.entrySet().iterator();
        while (iterator.hasNext()){
            Map.Entry<Integer,Integer> e = iterator.next();
            int index = e.getKey();
            Integer sum = e.getValue();
            if (sum > 9){
                int firstDigit = sum % 10;
                int secondDigit = sum / 10;
                sBuilder.append(firstDigit);
                addToMap(map, index + 1, secondDigit);
            } else {
               sBuilder.append(sum);
            }
        }

        return sBuilder.reverse().toString();
    }

    private static void addToMap(Map<Integer, Integer> map, int index, int firstDigit) {
        map.merge(index, firstDigit, Integer::sum);
    }

    public static void main(String[] args) {
        System.out.println(multiply("12", "12"));
        System.out.println(multiply("25", "24"));
        System.out.println(multiply("25234332321", "24213345454"));
    }
}
