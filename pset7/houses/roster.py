from cs50 import SQL
from sys import argv, exit

def main():
    if len(argv) != 2:
        print("USAGE: roster.py <house name>")
        exit(1)

    db = SQL("sqlite:///students.db")
    rows = db.execute("select first, middle, last, birth from students where house = ? group by first order by last", argv[1])
    for row in rows:
        if row['middle'] == None:
            print(f"{row['first']} {row['last']}, born {row['birth']}")
        else:
            print(f"{row['first']} {row['middle']} {row['last']}, born {row['birth']}")
if __name__ == "__main__":
    main()

