import time
from hello import say_hello, say_hello_slowly, say_hello_faster


print ('\n')

start = time.time()

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