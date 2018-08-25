import sys

from pybindgen import Module, retval, param


mod = Module('newmath')
mod.add_container('std::list<std::string>', 'std::string', 'list')
mod.add_function('Countdown', retval('void'), [
    param('std::list<std::string> const &', 'listOfStrings'),
])
mod.generate(sys.stdout)
