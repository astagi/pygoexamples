import time
from joblib import Parallel, delayed

COUNT = 50000000

def countdown(n):
    while n > 0:
        n -= 1
    print ('Done! My final value is {0}'.format(n))

half_count = int(COUNT/2)
start = time.time()
Parallel(n_jobs=2)(delayed(countdown)(half_count) for i in range(2))
end = time.time()

print('Time taken in seconds -', end - start)
