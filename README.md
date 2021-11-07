
# Answers
## Q1 
### Can be done in C++:
- Classes, C++ style Structs, inheritance, operator overloading, function overloading, virtual functions, polymorphism
- References, move semanthics<br> 
- Lambdas<br>
- Generic programming using templates, type deduction, auto<br>
- Reflection: decltype, typeid<br>
- Constant expressions<br>
- Heap memory management with new and delete<br>
- Exceptions<br>
- bool type<br> 
- nullptr<br> 
- Namespaces<br>

### Can be done in C
- Old style struct can be defined in argument type declarations
- Initializing char pointer with string literal.
- Initializing a pointer with void* for example using malloc()
- In function declarations argument types can be defined after the arguments

## Q2 
C++20

## Q3 
OOP classes are user defined types. Creating a representation of such a type, for example defining a local variable, using new or make_unique creates an object described by that class. This object is an instance of that class.

## Q4 
Polymorphism is a mechanism using a common interface for different types. In C++ an object can be pointed by a pointer of the type of a parent class, not just by a pointer of the class of the object itself. The concrete class of an object is usually not known is compile time but in runtime.

## Q5 
Design patterns are commonly agreed solutions for specific problems. Programming idioms are sequences of tasks solving particular things. Design patterns: builder, iterator, thread pool. Idioms: pointer to implementation 

## Q6 
Yes. Using a translation unit as a kind of class representation structs can be used for encapsulation, static functions can be used as private static functions, struct members with function parameter type can be used as public member functions or virtual functions. Placing a struct in the first element in an other struct can be used as a base class, it can be used for inheritance.  RAII - automatic construction and destruction are not supported. 

## Q7 
Declaration consists a type and a name. It informs the compiler that an entity exists from that point. After definition an entity is fully specified, ready to use. In case of a variable memory is allocated for it, in case of a class it is fully specified.
```
//declaration of class A
class A;
class B {
  // definition of variable 'a' cannot be done here because A size and other properties are unknown:
  A a;        // Error
  // pointer size is known:
  A* a;       // OK
};

// definition of class A
class A {
...
};

// A is fully specified so a can be defined here
A a;          // OK
```

## Q8
### POD: 
Plain old data. Used for data encapsulation only.
### RAII: 
Resource acquisition is initialization. When resource management relies on class construction/destruction mechanism (examples: lock guards, smart pointers). 
### ODR: 
One definition rule: A template, a type or a function cannot have more than one definition in a translation unit. If there are more definitions across transaltion units, these must be identical. 
### RVO: 
Return value optimization: (copy elision) Passing by value something means that return value is always unnecessarily duplicated because the one entity local to the called function goes out of scope after the return. A compiler can optimize it moving the return value to the correct place in the caller function.
### ADL:
Argument dependent lookup. In function calls if the function doesn't exist in the scope, the compiler searches for the function in the namespaces determined from the argument types.

## Q9 
### const specifier: 
It tells the compiler that the relevant entity cannot be modified later unless constness casted away. This entity can be a variable, function argument etc... a member function can be const too, in this case that function is not allowed to modify members.
### constexpr specifier: 
constexpr can be used to evaluate expressions in compile time. variables and functions can be constexpr. Used for move computing resources from runtime to compile time
### auto specifier: 
The compiler must deduce the variable type from the expression.
### override specifier: 
A virtual member function marked with override takes part in polymorphism. Either it is an overridable function of base class or this function overrides a function in base class.

## Q10
static_cast is checked at compile time. A class can be casted to an other class with it when the cast mechanism is known.  
dynamic_cast is a safe way to downcast or sidecast an object with polymorphic type. 

## Q11
Consider classes A,B,C,D where A is a base class, B and C are both derived from A and D is derived from both B and C. We have a variable with type B holding an object of D. It can be casted to type C with dynamic_cast

## Q12
Made for reflection. It returns type_info which holds runtime info of the type or expressions given in the parameter of typeid.

## Q13
a. When more than one owners may present.<br>
b. Holding a shared_ptr can prevent a pointed object going out of scope. A weak ptr which is not locked on the shared counterpart doesn't hold the shared pointer in scope.<br>
c. When there is exaclty one owner exists for that pointer.  

## Q14
An array and a vector are usually built on built-in-arrays. These are represented by a contignous memory region. The size of array is fixed at compile time so it can be on stack, but cannot make more or less space later. vector uses heap. The length of vector can be modified in runtime. The array is simplier than vector. Removing elements or adding elements from/to these containers are expensive if the element is not on the end of the vector/array or initial capacity is not enough. Both can iterate fast. Containers like array, vector, list are sequence containers. A set is an associative container represented by a binary tree(or hash table on unordered_set). It is ordered, so searching is the cheapest function. Search key is unique with set and non-unique selecting multiset.
List is represented by linked list. Always dynamically allocatated on heap. Iteration is slow, but inserting or deleting affects the forward, backward pointers only, not the objects themselves, so these functions are cheap. 

## Q15
In stl there are interfaces built upon a container class with restricted functionality. For example stack or queue are deque-s with limited access to the one side only.

## Q16
Iterators are used to iterate over the data of containers. Mechanism is built on pointers, but there are more restrictions (e.g. no random access) or possibilities (type safe) can do more than just mirroring a pointer functionality. It is rather a design pattern.

## Q17
It depends of the context of the caller function.<br> 
### & 
If the object of type C is and lvalue, then the first function is called:  C c; c.foobar(); <br>
### const & 
Same as the previous but const variable: const C c; c.foobar(); <br>
### && 
If it is an rvalue. Consider + operator is defined:  C c1; C c2; (c1+c2).foobar();
or simply convert an lvalue with move<br>

## Q19 
a: assigning a pointer to a string literal is invalid in C++, but It may be compiled depending of the compiler and the flags.<br>
b: compiles<br>
c: error. c is a constant pointer pointing to a char. b holds const values therefore &b[0] is a pointer pointing to a constant char. There is no implicit cast from const char* to char* <br>
d: compiles<br>
e: error, these are different types. e is an address, * e is an address too, and ** e is a const char. a is an address, but * a is not an address but a char<br>
f: error, address is const here
## Q21
https://github.com/balinth0rvath/assignment-an/blob/master/src/main.cpp
