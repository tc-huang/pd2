# 12 Template
[![hackmd-github-sync-badge](https://hackmd.io/p0nC61gZSVGYzz6bPMiblg/badge)](https://hackmd.io/p0nC61gZSVGYzz6bPMiblg)

## Introduction of Template
- **Function templates** and **class templates** enable you to specify, with a single code segment, an entire range of related (overloaded) functions—called **function-template specializations**—or an entire range of related classes—called **class-template specializations**.

- This technique is called **generic programming**.

- Note the **distinction between templatesand template specializations**:
    - Function templates and class templates are like stencil sout of which we trace shapes.
    - Function-template specializationsand class-template specializations are like the separate tracings that all have the same shape, but could, for example, be drawn in different colors.

- Most C++ compilers require the complete definition of a template to appear in the client source-code file that uses the template. For this reason and for reusability, templates are often defined in header files, which are then #included into the appropriate client source-code files. For class templates, this means that the member functions are also defined in the header file.

## Function Templates
- If the operations are identical for each type, they can be expressed more compactly and conveniently usingfunction templates.

- Based on the argument types provided explicitly or inferred from calls to this function, the compiler generates separate source-code functions(i.e., function-template specializations) to handle each function call appropriately.

- All function-template definitionsbegin with keyword templatefollowed by a list of template parametersenclosed in angle brackets(`< >`); each template parameter that represents “any fundamental type or user-defined type”must be preceded by either of the interchangeable keywords `class` or `typename`, as in:
    - `template<typenameT1, typenameT2>`
    - `template<classT>`

- The type template parameters of a function template are used to specify the **types of the arguments** to the function, to specify the **return type** of the function and to **declare variables** within the function.

- **As with function parameters, the names of template parameters must be unique inside a template definition.**

- **Template parameter names need not be unique across different function templates.**
    ```cpp
    template < typename T>
    int func1(Tpar) {...}
    template < typename T>
    double func2(Tpar) {...}
    ```
## Overloading Function Templates
- **The function-template specializations generated from a function template all have the same name**, so the **compiler uses overloading resolution** to invoke the proper function.

## Class Templates
- C++ provides this capability through class templates.

- Class templates are called parameterized types, because they require one or more type parameters to specify how to customize a “generic class”template to form a class-template specialization

- The member-function definitions that appear outside the class template definition each begin with the header `template< typenameT >`

- Although templates offer software-reusability benefits, remember that multiple class-template specializations are instantiated in a program (at compile time), even though the template is written only once.