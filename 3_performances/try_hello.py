import time
from hello import say_hello, say_hello_slowly, say_hello_faster


print ('\n')

start = time.time()

for i in range (0, 900000):
    print('\r' + "Hello " + "PyPizza", end='')
end = time.time()
print('\n\nPure Hello: Time taken in seconds -', end - start)

"""
The following call throws an error if called with GODEBUG=cgocheck=1

panic: runtime error: cgo result has Go pointer

goroutine 17 [running, locked to thread]:
main._cgoexpwrap_80580a90e820_sayHello.func1(0xc000048e50)
	_cgo_gotypes.go:69 +0x51
main._cgoexpwrap_80580a90e820_sayHello(0x10d4b5de0, 0x7, 0xc00001a0f0, 0xd)
	_cgo_gotypes.go:71 +0xfd
"""
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
