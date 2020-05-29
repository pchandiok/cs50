from sys import argv
import csv

# checking no. of arguments
if len(argv) != 3:
    print("USAGE: python dna.py databases sequences")
    exit(1)

# Open Database file put it into memory
db = open(argv[1], "r")
db_reader = csv.reader(db, delimiter=",")
mydb = next(db_reader)
mydb.remove(mydb[0])

# Open Sequence File
seq = open(argv[2], "r")
sequencearray = seq.read()
seq.close()

inputSeqSTRCount = [0] * len(mydb)
inputSeqSTRLen = [0] * len(mydb)

for i in range(len(mydb)):
    cursor = 0
    str_count = 0
    inputSeqSTRCount[i] = 0
    inputSeqSTRLen[i] = len(mydb[i])

    while (cursor < len(sequencearray)):
        locatedAt = sequencearray.find(mydb[i], cursor) # Locating the position of the string

        if (locatedAt == cursor):
            str_count += 1                            # Counting the string occurrence        
            cursor += inputSeqSTRLen[i]                                 
            if str_count > inputSeqSTRCount[i]:
                inputSeqSTRCount[i] = str_count
        elif (locatedAt > cursor):                                      
            cursor = locatedAt
            str_count = 0
        elif locatedAt == -1:
            break

name = ""

# Searching database file for the name of the person with DNA sequence
for person in db_reader:
    match = True
    for i in range(1, len(person)):
        if int(person[i]) != inputSeqSTRCount[i - 1]:
            match  = False

    if match:
        name = person[0]

if name == "":
    print("No match")
else:
    print(name)