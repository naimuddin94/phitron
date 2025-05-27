#include<bits/stdc++.h>>

using namespace std;

int* p;

void fun(){
    int* x = new int;
    *x = 100;
    p = x;
    cout << "Fun-> " << p << "-- " << *p << endl;
    return;
}

int main(){
    fun();
    cout << "Main-> " << p << "-- " << *p << endl;
    return 0;
}