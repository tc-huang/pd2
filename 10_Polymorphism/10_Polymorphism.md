# 10 Polymorphism
[![hackmd-github-sync-badge](https://hackmd.io/6RJqlMMUQ5iZ4Nvmv69VxQ/badge)](https://hackmd.io/6RJqlMMUQ5iZ4Nvmv69VxQ)

# Introduction of Polymorphism
- **Polymorphism enables us to “program in the general”** rather than “program in the specific.”
    - Enables us to write programs that process objects of classes that are part of the same class hierarchy as if they were all objects of the hierarchy’sbase class.

- Polymorphism works off base-class pointer handles and base-class reference handles, but not off name handles.

- With polymorphism, we can design and implement systems that are **easily extensible**.
    - New classes can be added with little or no modification to the general portions of the program, as long as the new classes are part of the inheritance hierarchy that the program processes generically.
    - The only parts of a program that must be altered to accommodate new classes are those that require direct knowledge of the new classes that you add to the hierarchy.

## Polymorphism Examples
- **Polymorphism occurs when a program invokes a `virtual` function through a base-class pointer or reference.**

- C++ dynamically (i.e., at execution time) chooses the correct function for the class from which the object was instantiated.

- Polymorphism promotes extensibility: Software written to invoke polymorphic behavior is written independently of the types of the objects to which messages are sent. Thus new types of objects that can respond to existing messages can be incorporated into such a system without modifying the base system. **Only client code that instantiates new objects must be modified to accommodate new types**.

```cpp
//    class Class2: public Class1
Class1 *p;
Class2 obj;
p = &obj;
static_cast<Class2 *>(p)->func();
```
- Off a base-class pointer, the compiler allows us to invoke only base-class member functions.

- If a base-class pointer is aimed at a derived-class object, and an attemptis made to access a derived-class-only member function, a compilation error will occur.

- The compiler allows access to derived-class-only membersfrom a base-class pointer that is aimed at a derived-class object if we explicitly cast the base-class pointer to a derived-class pointer—known as downcasting.

- After a downcast, the program can invoke derived-class functions that are not in the base class.

## Virtual Functions
- With `virtual` functions, the type of the object being pointed to, not the type of the handle, determines which version of a `virtual` function to invoke.

- We declare a `virtual` function by preceding the function’s prototype with the keyword `virtual` in the base class.

- Once a function is declared `virtual`, it remains `virtual` all the way down the inheritance hierarchy from that point, even if that function is not explicitly declared `virtual` when a derived class overrides it.

- Even though certain functions are implicitly `virtual` because of a declaration made higher in the class hierarchy, explicitly declare these functions `virtual` at every level of the hierarchy to promote program clarity.

- When a derived class chooses not to override a `virtual` function from its base class, the derived class simply inheritsits base class’s `virtual` function implementation.

- If a program invokes a `virtual` function through a base-class pointer to a derived-class object or a base-class reference to a derived-class object, the program will choose the correct derived-class function dynamically (i.e., at execution time) based on the object type—not the pointer or reference type.

- When a `virtual` function is called by referencing a specific object by name and using the dot member-selection operator, the function invocation is resolved at compile time(this is called static binding) and the `virtual` function that is called is the one defined for (or inherited by) the class of that particular object—this is not polymorphic behavior.

## Allowed Assignments Between Base-Class and Derived-Class Objects and Pointers
- derived-class pointers at base-class objects and derived-class objects:
    - Aiming a base-class pointer at a base-class object is straightforward—calls made off the base-class pointer simply invoke base-class functionality.
    - Aiming a derived-class pointerat aderived-class objectis straightforward, too.
    - Aiming a base-class pointerat a derived-classobject is safe, because the derived-class object is an object of its base class. This pointer can be used to invoke only base-class member functions.
    - Aiming a derived-class pointerat a base-class objectgenerates a compilation error.

## Abstract Classes and Pure `virtual` Functions
- There are cases in which it’s useful to define classes from which you never intend to instantiate any objects. Such classes are called **abstract classes**. (inheritance hierarchies, we refer to them as abstract base classes.
)

- These classes cannot be used to instantiate objects, because, as we’ll soon see, **abstract classes are incomplete; derived classes must define the “missing pieces.”**

- An abstract class provides a base class from which other classes can inherit.

- **Classes that can be used to instantiate objects are called concrete classes. Such classes define every member function they declare.**

- **An inheritance hierarchy does not need to contain any abstract classes, but many object-oriented systems have class hierarchies headed by abstract base classes.**

- **In some cases, abstract classes constitute the top few levels of the hierarchy.**

- A class is made abstract by declaring one or more of its `virtual` functionsto be “pure.”A pure `virtual` functionis specified by placing “= 0” in its declaration, as in `virtual voidpaint() const= 0`

    - The “`= 0`” is a **pure specifier**.
    - Pure `virtual` functions do not provide implementations.
    - Every concrete derived class must override all base-class pure `virtual` functions with concrete implementations of those functions.
    - The difference between a `virtual` function and a pure `virtual` function is that a `virtual` function has an implementationand gives the derived class the option of overriding the function.

- An abstract class defines a common public interface for the various classes in a class hierarchy.

- An abstract class has at least one pure `virtual` function. **An abstract class also can have data members and concrete functions(including constructors and destructors)**.

- **Although we cannot instantiate objects of an abstract base class, we can use the abstract base class to declare pointers and references that can refer to objects of any concrete classes derived from the abstract class.**

- Programs typically use such pointers and references to manipulate derived-class objects **polymorphically**.

## Virtual Destructors
- **A problem can occur when using polymorphism to process dynamically allocated objectsof a class hierarchy.**

- If a derived-class object with a nonvirtual destructor is destroyed explicitly by applying the deleteoperator to a base-class pointer to the object, the C++ standard specifies that the behavior is undefined.

- The simple solution to this problem is to create a `virtual` destructorin the base class. The simple solution to this problem is to create a `virtual` destructorin the base class.

## Notice on `virtual` Constructor / Destructor

- **If a class has `virtual` functions, provide a virtualdestructor, even if one is not required for the class. This ensures that a custom derived-class destructor (if there is one) will be invoked when a derived-class object is deleted via a base class pointer.**

- **Constructors cannot be virtual. Declaring a constructor virtual is a compilation error.**