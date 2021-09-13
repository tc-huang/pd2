# 06 Scope Ctor Dtor
[![hackmd-github-sync-badge](https://hackmd.io/GBX1hzWXTF6dsYWOlZ70Kw/badge)](https://hackmd.io/GBX1hzWXTF6dsYWOlZ70Kw)

## Class Scope
- Even though a member function declared in a class definition may be defined outside that class definition, that member function is still within that class’s scope.

- A class’s data members and member functionsbelong to that class’s scope.

- Within a class’s scope, class members are immediately accessible by all of that class’s member functions and can be referenced by name. e.g. `Cls::Cls(){}`

## Namespace Scope
```cpp
//    Namespace scope (std::main())
namespace std{
    int main(){
        cout << "kerker" << endl;
    }
}
```

##  Accessing Class Members Through Name, Pointerand Reference
- Outside a class’s scope, publicclass members are referenced through one of the handleson an object—an object name, a reference to an objector a pointer to an object.

- The dot member selection operator (`.`) is preceded by an object’s name or with a referenceto an object to access the object’s members.

- The arrow member selection operator (`->`)is preceded by a pointer to an object to access the object’s members

## Constructors with Default Arguments
- A constructor that defaults all its arguments is also a default constructor—i.e., a constructor that can be invoked with no arguments.

- There can be at most one default constructor per class.

## Destructors
- The name of the destructor for a class is the tilde character (~)followed by the class name. e.g. `~ClassName();`

- Called implicitly when an object is destroyed.

- The destructor itself does not actually release the object’s memory—it performs termination housekeeping before the object’s memory is reclaimed, so the memory may be reused to hold new objects.

- Receives no parameters and returns no value.

- Can not specify a return type—not even void.

- A class may have only one destructor.

- A destructor must be public.

- If you do not explicitly provide a destructor, the compiler creates an “empty” destructor.

- It’s a syntax errorto attempt to pass arguments to a destructor, to specify a return typefor a destructor (even voidcannot be specified), to return valuesfrom a destructor or to overload a destructor.

## When Constructors and Destructors Are Called
- Constructors and destructors are called implicitly.

- The order in which these function calls occur depends on the orderin which execution enters and leaves the scopes where the objects are instantiated.

- Generally, destructor calls are made in the reverse order of the corresponding constructor calls

- Constructorsare called for objects defined in global scopebefore any other function (including main) in that file begins execution (although the order of execution of global object constructors between files is not guaranteed).

- The corresponding destructorsare called when mainterminates.

- The constructor for a `static` local object is called only once, when execution first reaches the point where the object is defined—the corresponding destructor is called when mainterminatesor the program calls function exit.

- Global and `static` objects are destroyed in the reverse order of their creation.

## Terminate the program
- Function `exit` forces a program to terminate immediately and **does not execute the destructors** of automatic objects.

- Function `abort` performs similarly to function exitbut forces the program to terminate immediately, **without allowing the destructors of any objects to be called.**

## A Subtle Trap—Returning a Reference to a privateData Member
- A reference to an object is an alias for the name of the object and, hence, may be used on the left side of an assignment statement (lvalue).

- Unfortunatelya publicmember function of a class can return a reference to a privatedata member of that class. In this case, the returned privatedata member can be directly modified outside.

## Default Memberwise Assignment
- The assignment operator (=) can be used to assign an object to another object of the same type.

- By default, such assignment is performed by memberwise assignment: Each data member of the object on the right of the assignment operator is assigned individually to the same data member in the object on the left of the assignment operator.

- **Caution**: Memberwise assignment can cause serious problems when used with a class whose data members contain pointersto dynamically allocated memory