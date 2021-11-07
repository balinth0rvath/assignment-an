
1. Can be done in C++:
-classes, inheritance, operator overloading, function overloading, virtual functions, polymorphism
-Structure names not prefixed by struct
-references 
-lambdas
-move semanthics
-Generic programming using templates, type deduction, auto, decltype, typeid
-constant expressions
-heap memory management with new and delete 
-exceptions
-bool type 
-nullptr 
-namespaces

Can be done in C
-Old style struct can be defined in argument type declarations
-Initialize char pointer with string literal.
-Initializing a pointer with void* for example using malloc()
-In function declarations argument types can be defined after the arguments

2. C++20

3. OOP classes are user defined types. Creating a representation of such a type, for example defining a local variable, using new or make_unique creates an object of that class. This object is an instance of that class.

4. polymorphism is a mechanism using a common interface for different types. In C++ an object can be pointed by a variable with the type of a parent class, not just by a pointer of the class of the object itself. The concrete class of an object is usually not known is compile time but in runtime.

5. Design patterns are commonly agreed solutions for specific problems. Programming idioms are sequences of tasks solving particular things. Design patterns: builder, iterator, thread pool. Idioms: pointer to implementation 

6. Yes. Using a translation unit as a kind of class representation structs can be used for encapsulation, static functions can be used as private static functions, struct members with function parameter type can be used as public member functions or virtual functions. Placing a struct in the first element in an other struct can be used as a base class.  RAII - automatic construction and destruction is not supported. 

7. Declaration constist a type and a name. It informs the compiler that an entity exists from that point. After definition an entity is fully specified, ready to use. In case of a variable memory is allocated for it, in case of a class it is fully specified.
//declaration of class A
class A;
class B {
  A a;        // Error
  A* a;       // OK
};

// definition of class A
class A {
...
};

A a;          // OK

8.
POD: 
Plain old data. Used for data encapsulation only.
RAII: 
Resource acquisition is initialization. When resource management relies on class construction/ destruction mechanism (examples: lock guards, smart pointers). 
ORD: 
One definition rule: A template, a type or a function cannot have more than one definition in a translation unit. If there are more definitions across transaltion units, these must be identical. 
RVO: 
Return value optimization: (copy elision) Passing by value something means that return value is always unnecessarily duplicated because the one entity local to the called function goes out of scope after the return. A compiler can optimize it moving the return value to the correct place in the caller function.
ADL:
Argument dependent lookup. In function calls if the function doesn't exist in the scope, the compiler searches for the function in the namespaces determined from the argument types.

9. const specifier: 
It tells the compiler that the relevant entity cannot be modified later unless constness casted away. This entity can be a variable, class member, function argument etc... a member function can be const too, in this case that function is not allowed to modify member.
constexpr specifier: 
Replacing macros constexpr can be used to evaluate expressions in compile time.
auto specifier: 
The compiler must deduce the variable type from the expression.
override specifier: 
A member function marked with override takes part in polymorphism. Either it is an overridable function of base class or this function overrides a function in base class.

10.
static_cast is checked at compile time. A class can be casted to an other class with it when the cast mechanism is known.  
dynamic_cast is a safe way to downcast an object with polymorphic type. 

11.
Consider classes A,B,C,D where  A is a base class, B and C are both derived from A and D is derived from both B and C. We have a variable with type B holding an object of D. It can be casted to type C with dynamic_cast

12.
Made for reflection. It returns type_info which holds runtime info of the type or expressions given in the parameter of typeid.

13.
a. When more than one owners may present.
b. Holding a shared_ptr can prevent a pointed object going out of scope. A weak ptr which is not locked on the shared counterpart doesn't hold the shared pointer in scope. 

14.
An array and a vector are usually built on built-in-arrays. These are represented by a contignous memory region. The size of array is fixed at compile time so it can be on stack, but cannot make more or less space later. The length of vector can be modified in runtime. The array is simplier than vector. Removing elements or adding elements from/to these containers are expensive if the element is not on the end of the vector/array. Both can iterate fast. Containers like array, vector, list are sequence containers. A set is an associative container represented by a binary tree(or hash table on unordered_set). It is ordered, so searching is the cheapest function. Search key is unique with set and non-unique selecting multiset.
List is represented by linked list. Always dynamically allocatated. Iteration is slow, but inserting or deleting affects the forward, backward pointers only, not the objects themselves, so these functions are cheap. 

15.
  In stl there are interfaces built upon a container class with restricted functionality. For example stack or queue are deque-s with limited access to the one side only.

16.
Iterators are used to iterate over containers. Mechanism is a bit similar to pointers, but there are more restrictions or possibilities (type safe) can do more than just mirroring a pointer functionality. It is rather a design pattern.

17.
It depends of the context of the caller function. 
If the object of type C is and lvalue, then the first function is called:  C c; c.foobar();
Same as the previous but const variable: const C c; c.foobar();
If it is an rvalue. Consider + operator is defined:  C c1; C c2; (c1+c2).foobar();
or simply convert an lvalue with move

19. 
a: assigning a pointer to a string literal is invalid in C++, but It may be compiled depending of the compiler and the flags.
b: compiles
c: error. c is a constant pointer pointing to a char. b and therefore &b[0] is a pointer pointing to a constant char. It doesn't matter that the address of *c cannot be modified but &b[0] points to char which cannot be modified.   
d: compiles   
e: error, these are different types. e is an address, *e is an address too, and **e is a const char. a is an address, but *a is not an address but a char

21.
/*
 Copy char array from source to target in reverse direction
 assuming target memory is allocated and has at least the same amount of memory 
 allocated as the source.
  @param target
    Pointer to the target array 
  @param source
    Pointer to the source array
  @return Pointer to the first char of target when succeeded
          nullptr if target or source is nullptr or source length is 0
*/
char* convert(char* target, char* source);

constexpr int limit = 65536;

char* convert(char* target, char* source)
{
  // check initializations partially
  // cannot check dangling pointers
  if (target==nullptr || source==nullptr)
  {
    return nullptr;
  }

  // determine source length
  int len=0;
  while(*(source+(len++))!=0)
  
    if (len>limit)
    {
      return nullptr;
    }
  }
  len--;

  if (!len)
  {
    return nullptr;
  }

  // copy reverse array
  for(int i=0;i<len;++i)
  {
    *(target+len-i-1)=*(source+i);
  }   
  return target;
}

