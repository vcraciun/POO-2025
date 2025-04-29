#pragma once
#include <string>
#include <map>
#include <Windows.h>
#include <fstream>
#include <iostream>
#include <cstring>
#include <regex>
#include <set>
#include <Shlwapi.h>

class FileProcessor {
private:
    std::map<std::string, std::map<std::string, std::map<std::string, int>>> date;

public:
    void Scan(std::string path);
    void Procesare(std::string path);
    void Print();

};