class Account:
	name = "ctoLu"
	def __init__(self, account_holder='John'):
		self.balance = 0;
		self.holder = account_holder
		print(self.name)
	
	def deposit(self, amount):
		self.balance = self.balance + amount
		return self.balance

	def withdraw(self, amount):
		if amount > self.balance:
			print("insufficient funds!")
		else:
			self.balance -= amount
		return self.balance

	def modifyName(self, newName):
		name = newName
		return name

class CheckingAccount(Account):
	withdraw_fee = 1
	interest = 0.01
	def withdraw(self, account):
		return Account.withdraw(self, amount + self.withdraw_fee)

class SavingAccount(Account):
	deposit_fee = 2
	def deposit(self, amount):
		return Account.deposit(self, amount - self.deposit_fee)

class AsSeenOnTVAccount(CheckingAccount, SavingAccount):
	def __init__(self, account_holder):
		self.holder = account_holder
		self.balance = 1

class Bank:
	def __init__(self):
		self.accounts = []

	def open_account(self, holder, amount, kind=Account):
		account = kind(holder)
		account.deposit(amount)
		self.accounts.append(account)
		return account
		
	def pay_interest(self):
		for a in self.accounts:
			a.deposit(a.balance * a.interest)
	
	def too_big_to_fail(self):
		return len(self.accounts) > 1

class A:
	z = -1
	def f(self, x):
		return B(x-1)

class B(A):
	n = 4
	def __init__(self, y):
		if y:
			self.z = self.f(y)
		else:
			self.z = C(y+1)

class C(B):
	def f(self, x):
		return x


