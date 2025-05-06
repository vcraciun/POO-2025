#include <map>
#include <string>
#include <iostream>
#include"TraceFilter.h"
using namespace std;

/*int main()
{
    map<int, string> my_map = {
        {7, "hello"},
        {11, "home"},
        {50, "school"},
        {3, "POO"}
    };

    for (map<int, string>::iterator it = my_map.begin(); it != my_map.end(); ++it)
        cout << (*it).first << " " << it->second << endl;

    for (auto it : my_map)
        cout << it.first << " " << it.second << endl;

    return 0;
}*/

int main()
{
    TraceFilter filter("traces");

    // trebuie c++ 17+ ca sa mearga
    for (const auto& [fname, data] : filter)
    {
        cout << fname << endl;
        for (auto [api, extra] : data)
        {
            if (extra.count > 50)
                cout << "\t" << api << " " << extra.count << " " << extra.params << endl;
        }
    }

    return 0;
}