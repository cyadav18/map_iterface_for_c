#include <iostream>
#include <map>
#include <iterator>
#include "test_map.h"
using namespace std;

struct Student {
  string name;
  int roll_number;
  int marks;
};

void printStudent(void* student){
    Student * s = static_cast<Student *>(student); 
    cout<<"Name:"<<s->name<<" Roll:"<<s->roll_number<<" Marks"<<s->marks<<endl;
}

void printMap(void *mainMap){
    using mapType = map<string, void*>;
    mapType *mapPtr = static_cast<mapType*>(mainMap);
    map<string, void*>::iterator itr;
    for (itr = (*mapPtr).begin(); itr != (*mapPtr).end(); ++itr) {
        cout << '\t' << itr->first << '\t';
        printStudent(itr->second);
    }
    cout << endl;
}

int main() {
    cout << "Hello World!"<<endl;
    Student s1,s2,s3,s4,s5;
    void * ptrs1;
    s1.name = "cyd1";
    s1.marks = 11;
    s1.roll_number = 12;

    s2.name = "cyd2";
    s2.marks = 12;
    s2.roll_number = 22;

    s3.name = "cyd3";
    s3.marks = 13;
    s3.roll_number=32;

    s4.name = "cyd4";
    s4.marks = 14;
    s4.roll_number=42;

    s5.name = "cyd5";
    s5.marks=15;
    s5.roll_number=52;

    void *maps = CreateMap();
    cout<<"creating map"<<endl;
    Insert(maps,"student1",&s1);
    Insert(maps,"student2",&s2);
    Insert(maps,"student3",&s3);
    Insert(maps,"student4",&s4);
    printMap(maps);

    //Get
    cout<<"Get"<<endl;
    ptrs1 = Get(maps,"student1");
    printStudent(ptrs1);

    //update
    cout<<"update"<<endl;
    Update(maps,"student1",&s5);
    printMap(maps);

    //Get
    cout<<"Get updated"<<endl;
    ptrs1 = Get(maps,"student1");
    printStudent(ptrs1);

    //Delete
    cout<<"Deleting"<<endl;
    Delete(maps,"student1");
    printMap(maps);

    return 0;
}
