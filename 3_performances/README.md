# Chapter 3 - Performances

In this chapter we analyze performaces.


# Why prepend '_' to file names?

In the directory containing the package, .go, .c, .h, and .s files are considered part of the package except for:

- .go files in package documentation
- files starting with _ or . (likely editor temporary files)
- files with build constraints not satisfied by the context
