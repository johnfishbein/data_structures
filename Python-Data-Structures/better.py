print('Enter GPAs:')
x = input('')
gpas = []
while (x != 'end'):
    if float(x) > 4.0 or float(x) < 0:
        print("Invalid input ignored:", x)
    else:
        gpas.append(float(x))
    x = input('')


total = 0
for i in gpas:
    total += i
average = total/len(gpas)
print(average)

greater = []

for i in gpas:
    if i > average:
        greater.append(i)

for i in greater:
    gpas.remove(i)



print(greater)
print(gpas)

#this is an edit
