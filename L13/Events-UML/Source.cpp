#include "header.h"

int main()
{
    system("cls");
    Object::ConsoleEvents(true);
    bool running = true;

    auto onExit = [&running](Object* obj, unsigned char m_down, int x, int y, char key) -> bool {
        HANDLE hh = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(hh, { 0, 47 });
        SetConsoleTextAttribute(hh, 0x07);

        auto pos = obj->GetPos();
        auto dim = obj->GetDim();

        printf("%d, %d, %d, \'%c\'        ", m_down, x, y, (!key)? ' ':key);

        if (m_down == 1)
        {
            if ((x == pos.first + dim.first - 3) && (y == pos.second))
            {
                running = false;
                return true;
            }
        }

        if (key == 'q')
        {
            running = false;
            return true;
        }

        return false;
    };

    auto buton5_event = [&running](Object* obj, unsigned char m_down, int x, int y, char key) -> bool {
        Buton* buton = dynamic_cast<Buton*>(obj);
        static bool was_pressed = false;
        auto pos = obj->GetPos();
        auto dim = obj->GetDim();
        if (x >= pos.first && y >= pos.second && x < pos.first + dim.first && y < pos.second + dim.second)
        {
            if (m_down == 1)
            {
                buton->Press(true);
                was_pressed = true;
                return true;
            }
            else
                if (was_pressed)
                {
                    buton->Press(false)                    ;
                    running = false;
                    return true;
                }            
        }
        return false;
    };

    auto generic_buton = [](Object* obj, unsigned char m_down, int x, int y, char key) -> bool {
        Buton* buton = dynamic_cast<Buton*>(obj);
        static bool was_pressed = false;
        auto pos = obj->GetPos();
        auto dim = obj->GetDim();
        if (x >= pos.first && y >= pos.second && x < pos.first + dim.first && y < pos.second + dim.second)
        {
            if (m_down == 1)
            {
                buton->Press(true);
                was_pressed = true;
                return true;
            }
            else
                if (was_pressed)
                {
                    was_pressed = false;
                    buton->Press(false);
                    return true;
                }
        }
        return false;
    };

    Object* p1 = new Window(5, 5, 100, 40, 0x1F, "Window Title", 0, onExit);

    auto change_label = [&p1](Object* obj, unsigned char m_down, int x, int y, char key) -> bool {
        Buton* buton = dynamic_cast<Buton*>(obj);
        static bool was_pressed = false;
        auto pos = obj->GetPos();
        auto dim = obj->GetDim();
        if (x >= pos.first && y >= pos.second && x < pos.first + dim.first && y < pos.second + dim.second)
        {
            if (m_down == 1)
            {
                buton->Press(true);
                was_pressed = true;
                Object* label3 = p1->FindObject("Label 3");
                if (label3)
                {
                    Label* label = dynamic_cast<Label*>(label3);
                    label->ChangeLabel("** This is OOP **");
                }
                return true;
            }
            else
                if (was_pressed)
                {
                    was_pressed = false;
                    buton->Press(false);
                    return true;
                }
        }

        return false;
    };

    Object* p2 = new Panel(5, 5, 40, 30, 0x90, "Panel 2", p1);
    Object* p3 = new Panel(55, 5, 40, 30, 0xA0, "Panel 3", p1);
    Object* p4 = new Panel(5, 5, 30, 11, 0x4f, "Panel 4", p2);

    Object* b1 = new Buton(10, 3, 0xf0, "Buton 1", p4, generic_buton);
    Object* b2 = new Buton(15, 18, 0xf0, "Buton 2", p2, generic_buton);
    Object* b3 = new Buton(15, 23, 0xf0, "Change Label 3", p2, change_label);
    Object* b4 = new Buton(15, 8, 0xf0, "Buton 4", p3, generic_buton);
    Object* b5 = new Buton(15, 23, 0xf0, "EXIT", p3, buton5_event);

    Object* L1 = new Label(10, 8, 0x1f, "Label 1", p4);
    Object* L2 = new Label(15, 13, 0x1f, "Label 2", p3);
    Object* L3 = new Label(15, 20, 0x1f, "Label 3", p3);   

    p1->Desenare();

    while (running)
    {
        if (Object::HandleEvents(p1))
            p1->Desenare();
    }

    HANDLE hh = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hh, 0x07);
    SetConsoleCursorPosition(hh, { 0, 50 });    
    Object::ConsoleEvents(false);
    system("cls");

    return 0;
}



