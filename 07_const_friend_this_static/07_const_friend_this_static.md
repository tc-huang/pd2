# 07 const friend this static
[![hackmd-github-sync-badge](https://hackmd.io/pYFLekdxQa6U0MV3mAUEDQ/badge)](https://hackmd.io/pYFLekdxQa6U0MV3mAUEDQ)

- `const` objects and `const` member functions prevent modifications of objects and enforce the principle of least privilege.

- Composition is a form of reuse in which a class can have objects of other classes as members.

- Friendship enables a class designer to specify nonmember functions that can access a class’s non-publicmembers

- The `this` pointer is an implicit argument to each of a class’s non-static member functions. It allows those member functions to access the correct object’s data members and other non-static member functions.

- `static` class membersare class-widemembers.

## Copy Constructor
- Objects may be passed as function arguments and may be returned from functions. Such passing and returning is performed using pass-by-value by default—a copy of the object is passed or returned

- C++ creates a new object and uses a copy constructor to copy the original object’s values into the new object

- For each class, the compiler provides a default copy constructor that copies each member of the original object into the corresponding member of the new object.

## Pass-by-const-reference
- Passing an object by value is good from a security stand point, because the called function has no access to the original object in the caller, but pass-by-valuecan degradeperformancewhen making a copy of a large object.

- Pass-by-referenceoffers good performance but is weaker from a security standpoint, because the called function is given access to the original object.

- Pass-by-const-referenceis a safe, good-performing alternative.
    ```cpp
    int func (constAClass & AnObject)
    //    or
    int func (AClass const& AnObject);
    ```

## `const` Objects and `const` Member Functions
- You may use keyword `const` to specify that an objectis not modifiableand that any attempt to modify the object should result in a compilation error.

- Declaring variables and objects constwhen appropriate can improve performance. Compilerscan perform certain optimizationson constants that cannot be performed on variables.

- Attempting to declare a constructoror destructorconstis a compilation error.

- **C++ disallows member function calls for constobjects unless the member functions themselves are also declared const**(even for get member functions that do not modify the object).

- **A member function is specified as constboth in its prototype and in its definition**.

- Defining as `const` a member function that modifies a data memberof the object is a compilation error.

- Defining as `const` a member function that calls a non-`const` member function of the class on the same object is a compilation error.

## Overloaded constMember Function
- A `const` member function can be overloaded with a non-`const` version.

- The compiler chooses which overloaded member function to use based on the object on which the function is invoked.

- If the object is `const`, the compiler uses the `const`version. If the object is not `const`, the compiler uses the non-`const`version.

## Member Initializer
- All data members can be initialized using member initializer, but **`const` data members and data members that are referencesmust beinitialized using member initializers**.

- Member initializers appear between a constructor’s parameter list and the left brace that begins the constructor’s body. e.g. `Clock::Clock(clock_t s, clock_t e):elapsed_time(e){ setStart(s);}`
    - Separated from the parameter list with a colon (:).
    - Each member initializer consists of the data member name followed by parentheses containing the member’s initial value.

## Composition: Objects as Members of Classes

- Composition
    - Sometimes referred to as a **has-a relationship**
    - A class can have objects of other classes as members

- An object’s constructor can pass arguments to member-object constructors via member initializers.

- Member objects are constructed in the order in which they are declaredin the class definition (not in the order they are listed in the constructor’s member initializer list) and beforetheir enclosing class objects (sometimes called host objects) are constructed.

## Default Copy Constructor
- The compiler provides each class with a default copy constructorthat copies each data member of the constructor’s argument object into the corresponding member of the object being initialized.

- Initialize member objects explicitly through member initializers. This eliminates the overhead of “doubly initializing” member objects—once when the member object’s default constructor is called and again when set functions are called in the constructor body (or later) to initialize the member object.

## `friend` Functions and `friend` Classes

```cpp
friend bool solve(Sudoku question, Sudoku & answer);
friend int main();
friend class B;
```
- A `friend` functionof a class is defined outside that class’s scope, yet has the right to access the non-public(and public) members of the class.

- Standalone functions, entire classes or member functions of other classes may be declared to be friends of another class.

- **The friendship relation is neither symmetric nor transitive**.

- Even though the prototypes for `friend` functions appear in the class definition,`friend`s are not member functions.

- Member access notions of `private`, `protected` and `public` are not relevant to `friend` declarations, so friend declarations can be placed anywhere in a class definition.

- However, it is suggested to place all friendship declarations first inside the class definition’s body and do not precede them with any access specifier.

## Type of the `this` Pointer
- How do member functions know which object’s data members to manipulate? Every object has access to its own address through a pointer called `this`(a C++ keyword).

- The type of the `this` pointer depends onthe type of the object and whether the member functionin which `this` is used is declared const.
    ```cpp
    Timer::start(){
    star_ts = time(0);
    }
    Timer tmr;
    tmr.start();
    //    will be compile to
    Timer::start(Timer * const this){
    this ->start_ts = time(0);
    }
    Timer tmr
    Timer::start(& tmr);
    ```

## Using the this Pointer
- The `this` pointer is not part of the object itself.

- The `this` pointer is passed (by the compiler) as an implicit argument to each of the object’s non-`static` member functions.

- Objects use the `this` pointer implicitly or explicitly to reference their data members and member functions.
    ```cpp
    //    implicitly
    star_ts = time(0);
    //    explicitly
    this->star_ts = time(0);
    (*this).start_ts = time(0);
    ```

## Cascaded Member Function Call
- Another use of the `this` pointer is to enable cascaded member-function calls (**invoking multiple functions in the same statement**).

- Why does the technique of returning `*this` as a reference work? The dot operator (`.`) associates from left to right.

## staticClass Members
- In certain cases, only one copy of a variable should be shared by all objects of a class. A `static` data memberis used for these and other reasons (e.g., save storage).

- Such a variable **represents “class-wide” information

- Although they may seem like global variables, a class’s staticdata members have class scope.

- **A fundamental-type `static` data member is initialized by default to 0**

- **A `static const` data member can be initialized in its declaration in the class definition.**

- **All other `static` data members must be defined at global namespace scope and can be initialized only in those definitions.**

- A class’s `static` members exist and can be used even when no objects of that class exist.

- To access a `public static` class member when no objects of the class exist, prefix the class name and the binary scope resolution operator (`::`) to the name of the data member.

- To access a `private` or `protected` `static` class member when no objects of the class exist, provide a `public static` member function and call the function by prefixing its name with the class name and binary scope resolution operator.

- It is a compilation error to include keyword `static` in the definition of a `static` data member at global namespace scope.

    ```cpp
    class Cls {
        public: 
            Cls(){ NumObject++; }
            static int NumObject;
    };
    //    Definition (Do not use “static” here.)
    int Cls::NumObject = 0;
    ```

## `this` Pointer vs. `static` Member Function
- A member function should be declared `static` if it does not access non-`static` data members or non-`static` member functions of the class.

- A `static` member function does not have a `this` pointer, because `static` data members and `static` member functions exist independently of any objects of a class.

- The `this` pointer must refer to a specific object of the class, and when a `static` member function is called, there might not be any objects of its class in memory.

- **Using the `this` pointer in a staticmember functionis a compilation error**.

- **Declaring a static member function const is a compilation error.**