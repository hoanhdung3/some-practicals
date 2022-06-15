# basic format: new_list = [transform sequence [filter] ]
import random

# get values within a range 
under_10 = [x for x in range(10)]
print('under 10: ' + str(under_10))

# get squared values 
squares = [x**2 for x in under_10]
print('squares: ' + str(squares))

# get odd numbers using mod 
odds = [x for x in range(10) if x%2==1 ]
print('odds: ' + str(odds))

# get all numbers from a string 
s = 'I love 2 go t0 the store 7 times a w3ek.'
nums = [x for x in s if x.isnumeric()]
print('nums: ' + ''.join(nums))

# get index of a list item 
names = ['Cosmo', 'Perdo', 'Anu', 'Ray']
idx = [k for k, v in enumerate(names) if v=='Anu']
print('index = ' + str(idx[0]))

# delete an item from a list 
letters = [x for x in 'ABCDEF']
random.shuffle(letters)
letrs = [a for a in letters if a!='C']
print(letters, letrs)

# nested loop iteration in 2D list 
a = [[1,2], [3,4]]
new_list = [x for b in a for x in b]
print(new_list)
