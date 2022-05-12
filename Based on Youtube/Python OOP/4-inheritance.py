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

class Developer(Employee):
    raise_amt = 1.10
    
    def __init__(self, first, last, pay, prog_lang):
        super().__init__(first, last, pay)
        '''
        super().__init__ is going to pass first, last and pay to our Employee's __init__ method 
        and let that class handle those argument
        '''
        self.prog_lang = prog_lang

class Manager(Employee):
    def __init__(self, first, last, pay, employees=None):
        super().__init__(first, last, pay)
        if employees is None:
            self.employees = []
        else:
            self.employees = employees
            
    def add_emp(self, emp):
        if emp not in self.employees:
            self.employees.append(emp)
    
    def remove(self, emp):
        if emp in self.employees:
            self.employees.remove(emp)
    
    def print_emps(self):
        for emp in self.employees:
            print('-->', emp.fullname())

# print(help(Developer))

dev1 = Developer('Anh', 'Dung', 12345, 'Python')
dev2 = Developer('Minatozaki', 'Sana', 70000, 'C++')

# print(dev1.pay)
# dev1.apply_raise()
# print(dev1.pay)

mgr1 = Manager('Myoui', 'Mina', 20000, [dev1])
mgr1.add_emp(dev2)
mgr1.print_emps()

# print(dev1.prog_lang)

print(isinstance(mgr1, Manager))
print(isinstance(mgr1, Employee))
print(isinstance(mgr1, Developer))

print(issubclass(Developer, Employee))
