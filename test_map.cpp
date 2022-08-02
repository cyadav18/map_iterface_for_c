#include "test_map.h"
#include <map>
#include <iterator>
using namespace std;

void * CreateMap() {
    map<string, void*> *mainMap = new map<string, void*>;
    return mainMap;
}

bool Insert( void * mainMap,string key, void * value){
    using mapType = map<string, void *>;
    mapType *mapPtr = static_cast<mapType*>(mainMap);
    (*mapPtr).insert(make_pair(key,value));
    return true;
}

bool Update(void * mainMap,string key, void * value){
    using mapType = map<string, void *>;
    mapType *mapPtr = static_cast<mapType*>(mainMap);
    auto it = (*mapPtr).find(key);
    if (it != (*mapPtr).end()){
        it->second = value;
        return true;
    }
    return false;
}

void * Get(void * mainMap,string key){
    using mapType = map<string, void *>;
    mapType *mapPtr = static_cast<mapType*>(mainMap);
    auto it = (*mapPtr).find(key);
    if (it != (*mapPtr).end()){
        return it->second;
    }
    return nullptr;
}

void Delete(void *mainMap,string key){
    using mapType = map<string, void *>;
    mapType *mapPtr = static_cast<mapType*>(mainMap);
    (*mapPtr).erase(key);
}
