#Slope of the line

#Driver- Diya Jain U81673988
#Navigator- Zemar Robbins U03712676

#This program calculates the slope from the given points

#taking values from the user for the slope

p1 = float(input("Enter the x-coordinate for point1: "))
p2 = float(input("Enter the y-coordinate for point1: "))
p3 = float(input("Enter the x-coordinate for point2: "))
p4 = float(input("Enter the y-coordinate for point2: "))

#used formula to calculate the slope

slope= ((p4-p2)/(p3-p1))

#printing the values

print('The slope for the line that connects two points (',p1,',', p2,') and (',p3, ',', p4, ') is', '{:,.5f}'.format(slope))
