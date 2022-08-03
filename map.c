#include <stdio.h>
#include <string.h>
#include "linking_test_map.h"

// create struct with person1 variable
struct Address {
  char number[50];
  char street[50];
  char pincode[50];
};

struct Student {
    char name[50];
    int roll_number;
    int marks;
    struct Address * address;
};

void printAddress(struct Address * a){
     printf("Number :%s Street: %s, Pincode:%s \n",a->number,a->street,a->pincode);
}

void printStudent(void * s){
    struct Student* s1 = (struct Student*) s;
    printf("Name :%s Roll: %d, Marks:%d\n",s1->name,s1->roll_number,s1->marks);
    printAddress(s1->address);
}



int main() {

    struct Student s1,s2,s3,s4,s5;
    struct Address a1,a2,a3,a4,a5;

    strcpy(a1.number, "1");
    strcpy(a1.street, "street 1");
    strcpy(a1.pincode, "pincode 1");


    strcpy(a2.number, "2");
    strcpy(a2.street, "street 2");
    strcpy(a2.pincode, "pincode 2");


    strcpy(a3.number, "3");
    strcpy(a3.street, "street 3");
    strcpy(a3.pincode, "pincode 3");


    strcpy(a4.number, "4");
    strcpy(a4.street, "street 4");
    strcpy(a4.pincode, "pincode 4");

    strcpy(a5.number, "5");
    strcpy(a5.street, "street 5");
    strcpy(a5.pincode, "pincode 5");    

    strcpy(s1.name, "cyd1");
    s1.marks = 11;
    s1.roll_number = 12;
    s1.address = &a1;
    // printStudent(&s1);

    strcpy(s2.name, "cyd2");
    s2.marks = 12;
    s2.roll_number = 22;
    s2.address = &a2;
    // printStudent(&s2);

    strcpy(s3.name, "cyd3");
    s3.marks = 13;
    s3.roll_number = 23;
    s3.address = &a3;
    // printStudent(&s3);

    strcpy(s4.name, "cyd4");
    s4.marks = 14;
    s4.roll_number = 12;
    s4.address = &a4;
    // printStudent(&s4);

    strcpy(s5.name, "cyd5");
    s5.marks = 15;
    s5.roll_number = 25;
    s5.address = &a5;
    // printStudent(&s5);

    void *maps = CreateMap();
    Insert(maps,"student1",&s1);
    Insert(maps,"student2",&s2);
    Insert(maps,"student3",&s3);
    bool b =Insert(maps,"student4",&s4);
    printf("%d \n",b);

    void * get = Get(maps,"student4");
    printStudent(get);

    Update(maps,"student4",&s5);
    get = Get(maps,"student4");
    printStudent(get);
    
    DeleteMap(maps);
    get = Get(maps,"student4");
    if (get == NULL){
        printf("Map deleted \n");
    }
    
    maps = GetMap();
    Insert(maps,"student1",&s1);
    get = Get(maps,"student1");
    printStudent(get);
    get = Get(maps,"student2");
    if (get == NULL){
        printf("student2 not found \n");
    }
    
  return 0;
}