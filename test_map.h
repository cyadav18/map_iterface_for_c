#ifndef LINKING_TEST_MAP_H
#define LINKING_TEST_MAP_H
#include<string>

    void * CreateMap();
    bool Insert( void * mainMap, std::string key, void * value);
    bool Update(void * mainMap, std::string key, void * value);
    void * Get(void * mainMap, std::string key);
    void Delete(void *mainMap,std::string key);
    
#endif 