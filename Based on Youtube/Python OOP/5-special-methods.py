class Employee:
    raise_amt = 1.04
    
    def __init__(self, first, last, pay):
        self.first = first
        self.last = last
        self.email = first + '.' + last + '@gmail.com'
        self.pay = pay 
    
    def fullname(self):
        return '{} {}'.format(self.first, self.last)
    
    def apply_raise(self):
        self.pay = int(self.pay * self.raise_amt)
    
    def __repr__(self): # __repr__ is meant to be unambiguous representation of the obj and should be used for debugging and logging
        return "Employee('{}', '{}', '{}')".format(self.first, self.last, self.pay)
    
    def __str__(self): # __str__ is meant to be more of a readable representation of an obj, to be used as a display to end-user
        return '{} - {}'.format(self.fullname(), self.email)
    
    def __add__(self, other):
        return self.pay + other.pay
    
    def __len__(self):
        return len(self.fullname()) -1
    
emp1 = Employee('Anh', 'Dung', 12345)
emp2 = Employee('Minatozaki', 'Sana', 70000)

print(emp2) 
print(emp2.__repr__()) # recreate emp2
print(emp2.__str__())

print(int.__add__(1,2)) # dunder add method 

print('Total salary of emp1 and emp2: {}'.format(emp1 + emp2))
print('Length of emp1 fullname: {}'.format(len(emp1)))
