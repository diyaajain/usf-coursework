#Runway length of highway

#Driver- Diya Jain U81673988
#Navigator- Zemar Robbins U03712676

import math

#inputing values for the speed and acceleration

speed = float(input("Enter the plane's take off speed in m/s: "))
acc = float(input("Enter the plane's acceleration in m/s**2: "))

#using the formula to calculate the runway length of the highway

length = ((speed**2)/(2*acc))

#printing the result

print('The minimum runway length needed for this airplane is', '{:,.4f}'.format(length))
