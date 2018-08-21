from pybindgen import retval, param, Module
import sys

mod = Module('testsum')
mod.add_include('"sum.h"')
mod.add_function('Sum', retval('int'), [param('int', 'a'), param('int', 'b')])
mod.generate(sys.stdout)