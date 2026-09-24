/* One way to reverse a singly linked list is to use a recursive approach. 
Here's the general idea of the algorithm:
1.	Base case: If the list is empty or has only one node, return the list as it is.
2.	Recursive case: Reverse the rest of the list and make the first node as the last node of the reversed list.
Here's an implementation of the above algorithm in C++:*/

/* Name: Diya Jain
U81673988 */

#include <iostream>
struct Node {
    int data;
    Node* next;
    Node(int data) : data(data), next(nullptr) {}
};
Node* reverseList(Node* head) {
    if (!head || !head->next) {
        return head;
    }
    Node* rest = reverseList(head->next);
    head->next->next = head;
    head->next = nullptr;
    return rest;
}
int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head = reverseList(head);
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}
