Here’s the updated description with the language rules included:

---

## Project Description

This project, developed as part of the **Compilers Course**, involves building a compiler for a simple, educational programming language called **Small**. Implemented in C++, the compiler is designed to process Small language source files by checking for syntax and semantic errors, and generating intermediate code. The Small language mimics the structure of C-like languages, with support for core programming features such as data types, control flow, functions, arrays, and classes.

The project allows students to gain hands-on experience in compiler design, including lexical analysis, parsing, semantic checks, and code generation.

## General Information

- **Course**: Compilers  CMP101
- **University**:HIAST
- **Language**: Small (a C-like language designed for educational purposes)
- **Compiler Implementation**: C++
- **Project Scope**:
  - Lexical analysis
  - Syntax analysis (parsing)
  - Semantic checks (e.g., type checking)
  - Code generation (intermediate code)
- **Small Language Features**:
  - **Primitive Data Types**: `int`, `float`, `char`, `string`, `bool`
  - **Control Structures**: `if`, `else`, `while`, `break`
  - **Operators**: Arithmetic (`+`, `-`, `*`, `/`), comparison (`>`, `<`, `==`), logical (`&&`, `||`, `!`)
  - **Functions**: Declaration and function calls with parameter passing
  - **Arrays**: Declaration, initialization, and indexing
  - **Classes**: Class declarations and constructors
- **Input**: Small language source files (`.small`)
- **Output**: Intermediate code or error logs (if errors are detected)
- **Project Goals**:
  - Understanding of compiler design principles
  - Implementation of key components such as scanners, parsers, and code generators
  - Practical application of syntax rules and language grammar
- **License**: MIT License

## Small Language Grammar Rules

The grammar of the Small language is defined as follows:

- **Program Structure**:
  ``` 
  Smallc_program ::= (func | Var_decl)*
  ```

- **Function Declarations**:
  ```
  func ::= type_specifier id ‘(’ param_decl_list ‘)’ compound_stmt
  ```

- **Type Specifiers**:
  ```
  type_specifier ::= int | float | char | string | bool
  ```

- **Parameter Declaration**:
  ```
  param_decl_list ::= (parameter_decl (‘,’ parameter_decl)*)?
  parameter_decl ::= type_specifier id
  ```

- **Compound Statements**:
  ```
  compound_stmt ::= ‘{‘ (var_decl | stmt)* ‘}’
  ```

- **Variable Declarations**:
  ```
  var_decl ::= type_specifier var_decl_list ‘;’
  var_decl_list ::= variable_id (‘,’ variable_id)*
  variable_id ::= id (‘=’ expr)?
  ```

- **Statements**:
  ```
  stmt ::= compound_stmt | cond_stmt | while_stmt | break ‘;’ |
           assign_stmt ‘;’ | continue ‘;’ | return expr ‘;’
  ```

- **Conditional and Loop Statements**:
  ```
  cond_stmt ::= if ‘(’ expr ‘)’ stmt (else stmt)?
  while_stmt ::= while ‘(’ expr ‘)’ stmt
  ```

- **Assignment Statement**:
  ```
  assign_stmt ::= id ‘=’ expr
  ```

- **Expressions**:
  ```
  expr ::= primary | expr operator expr | ‘!’ expr | ‘(’ expr ‘)’ |
           triple_condition | ‘-’ expr | id ‘(’ expr_list ‘)’
  triple_condition ::= expr ‘?’ expr ‘:’ expr
  expr_list ::= (expr (‘,’ expr)*)?
  ```

- **Operators**:
  ```
  operator ::= ‘+’ | ‘-’ | ‘*’ | ‘/’ | ‘>’ | ‘<’ | ‘==’ | ‘&&’ | ‘||’
  ```

- **Primary Expressions**:
  ```
  primary ::= intNum | floatNum | charConst | stringConst | id | ‘true’ | ‘false’ | null
  ```

- **Class Definitions**:
  - Class syntax is similar to Java, supporting constructors and methods:
    ```
    class MyClass {
      /* functions and variables */
    }
    ```

- **Arrays**:
  - Array declaration and initialization:
    ```
    int myArray[];
    int myArray[] = {8, 3, 9};
    ```

---

This document provides a comprehensive overview of the Small language and the compiler project, offering students a solid foundation for learning and implementing compiler concepts.
