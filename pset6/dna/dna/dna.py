#IMPORT TOOLS
from sys import argv
import csv


#TAKE CL ARGUMENTS
databaseArg = argv[1]
inputSeqArg = argv[2]


#DEBUG
#print(f"second CLI is {argv[2]}")


#OPEN DATABASE FILE AND READ IN STRS
dbfile = open(databaseArg, "r")
dbarray = csv.reader(dbfile, delimiter=",")
dbstrs = next(dbarray)
# dbfile.close()
dbstrs.remove(dbstrs[0]) #remove name string


#DEBUG
#for header in dbstrs:
    #print(f"{header}")
#for row in dbarray:
    #print("new row test dbarray")


#OPEN INPUT SEQUENCE AND READ IN STRING
inseqfile = open(inputSeqArg, "r")
sequencearray = inseqfile.read()
inseqfile.close()

inputSeqSTRCount = [0] * len(dbstrs)
inputSeqSTRLen = [0] * len(dbstrs)



#SEARCH INPUT FOR DATABASES STRS
for i in range(len(dbstrs)): #iterate through database STRs
    cursor = 0
    consecutiveSTRCount = 0
    inputSeqSTRCount[i] = 0
    inputSeqSTRLen[i] = len(dbstrs[i])

    while (cursor < len(sequencearray)):                                #while cursor isn't at end of sequence array
        locatedAt = sequencearray.find(dbstrs[i], cursor)

        if (locatedAt == cursor):                                       #if sequencearray.find(singleSTR,cursor) == cursor (locates singleSTR at cursor)
            consecutiveSTRCount += 1                                    #increment consecutive STR count
            cursor += inputSeqSTRLen[i]                                 #move cursor forward length of STR
            if consecutiveSTRCount > inputSeqSTRCount[i]:
                inputSeqSTRCount[i] = consecutiveSTRCount
        elif (locatedAt > cursor):                                      #STR not found at cursor
            cursor = locatedAt                                          #move cursor to newest index its found at
            consecutiveSTRCount = 0
        elif locatedAt == -1:
            break




matching_person = ""
for person in dbarray:
    #print(person)
    match = True
    for i in range(1, len(person)):
        if int(person[i]) != inputSeqSTRCount[i - 1]:
            match  = False

    if match:
        matching_person = person[0]

if matching_person == "":
    print("No match")
else:
#print("MATCH")
    print(matching_person)


#DECIDE ON MATCH (OR NO MATCH)


#PRINT OUTPUT








#close(dbfile)
#inseqfile = open(database, "r")
# dbfile.close()
# inseqfile.close()



#IMPORT DNA DATABASE CSV
#READ INTO MEMORY

#IMPORT DNA SEQUENCE
#READ INTO MEMORY

#SEARCH SEQUENCE FOR EACH STR IN DATABASE
#FOR EACH STR IN SEQUENCE, RECORD LONGEST RUN

#COMPARE STR COUNTS WITH EACH ROW IN DATABASE

#OUTPUT BEST GUESS MATCH OR NO MATCH