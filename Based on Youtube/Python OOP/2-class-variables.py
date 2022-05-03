class Employee:
    
    num_of_emps = 0 
    raise_amount = 1.04
    
    def __init__(self, first, last, pay):     # constructor
        self.first = first  # self is the instance
        self.last = last
        self.pay = pay
        self.email = first + '.' + last + '@gmail.com'
        Employee.num_of_emps += 1 
        
    def fullname(self):
        return '{} {}'.format(self.first, self.last)
    
    def apply_raise(self):
        self.pay = int(self.pay * self.raise_amount)
        
emp1 = Employee('Dung', 'Ho Anh', 12345)
print('Number of employees: {}'.format(Employee.num_of_emps))
emp2 = Employee('Sana', 'Minatozaki', 98765)

# print(Employee.__dict__)
# print(emp1.__dict__) # see emp1 doesn't have raise_amount attribute but Employee have

Employee.raise_amount = 1.05

print(Employee.raise_amount)
print(emp1.raise_amount)
print(emp2.raise_amount)

emp1.raise_amount = 1.04
print(emp1.__dict__) # see emp1 now have raise_amount attribute

print(Employee.raise_amount)
print(emp1.raise_amount)
print(emp2.raise_amount)

print('Number of employees: {}'.format(Employee.num_of_emps))
