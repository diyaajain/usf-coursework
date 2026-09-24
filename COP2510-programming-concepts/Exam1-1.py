#Programming Exam 1
#Name- Diya Jain
#U81673988
#The following program determines if the two rectangles are within, overlapping or completely separate from each other.

#importing the math module

import math

#asking the user for inputs for the two rectangles

x1 = float(input("Enter rectangle 1's center x-coordinate: "))
y1 = float(input("Enter rectangle 1's center y-coordinate: "))
w1 = float(input("Enter rectangle 1's width: "))
h1 = float(input("Enter rectangle 1's height: "))
print('')
x2 = float(input("Enter rectangle 2's center x-coordinate: "))
y2 = float(input("Enter rectangle 2's center y-coordinate: "))
w2 = float(input("Enter rectangle 2's width: "))
h2 = float(input("Enter rectangle 2's height: "))

#using if-else statements to solve the problem

if math.fabs(x1-x2)<=(w1-w2)/2 and math.fabs(y1-y2)<=(h1-h2)/2: #used math.fabs()  
    print('')
    print("Rectangle 2 is inside Rectangle 1.")
elif math.fabs(x1-x2)<=(w1+w2)/2 and math.fabs(y1-y2)<=(h1+h2)/2:
    print('')
    print("Rectangle 2 overlaps Rectangle 1")
else:
    print('')
    print("Rectangle 2 does not overlap Rectangle 1.")
