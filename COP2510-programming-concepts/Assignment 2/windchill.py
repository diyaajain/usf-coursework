#Driver- David Hamilton U69189166
#Navigator- Diya Jain U81673988
#Wind-Chill Temperature

#Calculates wind chill index after valid input is inputted

import math

#asks for temp input

ta=float(input("Enter the temperature in Fahrenheit: "))

#validates input to be between specified values

while(ta>=41 or ta<=-58): 
    print("Temperature must be between -58F and 41F")
    ta= float(input("Please re-enter the temperature in Fahrenheit: "))
    
#asks for speed input
    
v=float(input("Enter the wind speed miles per hour: "))

#validates speed input

while(v<2):
    print("Speed must be greater than or equal to 2")
    v= float(input("Please re-enter the wind speed miles per hour: "))
    
#calculates wind chill index
    
twc= 35.74+.6215*ta-35.75*math.pow(v,.16)+.4275*ta*math.pow(v,.16)

#prints value to screen

print("The wind chill index is","%.3f"%twc)
