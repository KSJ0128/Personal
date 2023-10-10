#include "StudentStack.h"

int main()
{
    StudentStack stack;
    stack.push(Student(20201028, "김서진", "정시공"));
    stack.push(Student(20201161, "이단비", "소프트웨어"));
    stack.push(Student(202037903, "김나영", "방사선"));
    stack.display();
    stack.pop();
    stack.display();
}