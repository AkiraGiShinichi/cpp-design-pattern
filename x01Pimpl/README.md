# Pimpl

## Symptom:
```C++
class Something()
{
    ...
private:
    class Impl;
    Impl *mImpl;
}
```

## Pros and Cons
### Pros:
 - hide all private members -> clearer & more concise header file
 - prevent user to hack to access(by `#define private public`)

### Cons:
 - it requires to allocate & free the additional object
 - it requires to define a new class of Implement-Object

## Usage(?):
 - dev normal class
 - move all private variables and methods into Impl

 > *?* means not sure

## [Template](https://www.geeksforgeeks.org/pimpl-idiom-in-c-with-examples/)
**Header file**
```C++
/* |INTERFACE| User.h file */

#pragma once
#include <memory> // PImpl
#include <string>
using namespace std;

class User {
public:
    // Constructor and Destructors
    ~User();
    User(const string &name);
//  explicit User(const string &name);

    // Asssignment Operator and Copy Constructor
    User(const User& other);
    User& operator=(User rhs);

    // Getter
    int getSalary();

    // Setter
    void setSalary(int);

private:
    // Internal implementation class
    class Impl;

    // Pointer to the internal implementation
    unique_ptr<Impl> pimpl;
};
```

**Implementation file**
```C++
/* |IMPLEMENTATION| User.cpp file */

#include "User.h"
#include <iostream>
using namespace std;

struct User::Impl {
    Impl(const string &name) : name(name){};

    ~Impl();

    void welcomeMessage()
    {
        cout << "Welcome, "
             << name << endl;
    }

    string name;
    int salary = -1;
};

// Constructor connected with our Impl structure
User::User(string name) : pimpl(new Impl(name))
{
    pimpl->welcomeMessage();
}

// Default Constructor
User::~User() = default;

// Assignment operator and Copy constructor
User::User(const User& other) : pimpl(new Impl(*other.pimpl))
{
}

User& User::operator=(User rhs)
{
    swap(pimpl, rhs.pimpl);
    return *this;
}

// Getter and setter
int User::getSalary()
{
    return pimpl->salary;
}

void User::setSalary(int salary)
{
    pimpl->salary = salary;
    cout << "Salary set to "
         << salary << endl;
}
```



