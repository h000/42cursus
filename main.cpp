#include "List.hpp"
#include <iostream>

using namespace ft;

int main(void)
{
    List<int> lt;

    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(40);
    lt.push_back(50);

    // list<int>::iterator iter;
    // for (iter = lt.begin(); iter != lt.end(); ++iter){
    //     cout << *iter << ' ';
    // }
    // cout << endl;

    // iter = lt.begin();
    // iter++;
    // iter++;

    // // erase 삭제
    // list<int>::iterator iter2 = lt.erase(iter);
    // for (iter = lt.begin(); iter != lt.end(); ++iter){
    //     cout << *iter << ' ';
    // }
    // cout << endl;
    // cout << "iter2 : " << *iter2 << endl;

    // lt.push_back(10);
    // lt.push_back(10);

    // for (iter = lt.begin(); iter != lt.end(); ++iter){
    //     cout << *iter << ' ';
    // }
    // cout << endl;

    // // 리스트에서 원소 10 제거
    // lt.remove(10);

    // for (iter = lt.begin(); iter != lt.end(); ++iter){
    //     cout << *iter << ' ';
    // }
    // cout << endl;


    // // Predicate 함수에 해당하는 원소 제거 (30보다 크다)
    // lt.remove_if(Predicate);

    // for (iter = lt.begin(); iter != lt.end(); ++iter){
    //     cout << *iter << ' ';
    // }
    // cout << endl;

    return 0;
}