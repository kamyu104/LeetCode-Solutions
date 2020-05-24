# Time:  O(n)
# Space: O(n)

SELECT a.sale_date,
       a.sold_num - b.sold_num AS diff
FROM
  (SELECT sale_date,
          sold_num
   FROM sales
   WHERE fruit = "apples") a
INNER JOIN
  (SELECT sale_date,
          sold_num
   FROM sales
   WHERE fruit = "oranges") b
ON a.sale_date = b.sale_date;
