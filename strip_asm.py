#!/usr/bin/python3
import sys
from pwn import *

# Use the filename provided as a command-line argument, or the default
filename = sys.argv[1]

try:
    # Open the file for reading
    with open(filename, 'r') as file:
        # Read and print the contents
        contents = file.read()
        print(contents)
except FileNotFoundError:
    print(f"Error: The file '{filename}' does not exist.")
except IOError as e:
    print(f"Error: An IOError occurred. {e}")
context.log_level='debug'
context.arch='amd64'
context.terminal = ['tmux', 'splitw', '-h', '-F' '#{pane_pid}', '-P']
with open('./hw','rb') as f:
    pro = f.read()
print(len(pro))
pro = list(pro)
cut = 0x68
pro[0x18]  = cut
pro[0x74]  = 0x7c-(0x70-cut)
pro = pro[:cut]+pro[0x70:]
print(pro)
x = b''
for _ in pro:
    x+=_.to_bytes(1,'little')
with open("X",'wb') as f:
    f.write(x)
