#Driver- Diya Jain U81673988
#Navigator- David Hamilton U69189166

#Calculates the perimeter of the triangle

#asking the user the input values
edge1 = float(input("Enter the length of edge1: "))
edge2 = float(input("Enter the length of edge2: "))
edge3 = float(input("Enter the length of edge3: "))

#using the formula to calculate the perimeter

perimeter = edge1+edge2+edge3

#used the logic that sum of the sides should be greater than the third side

edge12 = edge1 + edge2
edge23 = edge2 + edge3
edge31 = edge3 + edge1

#used if loop for the above logic and then printing that the input is invalid

if (edge1> edge23 or edge2> edge31 or edge3> edge12):
    print("Perimeter cannot be calculated: the input is invalid.")
else:
    print("The perimeter is ",perimeter) 
