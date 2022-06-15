# Question: Alice has some cards with numbers written on them. 
# She arranges the cards in decreasing order, and lays them out face down in a sequence on a table. 
# She challenges Bob to pick out the card containing a given number by turning over as few cards as possible. 
# Write a function to help Bob locate the card.

# import random

# a = []
# for i in range(0,10):
#     a.append(random.randint(0,99))
# a.sort(reverse=True)
# print(a)

# query is the middle elem
test_case = {
    'input' : {
        'cards' : [13, 11, 10, 7, 4, 3, 1, 0],
        'query' : 7
    },
    'output' : 3
}

tests = []
tests.append(test_case)

tests.append({
    'input' : {
        'cards' : [13, 11, 10, 7, 4, 3, 1, 0],
        'query' : 1
    },
    'output' : 6
})

# query is the first elem
tests.append({
    'input' : {
        'cards' : [4, 2, 1, -1],
        'query' : 4
    },
    'output' : 0
})

# query is the last elem
tests.append({
    'input' : {
        'cards' : [4, 2, 1, -1],
        'query' : -1
    },
    'output' : 3
})

# cards contains just 1 elem
tests.append({
    'input' : {
        'cards' : [4],
        'query' : 4
    },
    'output' : 0
})

# cards does not contain query
tests.append({
    'input' : {
        'cards' : [9, 7, 5, 2, -6],
        'query' : 4
    },
    'output' : -1
})

# cards is empty
tests.append({
    'input' : {
        'cards' : [],
        'query' : 4
    },
    'output' : -1
})

# numbers can repeat in cards
tests.append({
    'input' : {
        'cards' : [8, 8, 6, 6, 6, 6, 6, 6, 3, 2, 2, 2, 0, 0, 0],
        'query' : 3
    },
    'output' : 8
})

# query occurs multiple times
tests.append({
    'input' : {
        'cards' : [8, 8, 6, 6, 6, 6, 6, 6, 3, 2, 2, 2, 0, 0, 0],
        'query' : 6
    },
    'output' : 2
})

def locate_card(cards, query):
    position = 0 
    while True:
        if cards[position] == query:
            return position
        position += 1 
        if position == len(cards):
            return -1
        
for test in tests:
    print(locate_card(**test['input']) == test['output'])
# ** means that it takes the keys from this dictionary and the value are then use as arguments for parameters 
