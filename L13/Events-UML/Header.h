#pragma once

#include <vector>
#include <string>
#include <windows.h>
#include <functional>
using namespace std;

class Object
{
protected:
    vector<Object*> v;
    vector<function<bool(Object*, unsigned char, int, int, char)>> events;
public:
    static void ConsoleEvents(bool enable);
    static bool HandleEvents(Object* inst);

    void Adauga(Object*);
    bool HandleEvent(Object* obj, unsigned char m_down, int x, int y, char key);
    Object* FindObject(string name);

    virtual void Desenare() = 0;
    virtual pair<int, int> GetPos() = 0;
    virtual pair<int, int> GetDim() = 0;
    virtual string GetName() = 0;
};

class Window: public Object
{
    int x, y, w, h;
    string s;
    Object* parent;
    unsigned short color;
public:
    void Desenare();
    pair<int, int> GetPos();
    pair<int, int> GetDim();
    string GetName();
    Window(int x, int y, int w, int h, unsigned short color, string s, Object* parent = 0, function<bool(Object*, unsigned char, int, int, char)> ev = nullptr);
};

class Panel : public Object
{
    int x, y, w, h;
    string s;
    Object* parent;
    unsigned short color;
public:
    void Desenare();
    pair<int, int> GetPos();
    pair<int, int> GetDim();
    string GetName();
    Panel(int x, int y, int w, int h, unsigned short color, string s, Object* parent = 0, function<bool(Object*, unsigned char, int, int, char)> ev = nullptr);
};

class Buton : public Object
{
    int x, y, w, h;
    string s;
    Object* parent;
    unsigned short  color;
    bool pressed = false;
public:
    void Desenare();
    pair<int, int> GetPos();
    pair<int, int> GetDim();
    string GetName();
    Buton(int x, int y, unsigned short color, string s, Object* parent = 0, function<bool(Object*, unsigned char, int, int, char)> ev = nullptr);
    void Press(bool down);
};

class Label : public Object
{
    int x, y, w, h;
    string s;
    Object* parent;
    unsigned short  color;
public:
    void Desenare();
    pair<int, int> GetPos();
    pair<int, int> GetDim();
    string GetName();
    Label(int x, int y, unsigned short color, string s, Object* parent = 0, function<bool(Object*, unsigned char, int, int, char)> ev = nullptr);
    void ChangeLabel(string new_label);
};