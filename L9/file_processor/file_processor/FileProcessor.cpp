#include "FileProcessor.h"

void FileProcessor::Scan(std::string path) {
    WIN32_FIND_DATA wfd;
    HANDLE hf = FindFirstFile((path + "/*").c_str(), &wfd);
    do {

        if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
            if (!strcmp(wfd.cFileName, ".") || !strcmp(wfd.cFileName, ".."))
                continue;
            else Scan((path + "/") + wfd.cFileName);
        }
        else {
            Procesare((path + "/") + wfd.cFileName);
        }

    } while (FindNextFile(hf,&wfd));
}

void FileProcessor::Procesare(std::string path) {
    std::ifstream fi(path);
    std::string var, extension;
    std::map<std::string, int> tempMap, finalMap;
    std::map<int, std::set<std::string>> sortMap;
    std::regex regexTemp("[a-zA-z]+", std::regex_constants::ECMAScript | std::regex_constants::icase) ;
    while (!fi.eof()) {
        fi >> var;
        if(std::regex_search(var, regexTemp)) // verificam pentru alpha only
            tempMap[var]++;
    }
    for (auto it : tempMap) {
        sortMap[it.second].insert(it.first);
    }
    auto it = sortMap.end();
    it--;
    int count = 0;
    while (it != sortMap.begin() && count < 5) {
        for (auto i : it->second) {
            if (count < 5) {
                finalMap[i] = it->first;
                count++;
            }
        }
    }
    extension = PathFindExtension(path.c_str());

    date[extension][path] = finalMap;
}

void FileProcessor::Print() {
    for (auto it1 : date) {
        std::cout << it1.first << std::endl;
        for (auto it2 : it1.second) {
            std::cout << '\t' << it2.first << ' ';
            for (auto it3 : it2.second) {
                std::cout << '(' << it3.first << ',' << it3.second << ") ";
            }
            std::cout << std::endl;
        }
    }
}