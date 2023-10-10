#include <cstdio>
#include <cstdlib>
#include <cstring>
const int MAX_SIZE = 30;

class Student
{
    private:
    int id;
    char name[MAX_SIZE];
    char dept[MAX_SIZE];

    public:
    Student(int i = 0, char* n = "", char* d = "")
    {
        set(i, n, d);
    }

    void set(int i, char* n, char* d)
    {
        id = i;
        strcpy(name, n);
        strcpy(dept, d);
    }

    void display()
    {
        printf("학과: %s, 학번: %d, 성명: %s\n", dept, id, name);
    }
};
