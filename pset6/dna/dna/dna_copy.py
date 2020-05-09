from sys import argv

verbose = False

database_file = argv[1]
sequence_file = argv[2]

people = {}
sequences = []

with open(database_file, 'r') as f:
    first_line = f.readline()               # read the first line from the file --> string
    first_line = first_line.strip()         # remove whitespace from the line --> string
    sequences = first_line.split(",")[1:]   # split string by commas, remove first element --> array

    # f.seek(0)

    # print(f.readlines())

    for line in f.readlines():              # for remaining lines in file --> string
        line = line.strip()                 # remove whitespace from the line --> string
        person_data = line.split(",")       # split line by commas --> array
        name = person_data[0]               # get name from line (first element of array)
        sequence_count = person_data[1:]    # get sequence counts (remaining elements of array)
        people[name] = sequence_count       # add person to people dictionary with sequence counts

if verbose:
    print("Sequences: ")
    for s in sequences:
        print(s)
    print("\n")

    print("People: ")
    for key, value in people.items():
        print(f"{key}: {value}")

sequence = ""
with open(sequence_file, 'r') as f:
    sequence = f.readline().strip()

if verbose:
    print(f"Sequence to compare: \n{sequence}")

counts = []
for _ in range(len(sequences)):
    counts.append('0')

i = 0
while i < len(sequence):
    for index, s in enumerate(sequences):

        offset = 0
        j = 0
        count = 0
        while i + offset < len(sequence) and s[j] == sequence[i + offset]:
            j += 1
            offset += 1

            if j == len(s):
                j = 0
                count += 1
        if count > int(counts[index]):
            counts[index] = str(count)

    i += 1

if verbose:
    for s in sequences:
        print(f"{s}: {sequence.count(s)}")

    print(counts)

match = None
for person, count in people.items():
    if count == counts:
        match = person
        if verbose:
            print(person, count, counts)
        # break

if match:
    print(f"The match is {match}!")
else:
    print("No match!")