--  Before you try the code in this file from the psql client, you need to create your database NBA-xxx and copy data from NBA to it. For example,
--  createdb NBA-tuy
--  pg_dump -t player_rs_career NBA | psql NBA-tuy
--  Note that those should be done under the Linux console. Then you can log into NBA-xxx and try the following scripts.

--  The following line only needs to be executed once before you do anything at all with pgplsql functions

CREATE LANGUAGE 'plpgsql';

-- function 1 answer

CREATE OR REPLACE FUNCTION fibonacci(lastN INTEGER)
RETURNS int AS $$
DECLARE
    N1 int;
	N2 int;
	N3 int;
	i int;
BEGIN
    -- Check if in range
    IF lastN < 0 OR lastN > 1000 THEN
        RETURN -1;
    END IF;

    -- Base tests when the number is 0 or 1
    IF lastN = 0 OR lastN = 1 THEN
        RETURN lastN;
    ELSE
        -- Calculate Fibonacci sequence using a loop
		FOR i IN 2..lastN LOOP
    	N1 := N2 + N3;
    	N2 := N3;
    	N2 := N1;
		END LOOP;
		RETURN N1;
    END IF;
END;
$$ LANGUAGE plpgsql;

-- function 2 declarations
 
CREATE OR REPLACE FUNCTION customer_order_rank (cust_ID INTEGER)
RETURNS int AS $$
DECLARE
   count_order INTEGER;
   rank_order INTEGER;
BEGIN
	SELECT COUNT(*) INTO count_order
	FROM orders o
	WHERE o.o_custkey = cust_ID;
	
	IF count_order = 0 THEN 
		RETURN 0;
	END IF;
	
	SELECT COUNT(*) + 1 INTO rank_order 
	FROM (
		SELECT o1.o_custkey, COUNT(*) AS counter
		FROM orders o1
		GROUP BY o1.o_custkey
	) AS order_count	
	WHERE order_count.counter > (SELECT COUNT(*) FROM orders WHERE o_custkey = cust_ID);
	
	RETURN rank_order;

END;
$$ LANGUAGE plpgsql;

-- function 3 declarations

CREATE OR REPLACE FUNCTION customer_balance_var (nation VARCHAR) RETURNS float AS $$
DECLARE
   key_nation INTEGER;
   customer_count INTEGER := 0;
   customer_bal_sum FLOAT := 0.0;
   mean_amt FLOAT := 0.0;
   balance FLOAT := 0.0;
BEGIN
	SELECT n.n_nationkey INTO key_nation
	FROM nation n
	WHERE UPPER(n.n_name) = UPPER(nation);
	
	IF key_nation IS NULL THEN 
		RETURN -1.0;
	END IF;
	
	SELECT SUM(c.c_acctbal), COUNT(*) INTO customer_bal_sum, customer_count
	FROM customer c
	WHERE c.c_nationkey = key_nation;
	
	IF customer_count > 0 THEN 
		mean_amt := customer_bal_sum / customer_count;
	END IF;
	
	SELECT AVG(POWER (c.c_acctbal - mean_amt,2)) INTO balance
	FROM customer c
	WHERE c.c_nationkey = key_nation;
	
	RETURN balance;
END;
$$ LANGUAGE plpgsql;




-- executing the above functions
select * from fibonacci(20);
select * from customer_order_rank (72);
select * from customer_balance_var ('CANADA');