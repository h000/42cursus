#include <iostream>

using namespace std;

class First
{
public:
    virtual void MyFunc() // 가상 함수
    {
        cout << "First::MyFunc()" << endl;
    }
};

class Second : public First
{
public:
    virtual void MyFunc() // 가상 함수
    {
        cout << "Second::MyFunc()" << endl;
    }
};

class Third : public Second
{
public:
    virtual void MyFunc() // 가상 함수
    {
        cout << "Third::MyFunc()" << endl;
    }
};

int main()
{
    Third* third = new Third;
    Second* second = third; // Ok, third를 만들때 이미 Second, First 객체를 묵시적으로 만들었음
    First* first = second;  // Ok, second를 만들때 이미 First 객체를 묵시적으로 만들었음

    cout << "address of third (즉, thrid 안의 내용  = 주소) " << third << endl;
    cout << "address of second(즉, second 안의 내용 = 주소) " << second << endl;
    cout << "address of first (즉, first 안의 내용  = 주소) " << first << endl;

    // 가상함수로 선언된 맴버 함수를 접근할 때에는 실제 객체의 맴버 함수 호출
    // 가상함수로 선언된 third = second = first 인 상황이므로 third의 맴버 함수 호출
    first->MyFunc();
    second->MyFunc();
    third->MyFunc();

    system("pause");   // VC++ 에서만
    return 0;
}