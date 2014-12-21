Use gdb to debug multi-threaded application

gdb is defaulted to all-stop mode, which will stop all running thread when a
break is reached.  In order to let other threads keep running, issue the
following commands to gdb shell to switch to non-stop mode.

set pagination off
set tharget-async on
set non-stop on

Some other useful commands are:

info thread
thread n
thread apply n|all command

"info thread" will display the status of all thread and thread number

"thread 3" means current thread to thread 3.

"thread apply 3 4 5 command" will apply command to thread 3, 4 and 5.  the
"all" can be used to apply to all threads.

Use the '&' after "next", "step" and "continue" to get gdb prompt immediately.

next&
step&
contineu&
