import time
from newmath import sum, listsum, faster_list_sum


def pure_list_sum(num_list):
    retsum = 0
    for num in num_list:
        retsum += num
    return retsum


target_list = []

for i in range (0, 900000):
    target_list.append(i)

start = time.time()
print(listsum(target_list))
end = time.time()
print('List Sum: time taken in seconds -', end - start)

start = time.time()
print(pure_list_sum(target_list))
end = time.time()
print('Pure List Sum: time taken in seconds -', end - start)

start = time.time()
print(faster_list_sum(target_list))
end = time.time()
print('Faster List Sum: time taken in seconds -', end - start)
