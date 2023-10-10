#include <iostream> 
#define MAX_DEGREE 80
using namespace std;

class Polynomial 
{
    private:
    int degree;
    float coef[MAX_DEGREE];

    public:
        Polynomial()
        {
            degree = 0;
        }

        void read() // 다항식 입력
        {
            cout << "다항식의 최고 차수를 입력하시오. ";
            cin >> degree;
            cout << "각 항의 계수를 입력하시오 (총 " << degree + 1 << "개): ";

            for(int i = 0; i <= degree; i++)
                cin >> coef[i];
        }

        void display(char* str = (char*)" Poly = ") // 다항식 출력
        {
            cout << str;
            
            for(int i = 0; i < degree; i++)
                cout << coef[i] << "x^" << degree - i << " + ";

            cout << coef[degree] << endl;
        }

        void add(Polynomial a, Polynomial b) // 다항식 a + b, 고유의 다항식 설정
        {
            if(a.degree > b.degree)
            {
                *this = a; // a 다항식 자기 객체에 복사

                for(int i = 0; i <= b.degree; i++)
                    coef[i+(degree-b.degree)] += b.coef[i];
            }
            else
            {
                *this = b; // b 다항식 자기 객체에 복사
                for(int i = 0; i <= a.degree; i++)
                    coef[i+(degree-a.degree)] += a.coef[i];
            }
        }

        bool isZero() // 최고 차수 0인지
        {
            return degree == 0;
        }

        void negate() // 모든 계수의 부호 변경
        {
            for(int i = 0; i <= degree; i++)
                coef[i] = -coef[i];
        }

        void sub(Polynomial a, Polynomial b)
        {
            if(a.degree > b.degree)
            {
                *this = a;
                
                for(int i = 0; i <= b.degree; i++)
                    coef[i+(degree - b.degree)] -= b.coef[i];
            }
            else
            {
                *this = b;
                
                for(int i = 0; i <= a.degree; i++)
                    coef[i+(degree - a.degree)] -= a.coef[i];
            }
        }

        void mult(Polynomial a, Polynomial b)
        {
            degree = a.degree + b.degree;

            if(a.degree > b.degree)
            {
                for(int i = 0; i <= a.degree; i++) // Polynomial A
                {
                    for(int k = 0, m = 0; k <= b.degree; k++, m++)
                    {
                        coef[i+m] += a.coef[i] * b.coef[k];
                    }
                }
                        
        } 
        else
        {
            for(int i = 0; i <= b.degree; i++) // Polynomial B
            {
                for(int k = 0, m = 0; k <= a.degree; k++, m++)
                {
                    coef[i+m] += b.coef[i] * a.coef[k];
                }
            }        
        } 
        }   

        void trim()
        {
            for(int i = 0; i <= degree; i++)            
            {
                if(coef[0] == 0)
                {
                    for(int j = 0; j < degree; j++)                    
                    {
                        coef[j] = coef[j+1];
                    }
                    degree -= 1;
                }            
            }
        }

        void display2(char* str = (char*)" Poly = ") // 다항식 출력
        {
            cout << str;
            
            this->trim();
            
            for(int i = 0; i < degree; i++)
            {
                if(coef[i] == 0)
                    continue;
                else if(coef[i] == 1)
                {
                    if(i == 0)
                        cout << "x^" << degree - i;
                    else
                        cout << " + x^" << degree - i;
                }
                else    
                {
                    if(i == 0)
                        cout << coef[i] << "x^" << degree - i;
                    else
                        cout << " + " << coef[i] << "x^" << degree - i;
                }     
            }
            
            if(coef[degree] != 0)
                cout << " + " << coef[degree] << endl;
        }
};

int main()
{
    Polynomial a, b, c;
    a.read();
    a.display2(" A = ");
}