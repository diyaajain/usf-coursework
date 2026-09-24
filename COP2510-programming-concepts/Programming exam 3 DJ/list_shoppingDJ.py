# Name- Diya Jain
# U81673988
# This program is the class definition module for calculating the total cost.
class list_shoppingDJ:
    def __init__(self, name,amount):
        self.__name = name
        self.__amount=amount
        self.__price_per_pound=0 #kept the standard price as price per pound
        self.__PriceList_DJ()
        self.price=self.calculatedprice_DJ()

    # the method that has the price of the items per pound
    def __PriceList_DJ(self):
        if self.__name=='Dry Cured Iberian Ham':
            self.__price_per_pound= 177.80
        elif self.__name=='Wagyu Steaks':
            self.__price_per_pound= 450.00
        elif self.__name=='Matsutake Mushrooms':
            self.__price_per_pound= 272.00
        elif self.__name=='Kopi Luwak Coffee':
            self.__price_per_pound= 317.50
        elif self.__name=='Moose Cheese':
            self.__price_per_pound= 487.20
        elif self.__name=='White Truffles':
            self.__price_per_pound= 3600.00
        elif self.__name=='Blue Fin Tuna':
            self.__price_per_pound= 3603.00
        elif self.__name=='Le Bonnotte Potatoes':
            self.__price_per_pound= 270.81
        else:
            self.__price_per_pound= 0.00

    # the method that calculates the total price and returns it.
    def calculatedprice_DJ(self):
        return (self.__amount*self.__price_per_pound)
    
    # the method that gets the name
    def get_Name(self):
        return self.__name
    
    # the method that gets the amount
    def get_Amount(self):
        return self.__amount
    
    # accessors 
    def __str__(self):

        return "Item: % s\nAmount Ordered:%.1f pounds\nPrice per pound:$%.2f\nPrice of order:$%.2f" % (self.__name, self.__amount,self.__price_per_pound,self.price)
