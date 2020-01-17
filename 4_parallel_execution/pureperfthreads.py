from multiprocessing import Pool
import time

COUNT = 50000000
def countdown(n):
    while n > 0:
        n -= 1
    print ('Done! My final value is {0}'.format(n))

if __name__ == '__main__':
    pool = Pool(processes=2)
    half_count = int(COUNT/2)
    start = time.time()
    r1 = pool.apply_async(countdown, [half_count])
    r2 = pool.apply_async(countdown, [half_count])
    pool.close()
    pool.join()
    end = time.time()
    print('Time taken in seconds -', end - start)
