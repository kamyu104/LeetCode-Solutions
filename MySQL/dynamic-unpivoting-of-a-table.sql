# Time:  O(n * m)
# Space: O(n * m)

CREATE PROCEDURE UnpivotProducts()
BEGIN
    SET SESSION group_concat_max_len = 1000000;
    
    SET @sql_query = NULL;
	  SELECT GROUP_CONCAT(
        CONCAT(
            'SELECT product_id, "', column_name, '" AS store, ', column_name, ' AS price FROM products WHERE ', column_name, ' IS NOT NULL'
        ) SEPARATOR ' UNION ALL '
    )
    INTO @sql_query
    FROM information_schema.columns
    WHERE table_name = 'products' AND column_name != 'product_id';
    
    PREPARE sql_query FROM @sql_query;
    EXECUTE sql_query;
    DEALLOCATE PREPARE sql_query;
END
