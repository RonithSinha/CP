import random
n=5
m=3
cylinders=[[] for i in range(3)]
num=3
cylinders[0].append(num)
cylinders[1].append(num)

print(cylinders)
for i in range(n):
    selectedIndex=random.randint(0,m-1)
    cylinders[selectedIndex].append(i)
    selectedIndex=random.randint(0,m-1)
    print('--------')
    print([num for num in range(m-1) if num!=selectedIndex])
    selectedIndex2=random.choice([num for num in range(m-1) if num!=selectedIndex])
    print('->', i,selectedIndex,selectedIndex2)
    cylinders[selectedIndex].append(i)
    cylinders[selectedIndex2].append(i)
    print(cylinders)
    print(cylinders[selectedIndex])
    print(cylinders[selectedIndex2])
    
for cylinder in cylinders:
    for j in cylinder:
        print(j, end=' ')
    print()