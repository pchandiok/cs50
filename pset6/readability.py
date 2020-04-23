from cs50 import get_string

letters = 0
words = 1
sentence = 0
index = 0.0

# Accepts string from the user
str = get_string("Text: ")

# Checks whether string has any punctuation marks or full stops so as to count letters, words and sentences.
for i in range(len(str)):
    if str[i].isalpha():
        letters += 1
    elif str[i].isspace():
        words += 1
    elif str[i] == '.' or str[i] == '?' or str[i] == '!' or str[i] == '\n':
        sentence += 1

if sentence == 0:
    sentence = 1

# Calculates the index as per the specifications

index = 0.0588 * (100.0 * letters/words) - 0.296 * (100.0 * sentence/words) - 15.8

# Prints the grade
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade ", round(index))

