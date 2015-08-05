#!/usr/bin/python

import os

dirs = ['bio', 'log', 'test', 'crypto', 'rand', 'os', 'scard', 'util', 'date']

os.system("mkdir -p lib")
os.system("rm -rf lib/*")

for d in dirs:
  os.chdir(d)  
  os.system("make")
  os.system("cp -P .lib/libnaeem* ../lib")
  os.chdir("..")
