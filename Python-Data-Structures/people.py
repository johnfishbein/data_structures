class Person:
    def __init__(self, n, a):
        self.name = n
        self.age = a

    def __str__(self):
        return "<Person: " + self.name + " , " + str(self.age) + ">"

    def happy_birthday(self):
        self.age += 1


class Student(Person):
    def __init__(self, n, a, gpa = 0):
        Person.__init__(self, n, a)
        # or super().__init__(n, a)
        self.gpa = gpa

    def __str__(self):
        return "<Student: " + self.name + " , " + str(self.age) + " , " + str(self.gpa) + ">"

    def set_gpa(self, gpa):
        self.gpa = gpa

    def get_gpa(self):
        return self.gpa




s1 = Student('john',19)
print(s1.gpa)

# #  if file is imported dont run anything below it i think
# if __name__ == '__main--':
#     pass
