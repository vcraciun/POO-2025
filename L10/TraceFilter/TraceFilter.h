#include <map>
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

struct extra {
    int count, params;
};

class Iterator {
    map<string, map<string, extra>>::iterator it;
public:
    Iterator(map<string, map<string, extra>>::iterator i) : it(i) {}
    bool operator!=(const Iterator&);
    Iterator& operator++();
    pair<string, map<string, extra>> operator*();
    //pair<string, map<string, extra>> operator->();
};


class TraceFilter {
private:
    map<string, map<string, extra>>my_map;
    void Procesare(string);
public:
    Iterator begin();
    Iterator end();

    TraceFilter(string);
};

