#!/usr/bin/python

import os
from subprocess import call

dirs = ['bio', 'log', 'test', 'crypto', 'rand', 'os', 'scard']

for d in dirs:
  os.chdir(d)
  call(["make"])
  os.chdir("..")
