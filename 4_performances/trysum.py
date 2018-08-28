import time
from newmath import sum, listsum, faster_list_sum, say_hello, say_hello_slowly, say_hello_faster


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

start = time.time()

print ('\n')

for i in range (0, 900000):
    print('\r' + "Hello " + "PyPizza", end='')
end = time.time()
print('\n\nPure Hello: Time taken in seconds -', end - start)

for i in range (0, 900000):
    print('\r' + say_hello("PyPizza"), end='')
end = time.time()
print('\n\nSay Hello: Time taken in seconds -', end - start)

start = time.time()
for i in range (0, 900000):
    print('\r' + say_hello_slowly("PyPizza"), end='')
end = time.time()
print('\n\nSay Hello slowly: Time taken in seconds -', end - start)

start = time.time()
say_hello_faster("PyPizza", 900000)
end = time.time()
print('\n\nSay Hello faster: Time taken in seconds -', end - start)