#pragma once
#include <vector>
#include <string>

class Object {
private:
    std::vector<Object*> child;
protected:
    int x, y;
    int width, length;
    std::string label;
    char color;
public:
    void PaintChild();
    Object(int x, int y, int w, int l, std::string label, char c) : x(x), y(y), width(w), length(l), label(label), color(c) {}
    virtual void Paint() = 0;
    virtual void Insert(Object*);

};

class Panel : public Object {
public:
    Panel(int x, int y, int w, int l, std::string label, char c) : Object(x, y, w, l, label, c) {}
    void Paint();
};

class Label : public Object {
public:
    Label(int x, int y, std::string label, char c) : Object(x, y, 0, 0, label, c) {}
    void Paint();
};

class Button : public Object {
public:
    Button(int x, int y, std::string label, char c) : Object(x, y, label.size()+4, 3, label, c) {}
    void Paint();
};