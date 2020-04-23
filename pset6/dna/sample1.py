import sys
import csv


def main():
    # Number of arguments passed to program (excluding script name)
    argc = len(sys.argv) - 1

    if argc != 2:
        print("Wrong argument count (usage: python dna.py file.csv sequence.txt)")

    # Filename variables
    database_filepath = sys.argv[1]
    sequence_filepath = sys.argv[2]

    # Read people and their STR counts into a list
    people_list = read_csv(database_filepath)
    # Read STRs to look for in the DNA sequence
    str_list = get_strs(database_filepath)
    # Read analyzed DNA sequence
    dna_sequence = get_dna_sequence(sequence_filepath)

    # Initialize helper variables
    match_count = 0
    str_count = len(str_list)
    found_match = False

    # Loop through each person's STR count
    for person in people_list:
        for STR in str_list:
            # Compare current STR count for person with STR count found in sequence
            if int(person[STR]) == get_str_count(dna_sequence, STR):
                match_count += 1
        if match_count == str_count:
            print(f"{person['name']}")
            found_match = True
            break
        else:
            match_count = 0
    
    if not found_match:
        print("No match")


def read_csv(filepath):
    """Read CSV DNA database into list of dictionaries"""
    people_list = []                                # Create a list to append each person's data
    with open(filepath) as database:               # Open the file passed as first parameter as database
        csv_reader = csv.DictReader(database)       # Create a csv_reader object to read the database
        fields = csv_reader.fieldnames              # Get the number of fieldnames (name + STRs)
        fields_num = len(csv_reader.fieldnames)
        for row in csv_reader:                      # Read rows one by one
            new_person = {}                         # Create a dictionary for each person
            for i in range(fields_num):             # Iterate over each fieldname (DictReader skips 1st row)
                key = fields[i]                     # Keys are: person's name and STR names
                value = row[fields[i]]              # Values are specified in database
                new_person[key] = value             # Append key : value to person's dictionary
            people_list.append(new_person)          # After reading each field, append that person to a list of people
    database.close()                                # Close the database
    return people_list
    

def get_dna_sequence(filepath):
    """Reads DNA sequence from file into a variable"""
    with open(filepath) as sequence:
        dna = sequence.read()
    sequence.close()
    return dna
    

def get_strs(filepath):
    """Reads the CVS file and returns a list of sought STRs"""
    with open(filepath) as database:
        csv_reader = csv.DictReader(database)
        fields = csv_reader.fieldnames
    database.close()
    return fields[1:]


def get_str_count(dna_sequence, dna_str):
    """Returns number of consecutive repeating dna_str substrings in dna_sequence string"""
    # Initial count values
    highest_count = 0
    current_count = 0

    # Set initial end point for rfind method
    end = len(dna_sequence)

    # Get STR length
    dna_str_length = len(dna_str)

    # Find each occurence of STR via rfind method (going from the right side of dna_sequence)
    # by comparing indexes of consecutive rfinds to the length of STR
    while True:
        first_index = dna_sequence.rfind(dna_str, 0, end)   # Get the first occurence of STR index in dna_sequence
        if first_index == -1:                               # If STR no longer occurs, exit loop
            break
        else:
            if current_count == 0:                          # Found first occurence
                current_count += 1

        next_index = dna_sequence.rfind(dna_str, 0, first_index)  # Get the index of next occurence up to the first one

        index_difference = first_index - next_index         # Check if the amount of chars between two STRs
        if index_difference == dna_str_length:              # is equal to their length (consecutiveness)
            current_count += 1
        else:
            if current_count > highest_count:
                highest_count = current_count
            current_count = 0
        end = next_index + dna_str_length                   # Set new end rfind point (+dna_str_len to include next_index occurence)
    return highest_count


main()