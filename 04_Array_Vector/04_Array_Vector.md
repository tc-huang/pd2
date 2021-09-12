# 04 Array Vector
[![hackmd-github-sync-badge](https://hackmd.io/-bWDR9e2QOGDtx4Ar2rOtQ/badge)](https://hackmd.io/-bWDR9e2QOGDtx4Ar2rOtQ)

## `public static const` Data Member
- `public` so that it’s accessible to the clients of the class.
- `const` so that the data member is constant.
- `static` so that the data member is shared by all objects of the class.
- `static` data membersare also known as class variables. When objects of a class containing `static` data members are created, all the objects share one copy of the class’s staticdata members.6

## Initialization of `const` Data Member
```cpp
class Cls{
    public:
        Cls():x(3){}
        const int x;
};
```
## Initialization of `static const` Data Member
```cpp
class Cls{
    public:
        Cls(){}
        static const int x = 3;
};
```

## `static` Data Member
```cpp
class Cls{
    public:
        Cls(){++NumObject;}
        //    Use static here!
        static int NumObject;
};
//    Don't use static here!
int Cls::NumObject = 0;
```
- A `static`data member **can be accessed within the class definition** and the member-function definitions like any other data member.
- A `public static` data member can also be **accessed outside of the class, even when no objects of the class exist**, using the class name followed by the binary scope resolution operator (`::`) and the name of the data member.

## C++ Standard Library Class Template vector

- C-style pointer-based arrays have great potential for errors and are not flexible:
    - A program can easily “walk off” either end of an array, because C++ does not check whether subscripts fall outside the range of an array. e.g. `arr[-1]`
    - Two arrays cannot bemeaningfully compared with equality operators or relational operators. e.g.`if(arr1 == arr2)`
    - When an array is passed to a general-purpose function designed to handle arrays of any size, the size of the array must be passed as an additional argument. e.g. `func(arr, size)`
    - One array cannot be assigned to another with the assignment operator. e.g. `arr1 = arr2`

- C++ Standard Library class template `vector` represents a more robust type of array featuring many additional capabilities:
    - Standard class template vectoris defined in header `<vector>` and belongs to namespace std.
    - By default, **all the elementsof a vector object are set to 0**.
    - **vectors can be defined to store any data type**.
    - **vector member function `size` obtain the number of elements in the vector**. e.g. `v.size()`.
    - vector objects can be compared with one another using the equality operators. e.g. `if(v1 == v2)`
    - You can create a new vector object that is initialized with the contents of an existing vectorby using its copy constructor. e.g. `vector<int> v2(v1);`
    - You can use the assignment (=) operator with vector objects. e.g. `v1 = v2;`
    - You can use square brackets, \[\], to access the elements in a vector. As with C-style pointer-based arrays, C++ does not perform any bounds checking when vector elements are accessed with square brackets. e.g. `v\[1\];`
    - Standard class template vectorprovides bounds checking in its member function at, which “throws an exception” if its argument is an invalid subscript. e.g. `v.at(1);`

## Using `sort()` in C++ Standard Library

```cpp
#include <algorithm>
insertion_sort(v);
```