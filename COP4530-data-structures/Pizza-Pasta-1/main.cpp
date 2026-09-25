/* This .cpp file is the driver of the program. 
This program implements a line in the italian restaurant that serves either pizza or pasta (depending on user declaration)

The user can choose to be a manager or customer: 
- Manager can give away orders, check the size of the line, and view order info of the front customer
- Customer can create a new order and check the size of the line

The main function includes menu options for each choice that the user might encounter

NOTE: Line 31: User has to declare the restaurant to have either Pasta or Pizza by putting the type PastaOrder or PizzaOrder (defined in classOrder.h)"
By default, it's defined as PastaOrder */

#include <iostream>
#include <cstdlib>
#include <limits>
#include <type_traits>
#include "classLine.h"
#include "classOrder.h"

char validateChoice();
using namespace std;

int main() {

    cout << "**************************" << endl;
    cout << "Welcome to Pasta&Pizza #1!" << endl;
    cout << "**************************" << endl;
    cout << endl;

    // Declare type either PizzaOrder or PastaOrder
    Line<PizzaOrder> newLine;

    // Printing a message depending on the previoius type declaration
    if (is_same<decltype(newLine), Line<PizzaOrder> >::value) {
        cout << "Today is a Pizza Day!" << endl;
    } else {
        cout << "Today is a Pasta Day!" << endl;
    }

    for (;;) {
        string role;
        cout << endl;
        cout << "Select your role:" << endl;
        cout << endl;
        cout << "1. Manager" << endl;
        cout << "2. Customer" << endl;
        cout << "3. Quit" << endl;
        cout << endl;
        
        cout << "Enter your choice (1, 2, or 3): ";
        cin >> role;

        if (role == "1") { // manager role
            char done = 'n';
            while (tolower(done) != 'y') {
                cout << endl;
                cout << "Choose one of the options: " << endl;
                cout << "1. Check how many customers are in the line." << endl;
                cout << "2. View order details of the current customer." << endl;
                cout << "3. Give away the order for the current customer." << endl;
                cout << endl;
                cout << "Enter your choice: ";
                char managerChoice;
                cin >> managerChoice;

                // if user did not input a character (i.e. string)
                if (cin.fail() || cin.peek() != '\n') {  // check if input is not a single character
                    cout << endl;
                    cout << "Invalid choice. Please try again. " << endl;
                    cin.clear();  // reset input stream state
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // clear input buffer
                    continue;
                }

                switch (managerChoice) {
                    case '1':  // handles checking the size of the line
                        cout << endl;
                        cout << "Number of people in line: " << newLine.size() << endl;
                        cout << endl;
                        done = validateChoice();
                        break;
                    case '2': // handles viewing front customer order info
                        cout << endl;
                        cout << "Here is the order of the current customer: " << endl;
                        newLine.getFront();
                        cout << endl;
                        done = validateChoice();
                        break;
                    case '3': // handles giving away the order
                        cout << endl;
                        if (newLine.empty()) {
                            cout << "There are no customers in the line!" << endl;
                            cout << endl;
                            done = validateChoice();
                            break;
                        }
                        cout << "Giving away the order for " << newLine.getFrontName() << "!";
                        newLine.dequeue();
                        cout << endl;
                        done = validateChoice();
                        break;
                    default:
                        cout << endl;
                        cout << "Invalid choice. Please try again.";
                        break;
                }
            }
        } else if (role == "2") { // customer role
            char done = 'n';
            while (tolower(done) != 'y') {
                cout << endl;
                cout << "Choose one of the options: " << endl;
                cout << "1. Place an order" << endl;
                cout << "2. Check how many customers are in the line" << endl;
                cout << endl;
                char customerChoice;
                cout << "Enter your choice: ";
                cin >> customerChoice; 

                // if user did not input a character (i.e. string)
                if (cin.fail() || cin.peek() != '\n') {  // check if input is not a single character
                    cout << "Invalid choice. Please try again. " << endl;
                    cin.clear();  // reset input stream state
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // clear input buffer
                    continue;
                }

                switch (customerChoice) {
                    case '1': // handles placing the order
                        cout << endl;
                        cout << "Let's get your order..." << endl;
                        cout << endl;
                        newLine.enqueue();
                        cout << endl;
                        done = validateChoice();
                        break;
                    case '2': // handles checking the size of the line
                        cout << endl;
                        cout << "Number of people in line: " << newLine.size() << endl;
                        cout << endl;
                        done = validateChoice();
                        break; 
                    default:
                        cout << endl;
                        cout << "Invalid choice. Please try again.";
                        break;
                }
            }
        } else if (role == "3") { // quit
            newLine.clear();
            cout << "See you soon!" << endl;
            return EXIT_SUCCESS;
        } else {
            cout << endl;
            cout << "Inavlid choice. Please try again.";
            cout << endl;
        }
    }
}

// validates done y/n input
char validateChoice() {
    char choice;
    bool validInput = false;

    while (!validInput) {
        cout << "Done (y/n)?: ";
        cin >> choice;

        // Check if input is a character
        if (cin.fail() || cin.get() != '\n' || (tolower(choice) != 'y' && tolower(choice) != 'n')) {
            cout << "Invalid input. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            validInput = true;
        }
    }

    return choice;
}