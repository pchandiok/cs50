EMPTY = None
X = 'X'
O = 'O'


test = [
    [EMPTY, EMPTY, EMPTY],
    [EMPTY, EMPTY, EMPTY],
    [EMPTY, EMPTY, EMPTY]
]

possible_actions = set()

for i, row in enumerate(test):
    if i == 2:
        i=0
    for j, cell in enumerate(row):
        if j == 2:
            j=0
        if cell == EMPTY:
            possible_actions.add((i, j))

print(possible_actions)

