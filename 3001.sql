SELECT name as type, CASE WHEN products.type = 'A' THEN '20.0' WHEN products.type = 'B' THEN '70.0' ELSE '530.5' END AS price FROM products ORDER BY products.type ASC, products.id DESC
