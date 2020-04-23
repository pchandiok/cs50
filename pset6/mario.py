import sys
from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height > 0 and height < 9:
        break

for j in range(height, 0, -1):
    for i in range(1, j, 1):
        print(" ", end="") 
    k = j
    while k != height+1:
        print("#", end="")
        k += 1
    print("  ", end="")
    k = j
    while k != height+1:
        print("#", end="")
        k += 1
    print()
