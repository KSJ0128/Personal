/*
**
난수 생성
1. ctime 헤더 추가: time() 사용하기 위해서
2. srand(time(0))   // 이유는 모름
3. rand() % n: 0 ~ n-1 까지의 난수 생성
**

<파일 입출력>
파일 쓰기: ofstream 유형 변수 필요( ofstream output )
- output.open(파일명): 파일 생성, 기존 파일 있다면 삭제 후 생성  // open() 통해 파일을 스트림과 연결
- ofstream output(파일명): 파일 출력 객체 생성 후 파일 여는 작업 수행
- output << : 데이터 쓰는 작업
- output.close(): 쓰기 작업 마침

파일 읽기: ifstream 유형 변수 필요( ifstream input )
- input.open(파일명): 입력 위해 파일 여는 작업
- ifstream input(파일명): 파일 입력 객체 생성 후 파일 여는 작업 수행
- input >> : 데이터 읽어 변수에 저장
- input.close(): 읽기 작업 마침

헤더: string

string은 <string>에 정의된 클래스
- 문자열에서 첫 번째 인덱스는 0이다.
- +로 두 문자열을 연결할 수 있다.   // string s3 = s1 + s2

length() = size(): 문자열의 문자 수 반환
- string.length(), string.size()로 사용
- s.length() - 1를 벗어나는 인덱스 사용하면 안된다.

at(index): 인덱스의 문자 반환
-string.at(index)로 사용

문자열 비교(index 0부터 n-1까지 각 문자 별로 비교)
- "ABC"는 "ABE" 보다 작다.

getline(cin, 문자열, 구분 문자)
- 구분 문자를 기준으로 문자열을 입력 받는다.   // 기본 구분 문자: '\n'
- 공백 포함된 문자열 받을 수 있다.

스트림 조정자: iomanip 헤더 파일에 포함
- setprecision: 실수에서 표시될 전체 자릿수 지정.
- fixed: 실수를 고정 소수점 형식 표시. fixed 뒤에 setprecision 사용해 소수점 자릿수 지정 가능.
- showpoint: 소수 부분 표시, 없더라도 0이 표시됨.
- setw: 출력되는 영역의 폭 지정
- left, right: 왼쪽, 오른쪽 정렬 출력

--------------------------------------------------------------------------------
헤더: cmath

삼각 함수:
sin(radians), cos(""), tan(""): radians 각도의 삼각함수값
- sin(PI / 6) = 0.5
asin(a), acos(a), atan(a): 역삼각함수의 라디안 각도값
- asin(0.5) = PI / 6

<삼각형의 세 변의 길이를 알 때 각>
A = acos((a*a - b*b - c*c) / (-2*b*c)) // A의 대변이 a

지수 함수:
exp(x): e(자연상수)의 x 제곱
log(x): x의 자연로그 값
log10(x): x의 상용로그 값 
pow(a,b): a의 b제곱
sqrt(x): x의 루트 값

라운드 함수:
ceil(x): 반올림
floor(x): 반내림

min, max, abs: 최솟값, 최댓값, 절댓값
- max(4.4, 5.0) = 5.0

문자 함수:
isdigit(ch): 문자가 숫자면 참 반환
isalpha(ch): 문자가 대소문자면 참 반환
isalnum(ch): 문자가 대소문자나 숫자면 참 반환
islower(ch): 문자가 소문자면 참 반환
isupper(ch): 문자가 대문자면 참 반환
isspace(ch): 문자가 공백이면 참 반환
tolower(ch): 문자의 소문자 반환
toupper(ch): 문자의 대소문자 반환

ASCII 코드( 문자끼리 크기 비교 가능 )
'0' - '9': 48 - 57
'A' - 'Z': 65 - 90
'a' - 'z': 97 - 122

char <-> 숫자 형 변환
정수 -> char: 데이터 하위 8비트만 사용
- char c = 0XFF41(16진수는 앞에 0X 붙임) -> c = 'A'

실수 -> char: 실수 -> 정수 -> char
- char c = 65.25 -> c = 'A'

char -> 숫자: 문자의 ASCII 값이 지정된 숫자로 변경
- int i = 'A' -> i = 65

static_cast<char>(value): 숫자인 value값을 char 형태로 명시적 형변환
*/