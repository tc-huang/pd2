# 02 Class
[![hackmd-github-sync-badge](https://hackmd.io/aLr02DELRi6UpfY-QvinlA/badge)](https://hackmd.io/aLr02DELRi6UpfY-QvinlA)

## Classes, Objects, Member Functions and Data Members
- A function belonging to a class is called a **member function**. In a class, you provide one or more member functions that are designed to perform the class’s tasks.

- You must create an **object** of a class for your program to perform the tasks the class describes.

- You send **messages** to an object—each message is known as a **member-function calland**, which tells a member function of the object to perform its task.

- **Attributes** are specified by the class’s data members.

- By convention, the name of a **user-defined class begins with a capital letter**, and for readability, each subsequent word in the class name begins with a capital letter. This capitalization style is often referred toas **camel case**. e,g. `MyClass`

- The access-specifier label `public:`contains the keyword publicas an access specifier. Which indicates that the function can be called by **other functions in the program**(e.g. main), and by **member functions of other classes**.

- Typically, you cannot call a member function of a class until you create an object of that class.

- Call the member function by using variable followed by the dot operator(.), the function name and an empty set of parentheses. e.g.`obj.hello()`

## UML Class Diagram
- UML: Unified Modeling Language

| **ClassName**      |
| ------------------ |
| class's attbutes   |
| class’s operations |

e.g. for class's attbutes: `-start\_ts: time\_t
`

e.g. for class's operations:`+hello(name: String)`, `+setStart (ts: time_t )`, `+getStart(): time_t`, `+getElapsedTime(): Integer`, `<<constructor>>+Timer()`, `<<constructor>>+Timer(s: time_t)`



- In the UML, each class is modeled in a UML class diagramas a rectangle with three compartments.

- The top compartment contains the class’s name centered horizontally and in boldface type.

- The middle compartment contains the class’s attributes, which correspond to data members in C++.

- The bottomcompartment contains the class’s operations, which correspond to member functions in C++.

- The UML models operations by listing the operation name followed by a set of parentheses.

- The plus sign (+) in front of the operation name indicates that hellois a publicoperation in the UML. e.g.`+hello()`

- The UML models a parameter by listing the parameter name, followed by a colonand the parameter type in the parentheses following the operation name.

- The UML has its own data types similar to those of C++.

- The UML is language independent—it’s used with many different programming languages—so its terminology does not exactly match that of C++.

- The UML represents data members as attributes by listing the attribute name, followed by a colon and the attribute type.

- The minus sign in the UML is equivalent to the `private` access specifier in C++.

- To distinguish a constructor from a class’s operations, the UML places the word “constructor” between « and » before the constructor’s name.

- It’s customary to list the class’s constructor before other operations in the third compartment.



## Using `string` Class
```cpp
#include <string>

string s;
getline(cin, s);
cout<<s;
```
- A stringis actually an object of the C++ Standard Library class string.
- Defined in header file `<string>` and part of namespace std.

## Using `getline()` 
- The `<string>` header file must be included in the program to use function getline.
- Library function `getline` reads a line of text into a string.
- The function call getline()reads characters (including the space characters that separate the words in the input) from the standard input stream object cin(i.e., the keyboard) until the newline character is encountered, places the characters in the stringvariable usernameand discards the newline character.

## Data Members
- Every instance (i.e., object) of a class contains one copyof each of the class’s data members.
- A benefit of making a variable a data member is that all the member functions of the class can manipulate any data members that appear in the class definition.

##  Data Members and Member Functions
- The compiler creates **only one copy** of the class’s member functions and shares that copy among all the class’s objects.

- Each object, **needs its own copy of the class’s data members**, because their contents can vary among objects.

- The member function code is not modifiable, so it can be shared among all objects of the class.

- Therefore, the size of an object depends onthe amount of memory required to store the class’s data members.
    - The `sizeof(CLASS_NAME)` or `sizeof(INSTANCE)` only consider the size of data members.
    - `sizeof(CLASS_NAME) == sizeof(INSTANCE)`

## Using `<ctime>`
```cpp
#include <ctime>
time_t ts;
ts = time(NULL);
```

## Using `<unistd.h>`
```cpp
#include <unistd.h>
sleep(2);
```
## `private` Access Specifier
- Variables or functions declared after access specifier `private`(and before the next access specifier) are accessible only to member functions of the class for which they’re declared.

- The defaultaccess for class members is `private` so all members after the class header and before the first access specifier are private.

- Generally, data members should be declared privateand member functions should be declared public.

- Member functions might be declared privateif they are to be accessed only by other member functions of the class

- Despite the fact that the publicand privateaccess specifiers may be repeated and intermixed, list all the public members of a class first in one group then list all the private members in another group. This focuses the programmer’s attention on the class’ publicinterface rather than on the class’s implementation.

## *set* and *get* Functions
- Classes often provide publicmember functions to allow functions from outside the object to **set**(i.e., assign values to) or **get**(i.e., obtain the values of ) privatedata members.

## Initializing Objects with Constructors
- Each class can provide a **constructor** that can be used to **initialize an object of the class when the object is created**.

- A constructor is a special member function that **must be defined with the same name as the class**.

- An important difference between constructors and other functions is that **constructors cannot return values**, so they cannot specify a return type (**not even void**).

- Normally, constructors are declared **public**.

- C++ **requires a constructor** call for each object that is created, which helps **ensure that each object is initialized before it’s used in a program**.

- The constructor call occurs implicitlywhen the object is created.

- If a class does not explicitly include a constructor, the **compiler provides a default constructor** that is, a constructor with no parameters.

- A class gets a default constructor in one of two ways:
    - The compiler implicitly creates a default constructor in a class that does not define a constructor.
    - You explicitly define a constructor that takes no arguments

- If you define a constructor witharguments, C++ will not implicitly create a default constructor for that class.

- Data members can be initialized in a constructor, or their values may be set later after the object is created. However, it is better to ensure that an object is fully initialized before the client code invokes the object’s member functions.

## e.g. Sequence of Constructor Calls in Composition
```cpp
class Tire {
public:
    Tire() { cout << “Tire Constructor" << endl;}
    };
class Car {
public:
    CAR() {cout<<"Car Constructor"<<endl;}
private:
    Tire tireB;
};
int main(){
    Car objA;
    return 0;
}
```
```
Output:
Tire Constructor
Car Constructor
```
## e.g. Error: Illegal Member Initialization Outside Constructor
```cpp
class Cls{
public:
    Cls(){x=4;}
private:
    int x = 3;'
};
int main(){
    Cls obj;
    return 0;
}
```
`int x = 3;` caurse problem.
```
$ g++ -o err\_init err\_init.cpp
err_init.cpp:8: error: ISO C++ forbids initialization of member `x'
```

## Placing a Class in a Separate File for Reusability
- When building an object-oriented C++ program, it’s customary to define **reusable source code** (such as a class) in a file that by convention has a `.h` filename extension—known as a *header file*.

- Programs use `#include` preprocessor directives to include header files and take advantage of reusable software components

- Placing the whole class definition in a header file reveals the entire implementation of the class to the class’s clients.

- However, the client code needs to know only what member functionsto call, what arguments to provide to each member function and what return type to expect from each member function.

- Hiding the class’s implementation details makes it easier to change the class’s implementation while minimizing, and hopefully eliminating, changes to client code.

- **Interfaces** define and standardize the ways in which things such as people and systems interact with one another.

- **The interface of a class** describes what services a class’s clients can use and how to request those services, but not how the class carries out the services

- A class’s `public` interface consists of the class’s `public` member functions.

- t’s better software engineering to **define member functions outside the class definition**, so that their implementation details can be hidden from the client code.

- By convention, member-function definitions are placed in a source-code fileof the same base name as the class’s header file but with a `.cpp `filename extension. e.g. `MyClass::Myclass(){}` for define constructor in the `.cpp` file

- Notice that each member-function name in the function headersis preceded by the class name and `::`, which is known as the **binary scope resolution operator**.

- A function prototype is a declaration of a function that tells the compiler the function’s name, its return type and the types of its parameters.

## Makefile
1. Step 1: Identify targets (executable program and .o files)
2. Step 2: Identify dependencies of each target.
3. Step 3: Write down corresponding commands (for compilation).

e.g.Makefile
```
<target1>: <dependence>
<tab><command>
<tab><command>

<target2>: <dependence>
<tab><command>

clean:
    rm *.o
```
run `make` for cmd.











































