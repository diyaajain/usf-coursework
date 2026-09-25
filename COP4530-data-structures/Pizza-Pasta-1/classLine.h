/* Queue implementation using Customers as nodes of the circularly linked list with front and rear pointers */

#ifndef CLASSLINE_H
#define CLASSLINE_H
#include <iostream>
#include <cstdlib>
#include <cctype>
#include "classCustomer.h"

using namespace std;

template <typename E>
class Line {
    private:
        Customer<E>* front;
        Customer<E>* rear;
        int n;
    public:
        // constructor
        Line() { 
            front = nullptr; 
            rear = nullptr; 
            n = 0; // stores current size
        }
        // destructor
        ~Line() {
            while (!empty()) {
                dequeue();
            }
            delete front;
            delete rear;
        }
        bool empty() const { return (n == 0); }
        void enqueue();
        void dequeue();
        void getFront();
        string getFrontName();
        void clear();
        int size();
        void modify(Customer<E>* newCustomer);
        bool phoneValidation(const string& phone);
        char validateCorrect();
        char validateChoice();
};   

// enqueue function to add new customers at the rear
template <typename E>
void Line<E>::enqueue() {
    Customer<E>* newCustomer = new Customer<E>();
    if (empty()) {
        front = newCustomer;
        rear = newCustomer;
        rear->next = front;
        cout << endl;
        cout << "Here is your order:" << endl;
        newCustomer->order->printOrder();
        n++;
        cout << endl;
        char correct = 'n';
        while (tolower(correct) != 'y') {
            correct = validateCorrect();
            while (tolower(correct) != 'n' && tolower(correct) != 'y') {
                cout << endl;
                correct = validateCorrect();
                cout << endl;
            }
            if (tolower(correct) == 'n') modify(newCustomer);
        }
        return;
    }
    rear->next = newCustomer;
    rear = newCustomer;
    rear->next = front;
    cout << "Here is your order:" << endl;
    newCustomer->order->printOrder();
    n++;
    cout << endl;
    char correct = validateCorrect();
    while (tolower(correct) != 'y') {
        correct = validateCorrect();
        while (tolower(correct) != 'n' && tolower(correct) != 'y') {
            cout << endl;
            correct = validateCorrect();
            cout << endl;
        }
        modify(newCustomer);
    }
    
}

// dequeue function to remove customers at the front
template <typename E>
void Line<E>::dequeue() {
    if (empty()) {
        cout << "Line has no customers!" << endl;
    } else if (front == rear) {
        delete front;
        front = nullptr;
        rear = nullptr;
        n--;
    } else {
        Customer<E>* temp = front;
        front = front->next;
        rear->next = front;
        delete temp;
        n--;
    }
}

// getFront function to print the order information of the front customer
// calls printOrder function defined in classOrder.h
template <typename E>
void Line<E>::getFront() {
    if (front == nullptr) {
        cout << "There are no customers in line!" << endl;
        return;
    }
    front->order->printOrder();
}

// gets the name of the front customer
template <typename E>
string Line<E>::getFrontName() {
    return front->order->getName();
}

// returns the number of people in the line
template <typename E>
int Line<E>::size() {
    return n;
}

// deletes all customers
template <typename E>
void Line<E>::clear() {
    if (empty()) {
        return;
    }
    else {
        Customer<E>* cur = front;
        while (cur != rear) {
            Customer<E>* temp = cur;
            cur = cur->next;
        }
        front = nullptr;
        rear = nullptr;
    }
}

// modifies information about the order
template <typename E>
void Line<E>::modify(Customer<E>* newCustomer) {
    cout << endl;
    cout << "What would you like to change?" << endl;
    cout << "1. Name" << endl;
    cout << "2. Phone number" << endl;
    cout << "3. Order details" << endl;
    cout << "4. Cancel" << endl;
    cout << endl;
    char choice = validateChoice();
    if (choice == '1') {
        cout << endl;
        string newName;
        cout << "Enter your new name: ";
        getline(cin, newName);
        newCustomer->order->setName(newName);
        cout << endl;
        cout << "Name changed succesfully!" << endl;
        newCustomer->order->printOrder();
        cout << endl;
    } else if (choice == '2') {
        cout << endl;
        string newPhone;
        cout << "Enter your new phone number: ";
        getline(cin, newPhone);
        while (!phoneValidation(newPhone)) {
            cout << "Invalid format. Please re-enter your phone: ";
            getline(cin, newPhone);
        }
        newCustomer->order->setPhone(newPhone);
        cout << endl;
        cout << "Phone number changed succesfully!" << endl;
        newCustomer->order->printOrder();
        cout << endl;
    } else if (choice == '3') {
        cout << endl;
        newCustomer->order->changeOrder();
        cout << endl;
    } else {
        newCustomer->order->printOrder();
        cout << endl;
    }
}

// validates phone number input
template <typename E>
bool Line<E>::phoneValidation(const string& phone) {
    // check the length of the string
    if (phone.length() != 10 && phone.length() != 12) {
        return 0;
    }
    
    int count = 0;

    // loop through the string and check each character
    for (int i = 0; i < phone.length(); i++) {
        char ch = phone[i];
        if (isdigit(ch)) {
            count++;
        }
        else if (ch != '-' && ch != '.'&& !(isdigit(ch))) {
            return 0;
        }
        // check the positions of the hyphens and dots
        if (i == 3 || i == 7) {
            if (ch != '-' && ch != '.' && !(isdigit(ch))) {
                return 0;
            }
        }
    }
    // check the number of digits
    if (count != 10) {
        return 0;
    }

    return 1;
}

// validates whether the y/n is correctly inputted
template <typename E>
char Line<E>::validateCorrect() {
    char choice;
    bool validInput = false;

    while (!validInput) {
        cout << "Is the order correct (y/n)?: ";
        cin >> choice;

        // Check if input is a character
        if (cin.fail() || cin.get() != '\n') {
            cout << "Invalid input! Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            validInput = true;
        }
    }

    return choice;
}

// validates the choice type (should be char)
template <typename E>
char Line<E>::validateChoice() {
    char choice;
    bool validInput = false;

    while (!validInput) {
        cout << "Enter your choice: ";
        cin >> choice;

        // Check if input is a character
        if (cin.fail() || cin.get() != '\n') {
            cout << "Invalid input! Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            validInput = true;
        }
    }

    return choice;
}
#endif