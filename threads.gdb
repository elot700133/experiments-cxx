set pagination off
set target-async on
set non-stop on
set logging file gdb.txt
set logging on
file a.out

b main.cpp:17

info thread

r
