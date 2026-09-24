#Pair Programming

#Driver : Fibi Shoukry (U43930747)
#Navigator : Diya Jain (U81673988)

#This program calculates the total sales of the week and indicates the minimum and maximum sales amount of the week.

weekdays = ('Sunday','Monday','Tuesday','Wednesday','Thursday','Friday','Saturday')


sales_per_day = []
for i in weekdays:
    isTrue = True
    print("Enter the sales for {}: ".format(i), end='')
    while isTrue:
        # getting the input amount of sales for one day
        sales = int(input())
        if sales>0:
            # if the amount of sales is over zero, add that to the sales per week list
            sales_per_day.append(sales)
            isTrue=False
        else:
            print("Input was invalid. Re-enter the sales for {}: ".format(i), end='')
# the base values for the three variables
totalsales = 0
max = sales_per_day[0]
min = sales_per_day[0]

# selecting values of of sales for each day and adding them into total sales
# finding max and min values
for i in sales_per_day:
    totalsales += i
    if max<i:
        max = i
    if min>i:
        min = i

# printing the values of the total sales and the maximum and minimun values 
print("The total sales is:${:,.2f}".format(totalsales))
print("The minimum sale amount was:${:,.2f}".format(min))
print("The maximum sale amount was:${:,.2f}".format(max))

