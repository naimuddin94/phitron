#include<bits/stdc++.h>
using namespace std;

class Student{
    public:
        char name[100];
        int role;
        char section;
        double GPA;
    
    Student(char n[], int r, char sec, double g){
        strcpy(name, n);
        role = r;
        section = sec;
        GPA = g;
    }
};

int main(){
    Student john("John Doe", 12, 'B', 4.75);


    cout << john.name << " -> " << john.role << " " << john.section << endl;

    return 0;
}