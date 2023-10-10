class mymath:
 	# 함수 정의시 self 필수.
	def add(self, a, b):
		return a + b

p1 = mymath()
print(p1.add(3,4))

def add(a, b):
	return a + b

print(add(3, 5))
