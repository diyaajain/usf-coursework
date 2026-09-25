/* This .cpp file includes function definitions and constructors for the Order class as well as its subclasses
*/ 
#include "classOrder.h"
#include <iostream>
#include <string>

// Constructor for Order 
Order::Order() {
    cin.ignore();
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your phone number: ";
    getline(cin, phone);
    while (!phoneValidation(phone)) {
        cout << "Invalid format. Please re-enter your phone: ";
        getline(cin, phone);
    }
    cout << "Nice to meet you, " << name << "!" << endl;
    cout << "Would you like a fountain drink (y/n)?: ";
    string choice;
    getline(cin, choice);
    if (choice == "y") {
        drink = 1;
    } else if (choice == "n") {
        drink = 0;
    }
    while (choice != "y" && choice != "n") {
        cout << "Invalid choice. Please enter 'y' or 'n': ";
        cin >> choice;
        if (choice == "y") {
        drink = 1;
        } else if (choice == "n") {
            drink = 0;
        }
    }
    total = 0;
}

// validates the user entered phone number
// valid formats: XXXXXXXXXX, XXX-XXX-XXXX, XXX.XXX.XXXX
bool Order::phoneValidation(const string& phone) {
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

// getting and validating choice
char Order::validateChoice() {
    char choice;
    bool validInput = false;

    while (!validInput) {
        cout << "Enter your choice: ";
        cin >> choice;

        // Check if input is a character
        if (cin.fail() || cin.get() != '\n') {
            cout << "Invalid choice. Please try again." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else {
            validInput = true;
        }
    }

    return choice;
}

// Constructor for PizzaOrder
PizzaOrder::PizzaOrder() : Order() {
    // inputting pizza type
    bool valid = 0;
    while (!valid) {
        cout << endl;
        cout << "Choose pizza type:" << endl;
        cout << "1. Margherita ($12)" << endl;
        cout << "2. Pepperoni ($13)" << endl;
        cout << "3. Cheese ($14)" << endl;
        cout << "4. Vegeterian ($13)" << endl;
        cout << "5. BBQ Chicken ($16)" << endl;
        cout << endl;
        char pizzaChoice = validateChoice();
        // swtich statement to calculate total and assign type
        switch (pizzaChoice) {
            case '1':   total += Margherita;
                        type = Margherita;
                        valid = 1;
                        break;
            case '2':   total += Pepperoni;
                        type = Pepperoni;
                        valid = 1;
                        break;
            case '3':   total += Cheese;
                        type = Cheese;
                        valid = 1;
                        break;
            case '4':   total += Vegetarian;
                        type = Vegetarian;
                        valid = 1;
                        break;
            case '5':   total += BBQChicken;
                        type = BBQChicken;
                        valid = 1;
                        break;
            default:    cout << "Invalid choice. Please try again. " << endl;
                        break;
        }
    }
    cout << endl;
    cout << "Wonderful choice, " << name << "!" << endl;
    // inputting size
    valid = 0;
    while (!valid) {
        cout << endl;
        cout << "Let's choose the size:" << endl;
        cout << "1. 14\" (+$0)" << endl;
        cout << "2. 16\" (+$2)" << endl;
        cout << "3. 18\" (+$4)" << endl;
        cout << endl;
        char sizeChoice = validateChoice();
        switch (sizeChoice) {
            case '1':   size = 14;
                        valid = 1;
                        break;
            case '2':   size = 16;
                        total += 2.0;
                        valid = 1;
                        break;
            case '3':   size = 18;
                        total += 4.0;
                        valid = 1;
                        break;
            default:    cout << "Invalid choice. Please try again. " << endl;
                        break;
        }
    }
    cout << endl;
    cout << "Great choice, " << name << "!" << endl;
    // inputting crust
    valid = 0;
    while (!valid) {
        cout << endl;
        cout << "Now, choose the crust:" << endl;
        cout << "1. Thin (+$0)" << endl;
        cout << "2. Thick (+$1)" << endl;
        cout << "3. Stuffed (+$2)" << endl;
        cout << endl;
        char crustChoice = validateChoice();
        switch (crustChoice) {
            case '1':   crust = thin;
                        valid = 1;
                        break;
            case '2':   size = thick;
                        total += thick;
                        valid = 1;
                        break;
            case '3':   size = stuffed;
                        total += stuffed;
                        valid = 1;
                        break;
            default:    cout << "Invalid choice. Please try again. " << endl;
                        break;
        }
    }
    cout << endl;
    cout << "You're all set! Thanks for your order!" << endl;
}

// Function to print the pizza order, overrides the function in the parent class
void PizzaOrder::printOrder() {
    cout << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Drink: ";
    if (drink == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    cout << "Pizza Type: ";
    if (type == 11) {
        cout << "Vegetarian" << endl;
    } else if (type == 12) {
        cout << "Margherita" << endl;
    } else if (type == 13) {
        cout << "Pepperoni" << endl;
    } else if (type == 14) {
        cout << "Cheese" << endl;
    } else if (type == 16) {
        cout << "BBQ Chicken" << endl;
    }
    cout << "Size: " << size << endl;
    cout << "Crust: ";
    if (crust == 0) {
        cout << "Thin" << endl;
    } else if (crust == 1) {
        cout << "Thick" << endl;
    } else if (crust == 2) {
        cout << "Stuffed" << endl;
    }
    cout << "Total: $" << total << endl;
}

// Function to change the pizza order
void PizzaOrder::changeOrder() {
    cout << endl;
    cout << "What would you like to modify?" << endl;
    cout << "1. Change pizza type" << endl;
    cout << "2. Change size" << endl;
    cout << "3. Change crust" << endl;
    cout << "4. Cancel" << endl;
    cout << endl;
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;
    while (choice != "1" && choice != "2" && choice != "3" && choice != "4") {
        cout << "Invalid choice. Please enter again: ";
        cin >> choice;
    }
    bool valid = 0;
    if (choice == "1") {
        while (!valid) {
            cout << endl;
            cout << "Choose new pizza type:" << endl;
            cout << "1. Margherita ($12)" << endl;
            cout << "2. Pepperoni ($13)" << endl;
            cout << "3. Cheese ($14)" << endl;
            cout << "4. Vegeterian ($13)" << endl;
            cout << "5. BBQ Chicken ($16)" << endl;
            cout << endl;
            char pizzaChoice = validateChoice();

            // swtich statement to calculate total and assign type
            switch (pizzaChoice) {
                case '1':   total -= type;
                            total += Margherita;
                            type = Margherita;
                            valid = 1;
                            break;
                case '2':   total -= type;
                            total += Pepperoni;
                            type = Pepperoni;
                            valid = 1;
                            break;
                case '3':   total -= type;
                            total += Cheese;
                            type = Cheese;
                            valid = 1;
                            break;
                case '4':   total -= type;
                            total += Vegetarian;
                            type = Vegetarian;
                            valid = 1;
                            break;
                case 5:   total -= type;
                            total += BBQChicken;
                            type = BBQChicken;
                            valid = 1;
                            break;
                default:    cout << "Invalid choice. Please try again. " << endl;
                            break;
            }
        }
        cout << endl;
        cout << "Pizza type changed successfully!" << endl;
    }
    else if (choice == "2") {
        while (!valid) {
            cout << endl;
            cout << "Let's choose the size:" << endl;
            cout << "1. 14\" (+$0)" << endl;
            cout << "2. 16\" (+$2)" << endl;
            cout << "3. 18\" (+$4)" << endl;
            cout << endl;
            char sizeChoice = validateChoice();
            switch (sizeChoice) {
                case '1':   size = 14;
                            total -= size;
                            valid = 1;
                            break;
                case '2':   size = 16;
                            total -= size;
                            total += 2.0;
                            valid = 1;
                            break;
                case '3':   size = 18;
                            total -= size;
                            total += 4.0;
                            valid = 1;
                            break;
                default:    cout << "Invalid choice. Please try again. " << endl;
                            break;
            }
        }
        cout << endl;
        cout << "Pizza size changed successfully!" << endl;
    }
    else if (choice == "3") {
        while (!valid) {
            cout << endl;
            cout << "Now, choose the crust:" << endl;
            cout << "1. Thin (+$0)" << endl;
            cout << "2. Thick (+$1)" << endl;
            cout << "3. Stuffed (+$2)" << endl;
            cout << endl;
            char crustChoice = validateChoice();
            switch (crustChoice) {
                case '1':   crust = thin;
                            total -= crust;
                            valid = 1;
                            break;
                case '2':   crust = thick;
                            total -= crust;
                            total += thick;
                            valid = 1;
                            break;
                case '3':   crust = stuffed;
                            total -= crust;
                            total += stuffed;
                            valid = 1;
                            break;
                default:    cout << "Invalid choice. Please try again. " << endl;
                            break;
            }
        }
        cout << endl;
        cout << "Crust type changed successfully!" << endl;
    }
    else {
        return;
    }
}

// Constructor for PastaOrder
PastaOrder::PastaOrder() : Order() {
    // inputting pasta type
    bool valid = 0;
    while (!valid) {
        cout << endl;
        cout << "Choose pasta type:" << endl;
        cout << "1. Spaghetti ($10)" << endl;
        cout << "2. Fettuccine ($11)" << endl;
        cout << "3. Penne ($12)" << endl;
        cout << "4. Linguine ($13)" << endl;
        cout << endl;
        char pastaChoice = validateChoice();
        // swtich statement to calculate total and assign type
        switch (pastaChoice) {
            case '1':   total += Spaghetti;
                        type = Spaghetti;
                        valid = 1;
                        break;
            case '2':   total += Fettuccine;
                        type = Fettuccine;
                        valid = 1;
                        break;
            case '3':   total += Penne;
                        type = Penne;
                        valid = 1;
                        break;
            case '4':   total += Linguine;
                        type = Linguine;
                        valid = 1;
                        break;
            default:    cout << "Invalid choice. Please try again. " << endl;
                        break;
        }
    }
    cout << endl;
    cout << "Good choice, " << name << "!" << endl;
    // inputting extras
    withChicken = false;
    withShrimp = false;
    withMushroom = false;
    valid = 0;
    while (!valid) {
        cout << endl;
        cout << "Would you like extras in your pasta?" << endl;
        cout << "1. Chicken (+$3)" << endl;
        cout << "2. Shrimp (+$4)" << endl;
        cout << "3. Mushroom (+$2)" << endl;
        cout << "4. None" << endl;
        cout << endl;
        char extraChoice = validateChoice();
        switch (extraChoice) {
            case '1':   total += 3.0;
                        withChicken = true;
                        valid = 1;
                        break;
            case '2':   total += 4.0;
                        withShrimp = true;
                        valid = 1;
                        break;
            case '3':   total += 2.0;
                        withMushroom = true;
                        valid = 1;
                        break;
            case '4':   valid = 1;
                        break;
            default:    cout << "Invalid choice. Please try again. " << endl;
                        break;
        }
    }
    cout << endl;
}

// Function to print the pasta order, overrides the function in the parent class
void PastaOrder::printOrder() {
    cout << endl;
    cout << "Name: " << name << endl;
    cout << "Phone: " << phone << endl;
    cout << "Drink: ";
    if (drink == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    cout << "Pasta Type: ";
    if (type == 10) {
        cout << "Spaghetti" << endl;
    } else if (type == 11) {
        cout << "Fettuccine" << endl;
    } else if (type == 12) {
        cout << "Penne" << endl;
    } else if (type == 13) {
        cout << "Linguine" << endl;
    }
    cout << "Extras: ";
    if (withChicken) {
        cout << "Chicken" << endl;
    } else if (withShrimp) {
        cout << "Shrimp" << endl;
    } else if (withMushroom) {
        cout << "Mushrooms" << endl;
    } else {
        cout << "None" << endl;
    }
    cout << "Total: $" << total << endl;
}

// Function to change the Pasta order
void PastaOrder::changeOrder() {
    cout << endl;
    cout << "What would you like to modify?" << endl;
    cout << "1. Change pasta type" << endl;
    cout << "2. Remove extras" << endl;
    cout << "3. Change to chicken (+$3)" << endl;
    cout << "4. Change to shrimp shrimp (+$4)" << endl;
    cout << "5. Change to mushrooms (+$2)" << endl;
    cout << "6. Cancel" << endl;
    cout << endl;
    string choice;
    cout << "Enter your choice: ";
    cin >> choice;
    while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5" && choice != "6") {
        cout << "Invalid choice. Please enter again: ";
        cin >> choice;
    }
    if (choice == "1") {
        bool valid = 0;
        while (!valid) {
            cout << endl;
            cout << "Choose pasta type:" << endl;
            cout << "1. Spaghetti ($10)" << endl;
            cout << "2. Fettuccine ($11)" << endl;
            cout << "3. Penne ($12)" << endl;
            cout << "4. Linguine ($13)" << endl;
            cout << endl;
            char pastaChoice = validateChoice();
            // swtich statement to change total and assign new type
            switch (pastaChoice) {
                case '1':   total -= type;
                            total += Spaghetti;
                            type = Spaghetti;
                            valid = 1;
                            break;
                case '2':   total -= type;
                            total += Fettuccine;
                            type = Fettuccine;
                            valid = 1;
                            break;
                case '3':   total -= type;
                            total += Penne;
                            type = Penne;
                            valid = 1;
                            break;
                case '4':   total -= type;
                            total += Linguine;
                            type = Linguine;
                            valid = 1;
                            break;
                default:    cout << "Invalid choice. Please try again. " << endl;
                            break;
            }
        }
        cout << endl;
        cout << "Good choice, " << name << "!" << endl;
        cout << endl;
        cout << "Here is your order:" << endl;
        printOrder();
    } else if (choice == "2") {
        withChicken = 0;
        withShrimp = 0;
        withMushroom = 0;
        total = type;
        cout << endl;
        cout << "Here is your order:" << endl;
        printOrder();
    } else if (choice == "3") {
        withChicken = 1;
        withMushroom = 0;
        withShrimp = 0;
        total = type;
        total += 3;
        cout << endl;
        cout << "Here is your order:" << endl;
        printOrder();
    } else if (choice == "4") {
        withChicken = 0;
        withMushroom = 0;
        withShrimp = 1;
        total = type;
        total += 4;
        cout << endl;
        cout << "Here is your order:" << endl;
        printOrder();
    } else if (choice == "5") {
        withChicken = 0;
        withShrimp = 0;
        withMushroom = 1;
        total = type;
        total += 2;
        cout << endl;
        cout << "Here is your order:" << endl;
        printOrder();
    } else {
        cout << endl;
        cout << "Here is your order:" << endl;
        printOrder();
    }
}