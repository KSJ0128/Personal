#include <iostream>
#include <random>
using namespace std;
const int MAX_SIZE = 100;

class Queue // 2. 원형 큐 사용해 남녀학생 큐 구현
{
    protected:
    int front;
    int rear;
    string meeting[MAX_SIZE];

    public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty() // 큐가 비어있는지 확인
    {
        return front == rear;
    }

    bool isFull() // 큐가 가득 차있는지 확인
    {
        return front == (rear+1) % MAX_SIZE;
    }

    void enqueue(string name) // 큐의 front로 삽입 연산
    {
        if(isFull()) // 큐가 가득 찬 상태면 에러
        {
            cout << "큐가 포화 상태입니다.";
            exit(0);
        }
        else
        {
            rear = (rear + 1) % MAX_SIZE;
            meeting[rear] = name;  
        } 
    }

    string dequeue() // 큐의 rear로 삭제 연산
    {
        if(isEmpty()) // 큐가 비어있는 상태면 에러
        {
            cout << "큐가 비어있습니다.";
            exit(0);
        }
        else
        {
            front = (front + 1) % MAX_SIZE;
            return meeting[front];
        }
    }

    string peek() // 큐의 front쪽 데이터 받아오기
    {
        if(isEmpty()) // 큐가 비어있는 상태면 에러
        {
            cout << "큐가 비어있습니다.";
            exit(0);
        }
        else
            return meeting[(front + 1) % MAX_SIZE];
    }

    void display() // 큐에 담겨있는 데이터 출력
    {
        int maxI = (front < rear) ? rear : rear + MAX_SIZE;

        for(int i = front+1; i <= maxI; i++)
        {
            cout << meeting[i % MAX_SIZE] << " ";
        }
        cout << endl;
    }
};

class Dequeue : public Queue // 3. 덱 이용해 남녀학생의 큐 구현
{
    public:
    void addFront(string name) // 덱의 front로 삽입 연산
    {
        if(isFull()) // 덱이 가득 찬 상태면 에러
        {
            cout << "큐가 포화상태입니다.";
            exit(0);
        }
        else 
        {
            meeting[front] = name;
            front = (front - 1) % MAX_SIZE;
        }
    }

    void addRear(string name) // 덱의 rear로 삽입 연산, 큐의 enqueue 연산과 동일
    {
        enqueue(name);
    }

    string deleteFront() // 덱의 front로 삭제 연산, 큐의 dequeue 연산과 동일
    {
        return dequeue();
    }

    string deleteRear() // 덱의 rear로 삭제 연산
    {
        if(isEmpty()) // 큐가 비어있는 상태면 에러
        {
            cout << "큐가 포화상태입니다.";
            exit(0);
        }
        else
        {
            string delName = meeting[rear];
            rear = (rear - 1) % MAX_SIZE;
            return delName;
        }
    }

    string getFront() // 덱의 front 위치 데이터 받아오기, 큐의 peek 연산과 동일
    {
        return peek();
    }

    string getRear() // 덱의 rear 위치 데이터 받아오기 
    {
        if(isEmpty()) // 큐가 비어있는 상태면 에러
        {
            cout << "큐가 포화상태입니다.";
            exit(0);
        }
        return meeting[rear];
    }
};

struct Student // 학생 정보 구조체
{
    int id;
    string gender;

    Student(int i = 0) // 학생 생성시 id는 발생 시간과 동일하고, 성별은 난수를 통해 무작위로 부여
    {
        id = i; // 학생 id
        
        // 난수 발생 관련 코드
        random_device rd;
        
        mt19937_64 gen(rd());
        
        uniform_int_distribution<int> range(0, 9); 

        if(range(gen) % 2 == 0) // 학생 성별, 난수 mod 2 == 0이면 male, == 1이면 female
            gender = "m";
        else
            gender = "f";
    }

    friend ostream& operator<<(ostream& os, const Student& student) // 미팅이 주선된 커플의 쌍을 출력할 때 사용. Student 객체와 << 연산자를 연이어 출력 가능케 해줌.
    {
        os << "Student " << student.id << ": " << student.gender;
        return os;
    }
};

class StudentQueue // 학생 정보 큐 
{
    private:
    int front;
    int rear;
    Student data[MAX_SIZE];

    public:
    StudentQueue()
    {
        front = -1;
        rear = -1;
    }

    bool isEmpty() // 큐가 비어있는지 확인
    {
        return front == rear;
    }

    bool isFull() // 큐가 가득 차있는지 확인
    {
        return front == (rear+1) % MAX_SIZE;
    }

    void enqueue(Student& value) // 큐의 front로 삽입 연산
    {
        if(!isFull()) // 큐가 가득 찬 상태면 에러
        {
            rear = (rear + 1) % MAX_SIZE;
            data[rear] = value;  
        } 
    }

    Student dequeue() // 큐의 rear로 삭제 연산
    {
        if(!isEmpty()) // 큐가 비어있는 상태면 에러
        {
            front = (front + 1) % MAX_SIZE;
            return data[front];
        }
        else
        {
            exit(0);
        }
    }
};

class MeetingSimulator // 미팅 시뮬레이션
{
    private:
    int simulation; // 시뮬레이션 할 최대 인원
    double enroll; // 단위 시간에 등록하는 학생 수

    int totalMaleWait; // 남학생 전체 대기 시간
    int totalFemaleWait; // 여학생 전체 대기 시간
    int meetingCount; // 미팅 주선 횟수
    Student matching[2][MAX_SIZE]; // 매칭된 학생들 행 0: 남학생, 행 1: 여학생
    StudentQueue femaleQue; // 여학생 큐
    StudentQueue maleQue; // 남학생 큐

    public:
    MeetingSimulator(int s, double e)
    {
        simulation = s;
        enroll = e;
        totalMaleWait = 0;
        totalFemaleWait = 0;
        meetingCount = 0;
    }

    double Random() // 랜덤값 반환( 0.0 - 1.0 )
    {
        return rand() / (double)RAND_MAX;
    }

    bool isNewStudent() // 단위시간 등록 학생 수보다 큰지 체크
    {
        return Random() > enroll;
    }

    void insertStudent(int time) // 학생 삽입
    {
        Student s(time); // 학생 정보 생성
        if(s.gender == "f") // 여학생인 경우
            femaleQue.enqueue(s);
        else // 남학생인 경우
            maleQue.enqueue(s); 
        cout << "학생 ID: " << s.id << ", 학생 성별: " << s.gender << endl; // 생성된 학생 정보
    }

    void printMatchingNum() // 매칭된 학생들의 쌍 출력
    {
        for(int i = 0; i < meetingCount; i++)
        {
            cout << "[" << matching[0][i] << ", " << matching[1][i] << "] "; // 남학생, 여학생 순으로 출력
        }
    }

    void readSimulationParameters() // 사용자 입력 처리
    {
        cout << "시뮬레이션 할 최대 시간: " << simulation << endl;
        cout << "단위 시간에 등록하는 학생 수: " << enroll << endl;
        cout << "============================" << endl;
    }

    void run() // 미팅 시뮬레이션 프로그램
    {
        int clock = 0;

        while(clock < simulation) // 시뮬레이션 시간 지났는지 체크하고 시간 내에서 시뮬레이션 반복
        {
            cout << "현재 시각: " << ++clock << endl;

            if(isNewStudent()) // 단위 시간에 등록하는 학생 수에 맞게 학생 등록
                insertStudent(clock); // 학생 큐에 삽입

            if(!femaleQue.isEmpty()&&!maleQue.isEmpty()) // 매칭 가능한 경우: 여학생 큐와 남학생큐가 모두 비어있지 않은 경우
            {
                meetingCount++; // 미팅 주선 횟수 + 1
                matching[0][meetingCount-1] = maleQue.dequeue(); // 매칭된 학생 큐에 남학생 삽입
                matching[1][meetingCount-1] = femaleQue.dequeue(); // 매칭된 학생 큐에 여학생 삽입

                // 남녀학생의 id 비교 통해 대기 시간 알아냄
                int mTime = matching[0][meetingCount-1].id; 
                int fTime = matching[1][meetingCount-1].id;

                if(mTime <= fTime) // 남학생의 대기 시간 추가
                    totalMaleWait += fTime - mTime;
                else // 여학생의 대기 시간 추가
                    totalFemaleWait += mTime - fTime;
            }
            else // 매칭 불가한 경우 PASS
            {
                continue;
            }
        }
    }

    void printStat() // 통계 출력
    {
        cout << "============================" << endl;
        cout << "미팅 주선에 성공한 커플의 쌍의 번호: ";
        printMatchingNum(); // 미팅 주선에 성공한 커플의 쌍
        cout << "미팅 주선 횟수: " << meetingCount << endl;
        cout << "남학생 평균 대기 시간: " << totalMaleWait / meetingCount * 1.0 << "분" << endl;
        cout << "여학생 평균 대기 시간: " << totalFemaleWait / meetingCount * 1.0 << "분" << endl;
        
    }
};

int main()
{
    Dequeue female; // 여학생 큐
    Dequeue male; // 남학생 큐
    string name, gender; // 학생 이름, 학생 성별
    

    cout << "미팅 주선 프로그램입니다." << endl; // 사용자 인터페이스 구성

    for(int i = 0; i < 5; i++) // 5명의 대상자 입력 받기
    {   
        cout << endl << "고객 이름: ";
        cin >> name;
        cout << "성별을 입력하세요(f or m) ";
        cin >> gender;

        if(gender == "f") // 여자인 경우
        {
            female.enqueue(name);
            
            if(male.isEmpty()) // 남학생 큐가 비어있는 경우
                cout << "아직 대상자가 없습니다. 기다려주십시요." << endl;
            else
                cout << endl << "커플이 탄생했습니다! " << male.dequeue() << "과 " << female.dequeue() << endl;
        }
        else if(gender == "m") // 남자인 경우
        {
            male.enqueue(name);

            if(female.isEmpty()) // 여학생 큐가 비어있는 경우
                cout << "아직 대상자가 없습니다. 기다려주십시요." << endl;
            else
                cout << endl << "커플이 탄생했습니다! " << male.dequeue() << "과 " << female.dequeue() << endl;
        }
    }

    int simulation; // 시뮬레이션 할 최대 인원
    double enroll; // 단위시간에 등록하는 학생 수
    cout << "================================" << endl;
    cout << "미팅 주선 시뮬레이션 프로그램" << endl << "시뮬레이션 할 최대 인원과 단위 시간에 등록하는 학생 수를 입력해주세요.";
    cin >> simulation >> enroll;
    MeetingSimulator meet(simulation, enroll);
    meet.readSimulationParameters();
    meet.run();
    meet.printStat();
}