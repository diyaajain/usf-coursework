#Name: Diya Jain
# U81673988
def centered_square(n):
    return 2 * (n ** 2) + 2 * n + 1
def centered_hexagonal(n):
    return 3 * (n ** 2) + 3 * n + 1
def centered_octagonal(n):
    return (2 * n + 1) ** 2
def centered_decagonal(n):
    return 5 * (n ** 2) + 5 * n + 1

def menu():
    print('Welcome to the Centered Polygonal Number program!')
    print("Here are you choices:")
    print("1.Centered Square Number")
    print("2.Centered Hexagonal Number")
    print("3.Centered Octagonal Number")
    print("4.Centered Decagonal Number")


def main():
    value = ""

    while value != 'no':
        menu()
        choice = int(input("Enter your choice (1 - 4):"))
        while choice < 1 or choice > 4:
            choice = int(input("Invalid entry. Re-enter your choice (1 -4): "))

        order_number = int(input("Enter an order number(>=1): "))

        while order_number < 1:
            order_number = int(input("Invalid entry. Re-enter your order number (>=1): "))

        answer = 0
        if choice == 1:
            answer = centered_square(order_number)
        elif choice == 2:
            answer = centered_hexagonal(order_number)
        elif choice == 3:
            answer = centered_octagonal(order_number)
        elif choice == 4:
            answer = centered_decagonal(order_number)

        print("The number in position", order_number , "series is: " + str(answer))

        value = input("Would you like to run the program again? Enter yes or no: ")

    print("Thanks for using this program! Goodbye!")


main()
