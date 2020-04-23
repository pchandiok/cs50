from cs50 import get_float

change = 0

#Confirming, user inputs only positive numbers

while change <= 0:
    amount = get_float("Change owed: ")
    change = round(amount * 100)

# It converts the change into no. of Quarters
quarters = change // 25

# It converts the change into no. of Dimes
dimes = (change % 25) // 10

# It converts the change into no. of Nickels
nickels = ((change % 25) % 10) // 5

# It converts the change into no. of Pennies
pennies = ((change % 25) % 10 ) % 5


print(round(quarters + dimes + nickels + pennies))