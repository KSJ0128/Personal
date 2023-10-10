#include <iostream>
#include <string>
#include <sstream>
using namespace std;
const int MAX_SIZE = 20;

class Postfix
{
    private:
    int top; // array top
    int itemMax; // 스택 항목 최대 개수
    int maxCount; // itemMax에 도달한 횟수
    int thirdOperand; // 연산자 갯수
    int thirdTop; // 세 번째 연산 이전 스택의 top
    double thirdStack[MAX_SIZE]; // 세 번째 연산 이전 스택 상태
    double array[MAX_SIZE]; 

    public:
    Postfix() // 생성자
    {
        top = -1;
        itemMax = 0;
        maxCount = 1;
        thirdOperand = 0;
        thirdTop = 0;
    }

    void push(double d) // push 연산
    {
        array[++top] = d;

        if(top+1 > itemMax) // stack 최대 항목 개수 체크
        {
            itemMax = top + 1;
            maxCount = 1; // 최대 횟수 초기화
        }
        else if(top+1 == itemMax)
            maxCount++;
    }

    double pop() // pop 연산
    {
        return array[top--];
    }

    bool isEmpty() // empty 연산
    {
        return top == - 1;
    }

    bool isFull() // full 연산
    {
        return top == MAX_SIZE - 1;
    }

    void display() // 출력
    {
        // 1. 스택 항목 최대 개수, 그 횟수
        cout << itemMax << endl << maxCount << endl << "-----" << endl;

        // 2. 세 번째 연산자 수행 직전 스택 상태
        if(thirdOperand >= 3)
        {
            for(int i = 0; i <= thirdTop; i++)
                cout << thirdStack[i] << endl;
        }

        // 3. 계산 결과
        cout << "-----" << endl << array[0];
    }

    void calculate(string op)
    {
        if(++thirdOperand == 3)
        {
            for(int i = 0; i <= top; i++)
            {
                thirdStack[i] = array[top-i];
            }
            thirdTop = top;
        }

        double second = pop();
        double first = pop();

        if(op == "+")
            push(first + second);
        else if(op == "-")
            push(first - second);
        else if(op == "*")
            push(first * second);
        else if(op == "/")
            push(first / second);
    }

    void check(string str)
    {
        if(str == "+" || str == "-" || str == "*" || str == "/") // 연산자일 때
        {
            calculate(str);
        }
        else // 피연산자일 때
        {
            push(stod(str));
        }
    }
};

int main()
{
    Postfix post;
    string str = "";
    
    cout << "수식을 입력해주세요: ";
    getline(cin, str); // 수식 입력 받음

    stringstream ss(str);
    string s1;

    while(ss >> s1)
    {
        post.check(s1);
    }

    post.display();
}       

// 스택 항목 최대 개수가 1이 아닌 경우 
// 연산자가 세 개 이하인 경우 