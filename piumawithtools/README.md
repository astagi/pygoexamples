gcc sum.c -dynamiclib sum.so -o testsum.so `pkg-config --cflags --libs python3` -I /Library/Frameworks/Python.framework/Versions/3.6/include/python3.6m/


gcc sum.c -dynamiclib sum.so -o testsum.so



python build.py > sum.c