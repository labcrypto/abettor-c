#!/usr/bin/python

import os

dirs = ['bio', 'log', 'test', 'crypto', 'rand', 'os', 'scard', 'util', 'date', 'pkcs11', 'unicode']

for d in dirs:
  os.chdir(d)  
  os.system("make clean")
  os.chdir("..")
