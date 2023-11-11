#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* (*Fptr)(const void* obj);
typedef void (*Fptr2)(const void* obj, const char* str); 

typedef enum {
  PERSON_TYPE
} TypeName;

typedef struct {
  Fptr serialize;
  Fptr2 deserialize;
} Vptr;

typedef struct {
  Vptr* vptr;
} Serializable;

typedef struct {
  TypeName t_name;
  Serializable* ptr;
  char* name;
  int age;
} Person;

char* serialize_person(const void* th) {
    Person* p = (Person*)th;
    char buffer[24];
    snprintf(buffer, sizeof(buffer), "Name:%s\nAge:%d",p->name, p->age);
    return strdup(buffer);
}

void deserialize_person(const void* th, const char* message) {  
  Person* p = (Person*)th;
  sscanf(message, "Name:%ms\nAge:%d", &p->name, &p->age);
}

int main() {
    Vptr vtbl = {
      .serialize = serialize_person,
      .deserialize = deserialize_person
    };
    
    Serializable ser;
    ser.vptr = &vtbl;
    
    Person p1 = { 
        .t_name = PERSON_TYPE,
        .ptr = &ser, 
        .name = "John",
        .age = 30
    };
    
 char* message = p1.ptr->vptr->serialize(&p1);
   Person p2 = {
    .t_name = PERSON_TYPE,
    .ptr = &ser,
    .name = "Unknown",
    .age = 0
   };
  p2.ptr->vptr->deserialize(&p2, message);
 return 0;
}
