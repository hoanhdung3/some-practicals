class CreditCard:
    def __init__(self, customer, bank, acnt, limit):
        """
        The initial balance is zero
        
        customer: the name of customer
        bank:     the name of bank
        acnt:     the account identifier
        limit:    credit limit
        """
        self._customer = customer
        self._bank = bank
        self._account = acnt 
        self._limit = limit 
        self._balance = 0
    def get_customer(self):
        return self._customer
    def get_bank(self):
        return self._bank
    def get_account(self):
        return self._account
    def get_limit(self):
        return self._limit
    def geT_balance(self):
        return self._balance
    def charge(self, price):
        if price + self._balance > self._limit:
            return False
        else:
            self._balance += price
            return True
    def make_payment(self, amount):
        self._balance -= amount

class PredatoryCreditCard(CreditCard):
    def __init__(self, customer, bank, acnt, limit, apr):
        # apr: Annual percentage rate 
        super().__init__(customer, bank, acnt, limit) # call super constructor
        self._apr = apr
    def charge(self, price):
        """
        Charge given price to the card, assuming sufficient credit limit.
        """
        success = super().charge(price) # call inherited method 
        if not success:
            self._balance += 5          # assess penalty
        return success
    def process_month(self):
        if self._balance>0:
            monthly_factor = pow(1 + self._apr, 1/12)
            self._balance *= monthly_factor
