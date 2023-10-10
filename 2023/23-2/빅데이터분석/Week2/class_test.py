class MyPerson:
	i = 5
	def __init__(self, name, age):
		self.name = name
		self.age = age

	def bluechip(self):
		return "what is your name?"
	
	def print_name_age(self):
		return "My name is " + str(self.name) + " and I am " + str(self.age)

	def print_i(self):
		return "i = " + str(self.i)

p1 = MyPerson("Jin", 37)

print(p1.print_i())
print(p1.bluechip())
print(p1.print_name_age())

p2 = MyPerson("Jimin", 25)
p3 = MyPerson("Sugar", 28)
p3.i = 6

print(p2.print_i())
print(p2.print_name_age())
print(p3.print_i())
print(p3.print_name_age())
