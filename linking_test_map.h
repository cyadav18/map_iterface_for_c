#ifndef LINKING_TEST_MAP_H
#define LINKING_TEST_MAP_H

#include<string.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

void * CreateMap();
bool Insert( void * mainMap, char * key, void * value);
bool Update(void * mainMap, char * key, void * value);
void * Get(void * mainMap, char * key);
void Delete(void *mainMap,char * key);
void DeleteMap(void *mainMap);

#ifdef __cplusplus
}
#endif

#endif
