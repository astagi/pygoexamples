import sys

from pybindgen import Module, retval


mod = Module('pyperf')
mod.add_include('"perf.h"')
mod.add_function('Countdown', retval('void'), [])
mod.generate(sys.stdout)
