# Welcome to Pizza & Pasta #1!
## The best italian restaurant in Tampa, FL

#### This is a project for COP 4530 Data Structures. The program implements a Queue using templated circularly linked list. 

#### Project files:

1. "classCustomer.h" contains class definition for a node of the list.

2. "classOrder.h" contains class definitions for two types of orders: Pizza or Pasta, and an abstract parent class Order.

3. "classLine.h" contains the implementation of the queue, which includes dequeue(), enqueue(), size(), front(), empty().

4. "main.cpp" provides the menu options for the user.

The user has to be one of the two roles: manager or customer.

Manager roles:
* Give away current customer's order (dequeue)
* Check the number of customers in line (size)
* View order information of the current customer (front)

Customer roles:
* Place an order to get in the line (enqueue)
* Check the number of customers in line (size)

