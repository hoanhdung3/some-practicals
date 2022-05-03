class Employee:
    
    def __init__(self, first, last, pay):     # constructor
        self.first = first  # self is the instance
        self.last = last
        self.pay = pay
        self.email = first + '.' + last + '@gmail.com'
    
    def fullname(self):
        return '{} {}'.format(self.first, self.last)
        
emp1 = Employee('Dung', 'Ho Anh', 12345)
emp2 = Employee('Sana', 'Minatozaki', 98765)

print(emp2.email)
print(emp1.fullname()) # need () beacuse this is method, not an atribute
print(Employee.fullname(emp2))
