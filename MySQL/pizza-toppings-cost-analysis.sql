# Time:  O(n^3 * logn)
# Space: O(n^3)

SELECT CONCAT(t1.topping_name, ",", t2.topping_name, ",", t3.topping_name) AS pizza,
	   ROUND(t1.cost + t2.cost + t3.cost, 2) AS total_cost
FROM Toppings t1
INNER JOIN Toppings t2
ON t1.topping_name < t2.topping_name
INNER JOIN Toppings t3
ON t2.topping_name < t3.topping_name
ORDER BY 2 DESC, 1;
