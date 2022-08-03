#include "linking_test_map.h"
#include <map>
#include <iterator>
#include <string>
using namespace std;
typedef  map<string, void *> mapType;
void * CreateMap() {
    map<string, void*> *mainMap = new map<string, void*>;
    return mainMap;
}

bool Insert( void * mainMap,char * key, void * value){
    string ky = key;
    pair<map<string, void *>::iterator,bool> ret;
    mapType *mapPtr = static_cast<mapType*>(mainMap);
    ret = (*mapPtr).insert(make_pair(ky,value));
    if (ret.second == false) {
        //element with key already present in the map
        return false;
    }
    return true;
}

bool Update(void * mainMap,char * key, void * value){
    string ky = key;
    mapType *mapPtr = static_cast<mapType*>(mainMap);
    auto it = (*mapPtr).find(ky);
    if (it != (*mapPtr).end()){
        it->second = value;
        return true;
    }
    return false;
}

void * Get(void * mainMap,char * key){
    mapType *mapPtr = static_cast<mapType*>(mainMap);
    string ky = key;
    auto it = (*mapPtr).find(ky);
    if (it != (*mapPtr).end()){
        return it->second;
    }
    return nullptr;
}

void Delete(void *mainMap,char * key){
    mapType *mapPtr = static_cast<mapType*>(mainMap);
    string ky = key;
    (*mapPtr).erase(ky);
    return;
}

void DeleteMap(void *mainMap){
    mapType *mapPtr = static_cast<mapType*>(mainMap);
    (*mapPtr).clear();
    delete mapPtr;
    return;
}
