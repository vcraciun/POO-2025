#include "header.h"

void Object::ConsoleEvents(bool enable)
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    DWORD prevMode;    

    if (GetConsoleMode(hInput, &prevMode)) 
    {
        DWORD newMode;
        if (enable)
            newMode = (prevMode | ENABLE_MOUSE_INPUT) & ~(ENABLE_QUICK_EDIT_MODE | ENABLE_INSERT_MODE);
        else
            newMode = (prevMode & ~ENABLE_MOUSE_INPUT) | (ENABLE_QUICK_EDIT_MODE | ENABLE_INSERT_MODE);
        SetConsoleMode(hInput, newMode);
    }    
}

void Object::Adauga(Object* obj)
{
    v.push_back(obj);
}

bool Object::HandleEvents(Object* inst)
{
    HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
    INPUT_RECORD inputRecord;
    DWORD events;
    COORD mousePos;
    char key = 0;
    unsigned char m_down = 0;
    int mx = 0;
    int my = 0;
    bool require_repaint = false;

    ReadConsoleInput(hInput, &inputRecord, 1, &events);

    if (inputRecord.EventType == MOUSE_EVENT)
    {
        MOUSE_EVENT_RECORD mer = inputRecord.Event.MouseEvent;
        mousePos = mer.dwMousePosition;
        mx = mousePos.X;
        my = mousePos.Y;

        if (mer.dwEventFlags == 0)
        {
            if (mer.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED)
                m_down = 1;
            if (mer.dwButtonState & RIGHTMOST_BUTTON_PRESSED)
                m_down = 2;
        }
    }

    if (inputRecord.EventType == KEY_EVENT && inputRecord.Event.KeyEvent.bKeyDown)
        key = inputRecord.Event.KeyEvent.uChar.AsciiChar;
    
    for (auto ev : inst->events)
        require_repaint = require_repaint || ev(inst, m_down, mx, my, key);

    for (auto child : inst->v)
        require_repaint = require_repaint || child->HandleEvent(child, m_down, mx, my, key);

    return require_repaint;
}

bool Object::HandleEvent(Object* obj, unsigned char m_down, int x, int y, char key)
{
    bool require_repaint = false;

    for (auto it : events)
        require_repaint = require_repaint || it(this, m_down, x, y, key);    

    for (auto child : v)
        require_repaint = require_repaint || child->HandleEvent(child, m_down, x, y, key);

    return require_repaint;
}

Object* Object::FindObject(string name)
{
    for (auto obj : v)
    {
        if (obj && obj->GetName() == name)
            return obj;
        else
        {
            Object* next_obj = obj->FindObject(name);
            if (next_obj)
                return next_obj;
        }
    }
    return 0;
}

Window::Window(int x, int y, int w, int h, unsigned short color, string s, Object* parent, function<bool(Object*, unsigned char, int, int, char)> ev)
{
    this->w = w;
    this->h = h;
    this->parent = parent;
    this->s = s;
    this->color = color;
    if (ev)
        this->events.push_back(ev);

    if (!parent)
    {
        this->x = x;
        this->y = y;
    }
    else
    {
        auto pos = parent->GetPos();
        this->x = pos.first + x;
        this->y = pos.second + y;
    }

    if (parent)
        parent->Adauga(this);
}

void Window::Desenare()
{
    HANDLE hh = GetStdHandle(STD_OUTPUT_HANDLE);   
    char fill1[256] = { 0 };
    char fill2[256] = { 0 };
    memset(fill1, 205, (w - 6 - s.size()) / 2); 
    memset(fill2, 205, w - 2);    
    SetConsoleTextAttribute(hh, color);
    for (int i=0; i < h; i++)
    {
        SetConsoleCursorPosition(hh, { (short)x, (short)(y + i) });
        if (i == 0)
            printf("%c%s%c %s %c%s%c", 201, fill1, 185, s.c_str(), 204, fill1, 187);
        else
        {
            if (i == h - 1)
                printf("%c%s%c", 200, fill2, 188);
            else
                printf("%c%*c", 186, w - 1, 186);
        }
    }

    //X
    SetConsoleCursorPosition(hh, { (short)(x+w-4), (short)y });
    printf("%cx%c", 185, 204);

    SetConsoleTextAttribute(hh, 0x07);

    for (auto object : v)
        object->Desenare();
}

pair<int, int> Window::GetPos()
{
    return { x,y };
}

pair<int, int> Window::GetDim()
{
    return { w, h };
}

string Window::GetName()
{
    return s;
}

Panel::Panel(int x, int y, int w, int h, unsigned short color, string s, Object* parent, function<bool(Object*, unsigned char, int, int, char)> ev)
{
    this->w = w;
    this->h = h;
    this->parent = parent;
    this->s = s;
    this->color = color;
    if (ev)
        this->events.push_back(ev);

    if (!parent)
    {
        this->x = x;
        this->y = y;
    }
    else
    {
        auto pos = parent->GetPos();
        this->x = pos.first + x;
        this->y = pos.second + y;
    }

    if (parent)
        parent->Adauga(this);
}

void Panel::Desenare()
{
    HANDLE hh = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hh, color);
    char fill1[256] = { 0 };
    char fill2[256] = { 0 };
    memset(fill1, 196, w - 7 - s.size());
    memset(fill2, 196, w - 2);

    for (int i = 0; i < h; i++)
    {
        SetConsoleCursorPosition(hh, { (short)x, (short)(y + i) });
        if (i == 0)
            printf("%c%c%c %s %c%s%c", 218, 196, 180, s.c_str(), 195, fill1, 191);
        else
            if (i == h - 1)
                printf("%c%s%c", 192, fill2, 217);
            else
                printf("%c%*c", 179, w-1, 179);
    }

    //umbra
    SetConsoleTextAttribute(hh, 0x00);
    for (int i = 0; i < h; i++)
    {
        if (i < h - 1)
        {
            SetConsoleCursorPosition(hh, { (short)(x + w), (short)(y + i + 1) });
            printf("%c", 219);
        }
        else
        {
            SetConsoleCursorPosition(hh, { (short)(x + 1), (short)(y + i + 1) });
            for (int j = 0; j < w; j++)
                printf("%c", 219);
        }
    }
    
    SetConsoleTextAttribute(hh, 0x07);

    for (auto object : v)
        object->Desenare();
}

pair<int, int> Panel::GetPos()
{
    return { x,y };
}

pair<int, int> Panel::GetDim()
{
    return { w, h };
}

string Panel::GetName()
{
    return s;
}

Buton::Buton(int x, int y, unsigned short color, string s, Object* parent, function<bool(Object*, unsigned char, int, int, char)> ev)
{
    this->w = s.size() + 4;
    this->h = 3;
    this->parent = parent;
    this->s = s;
    this->color = color;
    if (ev)
        this->events.push_back(ev);

    if (!parent)
    {
        this->x = x;
        this->y = y;
    }
    else
    {
        auto pos = parent->GetPos();
        this->x = pos.first + x;
        this->y = pos.second + y;
    }

    if (parent)
        parent->Adauga(this);
}

void Buton::Desenare()
{
    HANDLE hh = GetStdHandle(STD_OUTPUT_HANDLE);
    char fill[256] = { 0 };
    memset(fill, 196, s.size() + 2);
    SetConsoleTextAttribute(hh, color);

    if (!pressed)
    {
        for (int i = 0; i < h; i++)
        {
            SetConsoleCursorPosition(hh, { (short)x,(short)(y + i) });
            if (i == 0)
                printf("%c%s%c", 218, fill, 191);
            else
                if (i == h - 1)
                    printf("%c%s%c", 192, fill, 217);
                else
                    printf("%c %s %c", 179, s.c_str(), 179);
        }

        //umbra
        SetConsoleTextAttribute(hh, 0x00);
        for (int i = 0; i < h; i++)
        {
            if (i < h - 1)
            {
                SetConsoleCursorPosition(hh, { (short)(x + w), (short)(y + i + 1) });
                printf("%c", 219);
            }
            else
            {
                SetConsoleCursorPosition(hh, { (short)(x + 1), (short)(y + i + 1) });
                for (int j = 0; j < w; j++)
                    printf("%c", 219);
            }
        }
    }
    else
    {
        for (int i = 0; i < h; i++)
        {
            SetConsoleCursorPosition(hh, { (short)(x + 1),(short)(y + i + 1) });
            if (i == 0)
                printf("%c%s%c", 218, fill, 191);
            else
                if (i == h - 1)
                    printf("%c%s%c", 192, fill, 217);
                else
                    printf("%c %s %c", 179, s.c_str(), 179);
        }
    }

    SetConsoleTextAttribute(hh, 0x07);

    for (auto object : v)
        object->Desenare();
}

pair<int, int> Buton::GetPos()
{
    return { x,y };
}

pair<int, int> Buton::GetDim()
{
    return { w, h };
}

void Buton::Press(bool down)
{
    pressed = down;
}

string Buton::GetName()
{
    return s;
}


Label::Label(int x, int y, unsigned short color, string s, Object* parent, function<bool(Object*, unsigned char, int, int, char)> ev)
{
    this->w = s.size() + 2;
    this->h = 1;
    this->parent = parent;
    this->s = s;
    this->color = color;
    if (ev)
        this->events.push_back(ev);

    if (!parent)
    {
        this->x = x;
        this->y = y;
    }
    else
    {
        auto pos = parent->GetPos();
        this->x = pos.first + x;
        this->y = pos.second + y;
    }

    if (parent)
        parent->Adauga(this);
}

void Label::Desenare()
{
    HANDLE hh = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hh, color);
    SetConsoleCursorPosition(hh, { (short)x,(short)(y) });
    char* c = new char[w + 1];
    memset(c, ' ', w);
    c[w] = 0;
    printf("%s", c);
    delete[] c;
    SetConsoleCursorPosition(hh, { (short)(x + w / 2 - s.size() / 2),(short)(y) });
    printf("%s", s.c_str());
    SetConsoleTextAttribute(hh, 0x07);

    for (auto object : v)
        object->Desenare();
}

pair<int, int>  Label::GetPos()
{
    return { x,y };
}

pair<int, int> Label::GetDim()
{
    return { w, h };
}

void Label::ChangeLabel(string new_label)
{
    s = new_label;
}

string Label::GetName()
{
    return s;
}
