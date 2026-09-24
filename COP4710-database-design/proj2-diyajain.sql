--Name: Diya Jain
--U81673988

--1

SELECT max(ps.ps_supplycost) AS p_max, s.s_name
FROM supplier s
JOIN partsupp ps ON s.s_suppkey = ps.ps_suppkey
WHERE ps.ps_supplycost < 200.00
GROUP BY s.s_name
HAVING COUNT(*) = 20
ORDER BY s.s_name ASC;

--it is working, output is correct, checked

--2

SELECT s.s_suppkey, s.s_name
FROM supplier s
WHERE s.s_suppkey IN (
    SELECT ps.ps_suppkey
    FROM partsupp ps, lineitem li, orders o, customer c, nation n
    WHERE ps.ps_partkey = li.l_partkey 
        AND li.l_orderkey = o.o_orderkey 
        AND o.o_custkey = c.c_custkey 
        AND c.c_nationkey = n.n_nationkey 
        AND n.n_name = 'UNITED STATES'
)
AND s.s_suppkey IN (
    SELECT ps.ps_suppkey
    FROM partsupp ps, lineitem li, orders o, customer c, nation n
    WHERE ps.ps_partkey = li.l_partkey 
        AND li.l_orderkey = o.o_orderkey 
        AND o.o_custkey = c.c_custkey 
        AND c.c_nationkey = n.n_nationkey 
        AND n.n_name = 'CANADA'
);

--it is working, output is correct, checked

--3

SELECT n.n_name
FROM nation n 
LEFT JOIN supplier s on n.n_nationkey = s.s_nationkey
WHERE s.s_nationkey is NULL;

--it is working, output is correct, checked

--4

SELECT c.c_name, AVG(o.o_totalprice) as avg
FROM customer c 
JOIN orders o ON c.c_custkey = o.o_custkey
WHERE c.c_nationkey = (SELECT n_nationkey FROM nation WHERE n_name = 'PERU')
GROUP BY c.c_name
ORDER BY c_name ASC;

--it is working, output is correct, checked

--5

WITH order_counts AS
(
    SELECT o_custkey, COUNT(*) as o_cnt 
    FROM orders 
    GROUP BY o_custkey
),
max_order_count as
(
    SELECT max(o_cnt) as max_count 
    FROM order_counts
)
SELECT c_name, order_counts.o_cnt
FROM customer
JOIN order_counts on customer.c_custkey = order_counts.o_custkey
JOIN max_order_count on order_counts.o_cnt = max_order_count.max_count
ORDER BY max_count DESC;

--it is working, output is correct, checked

--6

SELECT s.s_name, COUNT(DISTINCT p.p_container) as count
FROM part p 
JOIN partsupp ps on p.p_partkey = ps.ps_partkey 
JOIN supplier s on ps.ps_suppkey = s.s_suppkey
GROUP BY s.s_suppkey, s.s_name
HAVING COUNT(DISTINCT p.p_container) = (SELECT COUNT(DISTINCT p_container) FROM part);

--it is working, output is correct, checked

--7

SELECT c.c_custkey, s.s_name
FROM customer c
JOIN orders o ON c.c_custkey = o.o_custkey
JOIN lineitem li ON o.o_orderkey = li.l_orderkey
JOIN partsupp ps ON li.l_suppkey = ps.ps_suppkey AND li.l_partkey = ps.ps_partkey
JOIN supplier s ON ps.ps_suppkey = s.s_suppkey
JOIN nation n1 ON c.c_nationkey = n1.n_nationkey
JOIN nation n2 ON s.s_nationkey = n2.n_nationkey AND n1.n_nationkey = n2.n_nationkey;

--it is working, output is correct, checked

--8

SELECT p.p_name, p.p_retailprice 
FROM part p
JOIN
(
    SELECT p_retailprice
    FROM part
    WHERE p_partkey = 197998
)
p2 on p.p_retailprice >= p2.p_retailprice
ORDER BY p.p_name DESC;

--it is working, output is correct, checked

--9

SELECT l_orderkey, l_partkey, l_suppkey, l_linenumber, l_discount * l_quantity * l_extendedprice as discount 
FROM lineitem
WHERE l_discount * l_quantity * l_extendedprice = 
(
    SELECT max(l_discount * l_quantity * l_extendedprice)
    FROM lineitem
)
LIMIT 1;

--it is working, output is correct, checked

--10

SELECT p_name, p_retailprice
FROM part
WHERE p_retailprice=
(
    SELECT max(p_retailprice)
    FROM part
    WHERE p_retailprice < (SELECT max(p_retailprice)FROM part)
);

--it is working, output is correct, checked