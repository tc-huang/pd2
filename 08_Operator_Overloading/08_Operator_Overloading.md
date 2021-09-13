# 08 Operator Overloading
[![hackmd-github-sync-badge](https://hackmd.io/-07COmYNTqyP0c1Ssxhltg/badge)](https://hackmd.io/-07COmYNTqyP0c1Ssxhltg)

## Fundamentals of Operator Overloading
- Although C++ does not allow new operators to be created, it does allow most existing operators to be overloadedso that, when they’re used with objects, they have appropriate meaning to those objects.

- Use operator overloading when it makes a program clearerthan accomplishing the same operations with function calls.
    ```cpp
    //    which one is clearer?
    add(add(x.y), z)
    x + y + z
    ```
- An operator is overloaded by writing a non-`static` member function definition or global function definition as you normally would, except that the function name now becomes the keyword `operator`followed by the symbol for the operator being overloaded. e.g. `operator+`

- When operators are overloaded as member functions, they must be non-`static`, because they must be called on an object of the class and operate on that object.

- The assignment operator (=) may be used with every class to perform member-wise assignment of the class’s data members
    - **Dangerous for classes with pointer members; we’ll explicitly overload the assignment operator for such classes.**

- The address (&) and comma (,) operators may also be used with objects of any class without overloading.
    - The address operator returns a pointer to the object.
    - The comma operator evaluates the expression to its left then the expression to its right, and returns the value of the latter expression.

## Overloading Stream Insertion and Stream Extraction Operators
```cpp
//    for cin >> Object
istream &operator >> (istream &in, ObjectType &Object){
    return in;
}

//    for cout << Object
ostream &operator << (ostream &out,ObjectType &Object){
    return out;
}
```
## Tips of `cin`
- Stream manipulator setwlimits the number of characters read into each string. e.g. `in >>setw(2)`

- The parentheses and space characters are skipped by calling istreammember function ignore, which discards the specified number of characters in the input stream (one character by default). e.g. `in.ignore(2)`

## Restrictions on Operator Overloading
- **The precedence of an operator cannot be changed by overloading**.

- **The associativityof an operator (i.e., whether the operator is applied right-to-left or left-to-right) cannot be changed by overloading.**

- **It isn’t possible to change the “arity” of an operator (i.e., the number of operands an operator takes): Overloaded unary operators remain unary operators; overloaded binary operators remain binary operators.**

- C++’s only ternary operator (`?:`) cannot be overloaded.

- **Operators `&, *, +` and -all have both unary and binary versions; these unary and binary versions can each be over-loaded.**

- It isn’t possible to create new operators; only existing operators can be overloaded.

- Operator overloading works only with objects of user-defined types or with a mixture of an object of a user-defined type and an object of a fundamental type. That is, **at least one argument of an operator function must be an object or reference of a user-defined type**.

- Overloading `+` does not imply that the `+=` operator is also overloaded.

- Operator functions can be member functions or global functions.
    - Global functions are often made friends for performance reasons
    
- Arguments for both operands of a binary operator must be explicitly listed in a global function call.

- When overloading `(), [], ->`or any of the assignment operators, the operator overloading function must be declared as a member function. For the other operators, the operator overloading functions can be class members or standalone functions.

- **When an operator function is implemented as a member function, the leftmost (or only) operand must be an object (or a reference to an object) of the operator’s class

- If the left operand must be an object of a different class or a fundamental type, this operator function must be implemented as a global function(as we’ll do with `<<` and `>>`).

- You might choose a global functionto overload an operator to enable the operator to be commutative, so an object of the class can appear on the right side of a binary operator.
    ```cpp=
    //    making + commutative
    class Cls{
        friend int operator+(int b, Cls & anObj);
        public:
            int operator+(int y){
                return x+y;
            }
            Cls(int j):x(j){}
        private:
            int x;
    };
    
    int operator+(int b, Cls &anObj){
        return anObj + b;
    }
    ```

## Dynamic Memory Management
- C++ enables you to control the allocation and deallocation of memory in a program for objects and for arrays of any built-inor user-definedtype.
    - Known as dynamic memory management; performed with `new` and `delete`.

- The object or array is created in the free store(also called the heap)—a region of memory assigned to each program for storing dynamically allocated objects.

- The newoperator allocates storage of the proper size for an object of the specified type, calls the constructor to initialize the object and returns a pointer to the type specified

- If `new` is unable to find sufficient space in memory for the object, it indicates that an error occurred by “throwing an exception.”

- A dynamically allocated array’s sizecan be specified using any non-negative integral expression thatcan be evaluated at execution time.

- Also, **when allocating an array of objects dynamically, you cannot pass arguments to each object’s constructor—each object is initialized by its default constructor**.

- To deallocate a dynamically allocated array, use the statement
`delete\[\]ptr;`

- If the pointer points to an array of objects, the statement first calls the destructor for every object in the array, then deallocates the memory.

## Overloading `++` and `--`
- The prefix and postfix versions of the increment and decrement operators can all be overloaded.

### Preincrementing ++
- If the prefix increment operator is implemented as a global function, then, when the compiler sees the expression ++d1, the compiler generates the function call `operator++( d1 )`

- Overloading the postfix increment operator presents a challenge, because **the compiler must be able to distinguish between the signatures of the overloaded prefix and postfix increment operator functions.**

- The conventionthat has been adopted in C++ is that, when the compiler sees the postincrementing expression d1++, it generates the member function call `d1.operator++( 0
    - The argument 0is strictly a “dummy value” that enables the compiler to distinguish between the prefix and postfix increment operator functions.