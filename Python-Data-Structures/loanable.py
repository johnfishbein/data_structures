class Loanable:
    def __init__(self, i, t):
        self.id = i
        self.title = t
        self.due_date = None

    def __str__(self):
        return "ID: " + str(self.id) + " --- Title: " + self.title

    def __eq__(self, other):
        return self.id == other.id

    def get_id(self):
        return self.id

    def get_title(self):
        return self.title

    def get_duedate(self):
        return self.due_date

    def set_duedate(self, date):
        self.due_date = date


class Book(Loanable):
    def __init__(self, i, t, a):
        Loanable.__init__(self, i, t)
        self.author = a

    def __str__(self):
        return "ID: " + str(self.id) + " --- Title: " + self.title + " --- Author: " + self.author

    def get_author(self):
        return self.author


class Laptop(Loanable):
    def __init__(self, i, t, o):
        Loanable.__init__(self, i, t)
        self.os = o

    def __str__(self):
        return "ID: " + str(self.id) + " --- Title: " + self.title + " --- OS " + self.os

    def get_os(self):
        return self.os

#
# a = Loanable(123, "The Title")
# print(a)
#
# b = Book(456, "Hello", "John")
# print(b)
#
# c = Laptop(789, "j", "mac")
# print(c)