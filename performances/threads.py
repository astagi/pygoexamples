import time
from pyperf import Countdown


start = time.time()
Countdown()
end = time.time()

print('Time taken in seconds -', end - start)

