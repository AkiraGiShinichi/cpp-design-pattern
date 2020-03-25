#ifndef AUTOTIMER_H
#define AUTOTIMER_H

#include <string>

class Autotimer
{
public:
//    Autotimer();
    explicit Autotimer(const std::string &name);
    // Q: What is explicit?
    // A: it allows construction function to explicit the arguments to an external function(explicited function can get arguments from external function)
    // reference: http://www.cplusplus.com/forum/general/168292/

    // explicit function: hàm hiện
    // implicit function: hàm ẩn
    // mặc định các hàm là "implicit function"

    // Q: When use const?
    // A: exactly "const + &"
    // "string &name" prevent program to make a copy of input variable => save memory. but the variable is able to be modified in the function
    // "const" prohibit the function to modify the variable
    // reference: https://stackoverflow.com/questions/2627166/difference-between-const-reference-and-normal-parameter

    ~Autotimer();

private:
    class Impl;
    Impl *mImpl;
//    boost::scoped_ptr<Impl> mImpl; //~{Impl *mImpl} but mImpl will be freed automatically, hence the constructor need not free it manually.
};

#endif // AUTOTIMER_H
