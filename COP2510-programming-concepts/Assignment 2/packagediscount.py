#Driver- David Hamilton U69189166
#Navigator- Diya Jain U81673988
#Software Sales
#Program asks for amount of packages purchased, then calculates and displays discount

#amount input

packageAmount=int(input("Enter the number of packages purchased: "))

#check for discounts

discountPercent=0
if(packageAmount>=100):
    discountPercent=.4
elif(packageAmount>=50):
    discountPercent=.3
elif(packageAmount>=20):
    discountPercent=.2
elif(packageAmount>=10):
    discountPercent=.1
    
#cost without discount
    
cost=packageAmount*99

#discount recieved

discount=discountPercent*cost

#final cost which is discount + the cost

cost= cost-discount

#displays requested output formatted correctly

print("Discount Amount @{:.0%}".format(discountPercent),":${:.2f}".format(discount))
print("Total Amount: ${:.2f}".format(cost))
