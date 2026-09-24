#Area of a Hexagon

#Driver- Zemar Robbins U03712676
#Navigator- Diya Jain U81673988

#importing the math module to solve the question

import math

#asking user for values

side = float(input("Enter the side length of the hexagon: "))

#solving the question

area = (3 * math.sqrt(3))/2 * (math.pow(side,2))

#displaying the results

print("The area of the hexagon with side length", side, "is" ,'{:.3f}'.format(area))
