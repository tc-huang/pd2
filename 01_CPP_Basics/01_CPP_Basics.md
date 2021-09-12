# 01 C++ Basics
[![hackmd-github-sync-badge](https://hackmd.io/iVHqrHJVQdO4kYaCtbh3ug/badge)](https://hackmd.io/iVHqrHJVQdO4kYaCtbh3ug)

## First Program in C++: Printing a Line of Text
```cpp=
#include <iostream> //for using cout
using namespace std; // avoid repeating “std::”

int main(){
    cout<<"Hello"; // std::cout
    cout<<"NC"<<"KU!!"<<endl;
    return 0;
}
```
```
>g++ -o hello hello.cpp
>./hello
Hello NCKU!!
```

## The `cout` Object
- When a coutstatement executes, it sends a stream of characters to the standard output stream object—`std::cout`, which is normally “connected” to the screen.

- The notation `std::cout` specifies that we are using a name, in this case cout, that belongs to “namespace” `std`.

- The `<<` operator is referred to as the stream insertion operator. The value to the operator’s right, the right operand, is inserted in the output stream.

## The `endl` Stream Manipulator
- `std::endl` is a so-called **stream manipulator**

- The name `endl` is an abbreviation for “end line” and belongs to namespace `std`.

- The `std::endl` stream manipulator outputs a newline, then *“flushes the output buffer.”*
    - forces any accumulated outputs to be displayed at that moment.
    - This can be important when the outputs are prompting the user for an action, such as entering data.

## The `cin` Object
- A `cin`statement uses the input stream object `cin`(of namespace std) and the stream extraction operator, `>>`, to obtain a value from the keyboard.

- When the computer executes an input statement that places a value in an intvariable, it **waits** for the user to enter a value for variable.

- The computer **converts** the character representation of the number to the veriable type, and assigns this value to the variable




## Where is iostream?
- run `find /usr -name`
    - In Cygwin:
        - `/usr/lib/gcc/i686-pc-cygwin/3.4.4/include/c++/iostream`
        - `/usr/lib/gcc/i686-pc-mingw32/3.4.4/include/c++/iostream`
    - In FreeBSD:
        - `/usr/include/c++/4.2/iostream
- run `cat /usr/include/c++/4.2/iostream
` 
    ```cpp=
    #include <ostream>
    #include <istream>
    namespace std
    {
        extern istream cin; ///< Linked to standard input
        extern ostream cout; ///< Linked to standard output
        extern ostream cerr; ///< Linked to standard error (unbuffered)
        extern ostream clog; ///< Linked to standard error (buffered)
    }
    ```

## Using `#include`
Two ways of `#include` are:
1. `#include<FILE_NAME>` for stander
2. `#include "FILE_NAME.h"` for self define

`#include` will insert the code of including file to the palce of `#include`.

See the include result by run `$g++ -E FILE_NAME.cpp`

From g++’s man page, `-E` Stop after the preprocessing stage; do not run the compiler.

## Using `#ifdef`
### e.g. Turn on/off Debugging Messages
```cpp=
//str_len.cpp
#include<iostream>
#include<cstring>

int main(int argc, char ** argv)
{
#ifdef DEBUG
    std::cout<<argv[1]<<"\n";
#endif
    std::cout<<strlen(argv[1])<<"\n";
    return 0;
}
```
```
>g++ -o str_len str_len.cpp
>./str_len NCkU
4
>g++ -D DEBUG -o str_len str_len.cpp
>./str_len NCKU
NCKU
4
```
Can also use `#defin DEBUG` to define and `undef DEBUG` to undefine.

### Preprocessor Wrapper
*“Preprocessor wrappers”* in header files to **preventthe code in the header from being included into the same source code file more than once.**

```cpp=
//    wrapper
#ifdef FILE_NAME_H
#define FILE_NAME_H
//    code of FILE_NAME_H
#endif
```
## Preprocessor Directive
A preprocessor directiveis a message to the C++ preprocessor.

Lines that begin with #are processed by the preprocessor before the program is compiled.

`#include<iostream>` notifies the preprocessor to include in the program the contents of the input/output stream header file `<iostream>`.

## Comments and using Declaration
- Two ways for comment:
    - `//`
    - `/* */`
- `using` declaration eliminates the need to repeat the std::prefix.

## Getting Return Value in Unix
```cpp=
//    test.cpp
int main(){
return -1;
}
```
```
>g++ -o test test.cpp
>echo $?
0    //    last cmd run success
>./test
>echo $?
255    //    show the value of binary presentation of negtive number which main function returned
>echo $?
0    //    last cmd run success
```




