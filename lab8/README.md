# lab8

## 1. Explain why the rogram lab8_1.cpp terminates without showing “I love C++.”

Ececuting an empty "throw" statement outside a "catch" handler calls function "terminate", which abandons exception processing and terminates the porgram immediately.


## 2. Does the program lab8_2.cpp show “I love C++”? Why?

No, it shows the fallowing message (2 line):

libc++abi: terminating with uncaught exception of type double
[1]    44282 abort      ./lab8_2

that is because "3.0" treated as double type, which can't caught as float type exception.
Change "throw 3.0" to "throw static_cast<float> 3.0", the exception will be caught and output "I love C++".

## 3.

Run "make" cmd to compile and test the program for first time,
then run "./lab8_3.out" for fallowing test.