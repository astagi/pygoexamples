import time
from threading import Thread

COUNT = 50000000

def countdown(n):
    while n > 0:
        n -= 1
    print ('Done! My final value is {0}'.format(n))

half_count = int(COUNT/2)
t1 = Thread(target=countdown, args=(half_count,))
t2 = Thread(target=countdown, args=(half_count,))

start = time.time()
t1.start()
t2.start()
t1.join()
t2.join()
end = time.time()

print('Time taken in seconds -', end - start)

