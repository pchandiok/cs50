import csv
from sys import argv, exit

def main():
    if len(argv) != 3:
        print("USAGE: python dna.py databases sequences")
        exit(1)
    
    MyList = []
    header = []
    result = {}
    seq = open(argv[2]).read()

    db = open(argv[1])
    db_reader = csv.reader(db)
    
    for dna_data in db_reader:
        MyList.append(dna_data)
   
    for item in MyList[0:1]:
        for i in item:
            header.append(i)

    header.pop(0)
    for item in header:
        counter = 0
        n = 1
        while (n <= len(seq)):
            x = seq.find(item, n, n+len(item))
            if x > 0:
                n = n + len(item)
                counter += 1
            else:
                n += 1
        result[item] = counter

    for key in result:
        print(f"{key} found {result[key]} times")

    

if __name__ == "__main__":
    main()
