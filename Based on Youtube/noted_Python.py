# gg = [7,8,3]
# for index, item in enumerate(gg):
#     print(index, item)

# gg = ('Kevin', 'Niklas', 'Jenny', 'Craig')
# print(sorted(gg, key=lambda k: k[1])) # sorted by index 1 

# gg = [i**2 for i in range(10) if i>4]
# print(gg)
# t = [1,2]
# gg.extend(t)
# print(gg)

# gg = 1, # the comma tells Python it's tuple
# print(gg, type(gg))
# gg += (3,)
# print(gg)

# s1 = {1,2,3}
# s2 = {3,4,5}
# print(s1 & s2)
# print(s1 | s2)
# print(s1 ^ s2)
# print(s1 - s2)
# print(s1 <= s2) # check for subset
# print(s1 >= s2) # check for subset

# gg = {1 : 'Ho', 2 : "Anh", 3 : 'Dung'}
# for k, v in gg.items():
#     print(k , v)

# check all packages: pip list

# virtual environments:
# - virtualenv project
# - active: source project/bin/activate
# - save all pakages: pip freeze --local > requirements.txt
# - install all packages in requirements: pip install -r requirements.txt
