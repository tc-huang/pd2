# 09 Inheritance

[![hackmd-github-sync-badge](https://hackmd.io/kIh_wZKLR5m9Joshs9YHCQ/badge)](https://hackmd.io/kIh_wZKLR5m9Joshs9YHCQ)

## Introduction of Inheritance
- Inheritance is a form of software reuse in which you create a class that absorbsan existing class’s dataand behaviorsand enhancesthem with new capabilities.

- This existing class is called the **base class**, and the new class is referred to as the **derived class**.

- A derived class contains behaviors inheritedfrom its base class andcan contain additional behaviors.

- A derived class can also customize behaviors inheritedfrom the base class.

## Direct vs. Indirect Base Class and Single vs. Multiple Inheritance
- A **direct base class** is the base class from which a derived class explicitly inherits.

- An **indirect base class** is inherited from two or more levels upin the class hierarchy.

- In the case of single inheritance, a class is derived from one base class.

- **C++ also supports multiple inheritance**, in which a derived class inherits from multiple (possibly unrelated) base classes.

## public, privateand protectedInheritance
- C++ offers `public`, `private` and `protected` inheritance.

- **Every object of a derived class is also an object of that derived class’s base class.**

- However, base-class objects are not objects of their derived classes.

## *is-a* vs. *has-a* Relationship
- **The *is-a* relationship represents inheritance**

- In an *is-a* relationship, an object of a derived class also can be treated as an object of its base class.

- **By contrast, the *has-a* relationship represents composition**

## Base Classes and Derived Classes
- Often, an object of one class is anobject of another class, as well.
    - In geometry, a rectangle is a quadrilateral (as are squares, parallelograms and trapezoids)
    - Thus, in C++, class *Rectangle* can be said to inherit from class *Quadrilateral*
    - A rectangle *is a* specific type of quadrilateral, but it’s incorrect to claim that a quadrilateral is a rectangle—the quadrilateral could be a parallelogram or some other shape.

- A base class exists in a **hierarchical relationship** with its derived classes.

- A class becomes either a base class—supplying members to other classes, a derived class—inheriting its members from other classes, or both.

- In the UML diagram, each arrowin the hierarchy represents an *is-a* relationship.

## Passing Arguments to Constructors
```cpp=
//    IBlock.h
class I_Block{
    public:
        I_Block(int xx=0, int yy=0, int ri=0):x(xx),y(yy), rotate_index(ri){}
};

//    SBlock_inh.h
class S_Block:public I_Block{
    public:
        S_Block(int sx=0, int sy=0, int si=0):I_Block(sx, sy, si){}
};

//    tetris.cpp
int main(){
    S_Blocks(2, 0, 1);
    return 0;
}
```
- The `:public I_Block`  of SBlock_inh.hindicates inheritance, Keyword `public` indicates the type of inheritance.

- As a derived class (formed with publicinheritance), S_Block inherits all the members of class I_Block, **except for the constructor—each class provides its own constructors that are specific to the class**.

- **Destructors are not inherited**.

- The constructor introduces **base-class initializer syntax**, which uses a member initializer to pass arguments to the base-class constructor
    ```cpp
    class S_Block:public I_Block{
    public:
        S_Block(int sx=0, int sy=0, int si=0):I_Block(sx, sy, si){}
    };
    ```
## Accessing privateMembers of Base Class
- The errorsin derived class couldhave been prevented by using the get member functions inherited from base class

## `private` Members
- A derived class can access the non-`private` members of its base class.

- Base-class members that should not be accessible to the member functions of derived classes should be declared `private` in the base class.

- A derived class can change the values of privatebase-class members, but only through non-`private` member functions provided in the base class and inherited into the derived class.

## `protected` Members
- A base class’s `public` members are accessible anywhere.

- A base class’s `private` members are accessible only within its body and to the `friends` of that base class.

- Derived-class member functions can refer to `public`and `protected` members of the base class simply by using the member names.

- **When a derived-class member function redefinesa base-class member function, the base-class member can be accessedfrom the derived class by preceding the base-class member name with the base-class name and the binary scope resolution operator (`::`)**

- A base class’s `protected` members can be accessed by members and friends of the base class and by members and `friend`s of **any classes derived from that base class**.

- **Objects of a derived class also can access `protected` members in any of that derived class’s indirect base classes**

## Constructors and Destructors in Derived Classes
- Instantiating a derived class object begins a chain of constructor calls in which the derived class constructor, before performing its own tasks, **invokes its direct base class’s constructor either explicitly (via a base class member initializer) or implicitly (calling the base class’s default constructor)**.

- If the base class is derived from another class, the base class constructor is required to invoke the constructor of the next class up in the hierarchy, and so on.

- **The last constructor called in this chain is the constructor of the class at the base of the hierarchy, whose body actually finishes executing first.**

- **The original derived-class constructor’s body finishes executing last.**

- When a derived class object is destroyed, the program calls that object’s destructor.

- This begins a chain (or cascade) of destructor calls in which the derived-class destructor and the destructors of the direct and indirect base classes and the classes’ members execute in reverse of the order in which the constructors executed.

- When a derived class object’s destructor is called, the destructor performs its task, then invokes the destructor of the next base class up the hierarchy.

- This process repeats until the destructor of the final base class at the top of the hierarchy is called. Then the object is removed from memory.

- **Base-class constructors, destructors and overloaded assignment operatorsare not inherited by derived classes.** Derived-class constructors, destructors and overloaded assignment operators **can call base-class constructors, destructors and overloaded assignment operators**

## `public`, `protected` and `private` Inheritance

- A base class’s `private` members are never accessible directly from a derived class, but can be accessed through calls to the `public` and `protected` members of the base class.