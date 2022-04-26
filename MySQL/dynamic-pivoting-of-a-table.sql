# Time:  O(n * m)
# Space: O(n * m)

CREATE PROCEDURE PivotProducts()
BEGIN
    SET SESSION group_concat_max_len = 1000000;

    SET @case_stmt = NULL;
    SELECT GROUP_CONCAT(
        DISTINCT CONCAT(
            'MIN(CASE WHEN store = "', store, '" THEN price END) AS ', store
        ) SEPARATOR ','
    )
    INTO @case_stmt
    FROM products;

    SET @sql_query = CONCAT('SELECT product_id, ', @case_stmt, ' FROM products GROUP BY product_id ORDER BY NULL');

    PREPARE sql_query FROM @sql_query;
    EXECUTE sql_query;
    DEALLOCATE PREPARE sql_query;
END
