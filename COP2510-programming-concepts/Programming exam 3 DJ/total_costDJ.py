#Name- Diya Jain
#U81673988
#This program displays the list of items purchased and also gives the calculated cost for the items.

# importing the class module
from list_shoppingDJ import list_shoppingDJ

# asking the user to input the purchase items.
def listofitems_DJ():
    purchase=[]
    while True:
        number=int(input("How many items will you order today? "))
        if number<=0:
            print("Number of items must be atleast 1.")
        else:
            break
        
    # loop for the items purchased
    for i in range(0,number):
        print("Item #",(i+1),"-")
        name=input("Enter food:")
        while True:
            amount=float(input("Enter amount of pounds: "))
            if amount<=0:
                print("Amount of pounds must be greater than 0.")
            else:
                break
        purchase.append(list_shoppingDJ(name,amount))
        print("\n")
    return purchase

# displaying the list of the items which were entered
def itemsdisplayed_DJ(item_bought):
    print("Here's a summary of the items purchased:\n---------------------------------------")
    for b in item_bought:
        print(b)
        print("\n")

# calculating the total cost of the items which were entered
def totalcost_DJ(item_bought):
    totalCost=0
    for b in item_bought:
        totalCost+=b.calculatedprice_DJ()
    return totalCost

# the main function is calling the other three functions
def main():
    item_bought=listofitems_DJ()
    itemsdisplayed_DJ(item_bought)
    total=totalcost_DJ(item_bought)
    print(f'Total cost:$ {total:.2f}')

# calling of the main function
main()
