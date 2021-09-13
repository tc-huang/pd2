# 05 Function

[![hackmd-github-sync-badge](https://hackmd.io/gwc8CLbKSVaei1Nfy_AOpg/badge)](https://hackmd.io/gwc8CLbKSVaei1Nfy_AOpg)

## References and Reference Parameters
- **Two ways to pass arguments to functions** in many programming languages are **pass-by-value** and **pass-by-reference**.

- When an argument is **passed by value, a copy of the argument’s value is made** and passed (on the function call stack) to the called function
    - Changes to the copy do not affect the original variable’s value in the caller.
    - If a large data item is being passed, copying that data can take a considerable amount of execution time and memory space.

- With pass-by-reference, the caller gives the called function the ability to access the caller’s data directly, and to modify that data.

- A reference parameter is an alias for its corresponding argument in a function call.

- To indicate that a function parameter is passed by reference, simply follow the parameter’s type in the function prototype by an ampersand (&).

- Pass-by-reference is good for performance reasons, because it can eliminate the pass-by-value overhead of copying large amounts of data.

- To specify a reference to a constant, place the constqualifier before the type specifier in the parameter declaration.

- For passing large objects, use a constant reference parameter to simulate the appearance and security of pass-by-value and avoid the overhead of passing a copy of the large object.

## Initializing a Reference
- References can also be used as aliases for other variables within a function. e.g. `int &y = x;`

- **Reference variables must be initialized in their declarations** and **cannot be reassigned as aliases to other variables**.

- Once a reference is declared as an alias for another variable, all operations supposedly performed on the alias are actually performed on the original variable.

## Returning a Reference
- Functions can return references, but this can be dangerous.

- **Returning a reference to an automatic variable in a called function is a logic error**. Some compilers issue a warningwhen this occurs.

- When returning a reference to a variable declared in the called function, the variable should be declared `static` in that function.

## Default Arguments
- When a program omits an argument for a parameter with a default argument in a function call, the compilerrewrites the function call and inserts the default value of that argument

- **Default arguments must be the rightmost (trailing)** arguments in a function’s parameter list.

- Specifying and attempting to use a default argument that is not a rightmost argument (while not simultaneously defaulting all the rightmost arguments) is a syntax error.

## Function Overloading
- C++ enables **several functions of the same name to be defined, as long as they have different signatures**. This is called **function overloading**.

- The C++ **compiler selects the proper function to call by examining the number, types and order of the argumentsin the call**.

- Function overloading is used to create several functions of the same name that perform similar tasks, but on different data types.

- Overloaded functions are distinguished by their signatures.

- **A signature is a combination of a function’s name and number, types and order of its parameters**.

- The compiler encodes each function identifier with the number and types of its parameters to enable type-safe linkage. See the encode result by run the `>nm FILE` cmd.
    - From nm’s man page:
        - nm-list symbols from object files
        - "T" The symbol is in the text (code) section.

- Creating overloaded functions with identical parameter lists and different return typesis a compilation error.

- A function with default arguments omittedmight be called identically to another overloaded function; this is a compilation error

## Function Templates
- If the program logic and operations are identicalfor each data type, overloading may be performed more compactly and conveniently by using function templates.

e.g.
```cpp=
template<typename T>
T maximum(T v1, T v2, T v3)
{
T max = v1;
if(v2 > max)
    max = v2;
if(v3 > max)
    max = v3;
return max;
}
```

- All function template definitions begin with the `template` keyword followed by a template parameter listto the function template enclosed in angle brackets (`< >`).

- Every parameter in the template parameter list (often referred to as a formal type parameter) is preceded by keyword `typename` or keyword `class`.

- The formal type parameters are placeholders for **fundamental types or user-defined types

- These placeholders are used to specify the types of the **function’s parameters, to specify the function’s return type and to declare variable**s within the body of the function definition.