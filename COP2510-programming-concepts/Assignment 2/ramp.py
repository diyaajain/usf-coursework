#Driver- Diya Jain U81673988
#Navigator- David Hamilton U69189166

#This program finds the angle of the ramp

#importaing the math module

import math

#defining the value of g 

g=9.8

#asking user for inputs

mass = float(input("Enter the mass of the cart (in kg): "))
force = float(input("Enter the force to push the cart (in N): "))

#using the given formula to find the angle

angle = math.asin(force/(mass * g))

#changing radians into degrees

angle = angle*180/math.pi

#printing the values 

print("The angle of the ramp is", '{:,.1f}'.format(angle), "degrees")
