#Assignment 7: Retail Items

#Driver: James Victor Santos Alejandro (U45145495)

#Navigator: Diya Jain (U81673988)

#Desc: This program displays the different items in an retail store, and along with it, detailed information such as the
#type of item, how many of the item there are, and price of the item
#also displays this information in both simple phrases, and through a table



#Class definition of Retail_Item 
class Retail_Item:
    #initialization that uses type of item, amount of item, and item price as parameters
    def __init__(self, itemType, itemAmount, itemPrice):
        self.__itemType = itemType
        self.__itemAmount = itemAmount
        self.__itemPrice =  itemPrice
    
    #setter method to change item type/name
    def setType(self,itemType):
        self.__itemType = itemType
    
    #getter method to obtain item type/name
    def getType(self):
        return self.__itemType
    
    #setter method to change amount of item
    def setAmount(self):
        self.__itemAmount = itemAmount
    
    #getter method to obtain amount of item
    def getAmount(self):
        return self.__itemAmount
    
    #setter method to change item price
    def setItemPrice(self, itemPrice):
        self.__itemPrice = itemPrice
    
    #getter method to obtain item price
    def getItemPrice(self):
        return self.__itemPrice
    
    #__str__ method that is used to format the table to display the different items
    def __str__(self):
        return "{name:<20}".format(name = self.__itemType)+"{qty:<10}".format(qty = self.__itemAmount)+"{price:>11}"\
              .format(price = "$"+ str(self.__itemPrice))
        
        
#main function that stores the key operations of the program
def main():
    #ask for user input
    item1Name = input("Name of item 1: ")
    item1Amount = input("Amount of item 1: ")
    item1Price = input("Price of item 1: ")
    print()
    item2Name = input("Name of item 2: ")
    item2Amount = input("Amount of item 2:")
    item2Price = input("Price of item 2: ")
    
    #defines two instances of the class Retail_Item, from given user input
    item1 = Retail_Item(item1Name, item1Amount, item1Price)
    item2 = Retail_Item(item2Name, item2Amount, item2Price)

    #upper portion of the table that displays the column names, and the divider between names and information about retail items
    print("Here us a summary of the items you added:")
    print("{x:<20}".format(x="Item")+"{y:<10}".format(y="Amount")+"{z:>11}".format(z="Price"))
    print("-" * 41)
    
    #uses __str__ method of the two different variables of the Retail_Item class to display the items in the aforementioned table  
    print(item1)
    print(item2)
    

#function call to main
main()

