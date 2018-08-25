import time
from newmath import sum, listsum


def purelistsum(num_list):
    retsum = 0
    for num in num_list:
        retsum += num
    return retsum


target_list = []

for i in range (0, 9000000):
    target_list.append(i)

start = time.time()
print(listsum(target_list))
end = time.time()
print('Time taken in seconds -', end - start)

start = time.time()
print(purelistsum(target_list))
end = time.time()
print('Time taken in seconds -', end - start)