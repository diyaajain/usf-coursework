#Assignment 7: Create a Pet Class and object

#Driver: Diya Jain (U81673988)

#Navigator: James Victor Santos Alejandro (U45145495)

#Desc: This program displays infromation about a pet, by default it does not have any values, so the user inputs
#their own values that is then displayed afterwards

#class Pet that houses the methods and attributes of Pet
class Pet:
    #initializer method with name, type, and age and default values
    def __init__(self):
        self.__name = "Not provided"
        self.__petType = "Not provided"
        self.__petAge = 0
    
    #setter method for name
    def setName(self,name):
        self.__name = name
    
    #getter method for name
    def getName(self):
        return self.__name 
    
    #setter method for type of pet
    def setType(self,petType):
        self.__petType = petType
    
    #getter method for type of pet
    def getType(self):
        return self.__petType 
    
    #setter method for pet age
    def setAge(self,petAge):
        self.__petAge = petAge
    
    #getter method for pet age
    def getAge(self):
        return self.__petAge 
    
    
#main method that stores the program 
def main():
    #class call to Pet assigned to var petInfo
    petInfo = Pet()
    
    #displays the default values to the user and tells user we are going to change the information
    print("A pet object has been createdd. Here is the initial information about the pet: ")
    print("Name of pet:", petInfo.getName(),"\nType of pet:", petInfo.getType(), "\nAge of pet:", petInfo.getAge())
    print("Let's update the information for a pet!")
    
    #asks user to input values for new pet, type of pet, and age of pet
    petName = str(input("Enter the pet's name: "))
    petType = str(input("Enter the type of animal: "))
    petAge = str(input("enter the pet's age: "))
    
    #calls for setter methods for the name, type, and pet age to change the value of the different attributes
    petInfo.setName(petName)
    petInfo.setType(petType)
    petInfo.setAge(petAge)
    
    #displays updated information about the pet using the getter methods of the Pet class
    print("Here is the updated information about the pet:")
    print("Name of pet: {} \nType of pet: {}\nAge of pet: {}".format(petInfo.getName() ,petInfo.getType() ,petInfo.getAge()))
    
    
#function call for main    
main()
    
