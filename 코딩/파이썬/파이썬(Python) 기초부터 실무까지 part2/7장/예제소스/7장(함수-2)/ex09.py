# 매개변수는 함수의 선언부에 존재하며 함수가 호출될 때 비로소 메모리에
# 할당이 된다. 함수가 종료되면 매개변수도 소멸이 된다.
# 매개변수도 지역변수의 일종이다.

def list_test(my_list) :
    print("함수 내 매개변수 my_list 의 주소값 : ", id(my_list))
    # 매개변수로 넘어온 my_list 에 새로운 리스트를 할당한다.
    # 매개변수로 넘어온 메모리의 주소를 버리고 새롭게 할당된 리스트의 주소를
    # 가지게 된다.
    my_list = [1, 2, 3, 4]
    print("함수 내 매개변수 my_list 에 할당 후의 주소값 : ", id(my_list))
    print("함수 내부에서의 my_list 값 출력 : ", my_list)
    return 

# my_list 타입은 list 이므로 변경가능객체(mutable object)
my_list = [100, 200, 300, 400]
print("함수 호출 전 my_list 의 주소값 : ", id(my_list))
list_test(my_list)
print("함수 호출 후 my_list 의 주소값 : ", id(my_list))
print("함수 외부에서의 my_list 값 출력 : ", my_list)