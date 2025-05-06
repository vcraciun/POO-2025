#include "TraceFilter.h"
#include<Windows.h>

TraceFilter::TraceFilter(string traces) {
    
    WIN32_FIND_DATA wfd;
    HANDLE hf = FindFirstFile((traces + "/*").c_str(), &wfd);
    if (hf == INVALID_HANDLE_VALUE)
        return;
    do {

        if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if (!strcmp(wfd.cFileName, ".") || !strcmp(wfd.cFileName, ".."))
                continue;
        }
        else {
            Procesare((traces + "/") + wfd.cFileName);
        }

    } while (FindNextFile(hf, &wfd));

}

void TraceFilter::Procesare(string s) {
    ifstream file(s);
    string buffer;
    string temp;
    int nr_param = 0;
    while (!file.eof()) {
        getline(file, buffer);
        if (buffer[0] == ' ') {
            int k = buffer.find("]");
            temp = buffer.substr(5, k - 14);
            if (buffer.find("()") != string::npos) {
                nr_param = 0;
            }
            else {
                for (auto it : buffer) {
                    if (it == ',')
                        nr_param++;
                }
                nr_param++;
            }
            my_map[s][temp].params = nr_param;
            my_map[s][temp].count++;
        }
    }
    //for (auto it : my_map) {
    //    cout << it.first << '\n';
    //}
}

bool Iterator::operator!=(const Iterator& other) {
    return it != other.it;
}

Iterator& Iterator::operator++() {
    it++;
    return *this;
}

pair<string, map<string, extra>> Iterator::operator*() {
    return *it;
}

pair<string, map<string, extra>> Iterator::operator->() {
    return *it;
}

Iterator TraceFilter::begin() {
    return Iterator(my_map.begin());
}

Iterator TraceFilter::end() {
    return Iterator(my_map.end());
}