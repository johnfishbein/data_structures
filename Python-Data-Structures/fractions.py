class Fraction:
    # class definition include set of methods

    def __init__(self, n, d):  # constructor
        self.num = n  #defines instance var num as arg/param n
        self.den = d

    def __str__(self):
        # return "<%d/%d>" % (self.num, self.den) # format str number 1
        return "<{}/{}>".format(self.num, self.den) # format str number 2

        # format str number 3  == f strings

    def to_float(self):
        return self.num/self.den

    def __eq__(self, other):
        return (self.num * other.den) == (self.den * other.num)







f1 = Fraction(2,3)
f2 = Fraction(4,6)
print(f1 == f2)  # print automatically converts f1 to string through default string method