# TODO
import csv
from sys import argv, exit
from cs50 import SQL

def main():
    if len(argv) != 2:
        print("Usage: import.py <filename.csv>")
        exit(1)    

    characters = open(argv[1], "r")
    csv_reader = csv.reader(characters, delimiter=",")
    db = SQL("sqlite:///students.db")
    i=1
    for person in csv_reader:
        name = person[0].split(" ")
        if i>1:
            if len(name) == 2:
                (firstName, lastName) = name
                print(f"First Name: {firstName}\nLast Name: {lastName}")
                db.execute("insert into students (first, last, house, birth) values (?, ?, ?, ?)", firstName, lastName, person[1], person[2])
            elif len(name) == 3:
                (firstName, middleName, lastName) = name
                print(f"First Name: {firstName}\nMiddle Name: {middleName}\nLast Name: {lastName}")
                db.execute("insert into students (first, middle, last, house, birth) values (?, ?, ?, ?, ?)", firstName, middleName, lastName, person[1], person[2])
        i += 1
            

if __name__ == "__main__":
    main()
