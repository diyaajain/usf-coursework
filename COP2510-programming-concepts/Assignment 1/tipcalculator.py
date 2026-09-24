#Tip calculator

#Driver- Zemar Robbins U03712676
#Navigator- Diya Jain U81673988

#This program calulates the subtotal and gratuity rate.

#Input the values 

subtotal= float(input("Enter the subtotal: $ "))
tip= float(input("Enter tip amount (as a %): "))

#calculating the values of the tips and the total

tips= (subtotal*tip)/100
total= subtotal+tips

#printing out the values

print("Subtotal: $ ", '{:,.2f}'.format(subtotal))
print("Tip: $ ", '{:,.2f}'.format(tips))
print("Total: $ ", '{:,.2f}'.format(total))

