#ifndef Pointer_h
#define Pointer_h

#include <Windows.h>
#include "wtypes.h"

class Pointer{
public:
    Pointer();
    Pointer(int,int);
    void setCurrentPosition();
    void setPosition(int x, int y);
    int getXPointer() const;
    int getYPointer() const;
    void move();
    void nextLine();
    void prevLine();
    void setColor();
    void defaulColor();
    void operator ++();
    void operator --();
    void operator +=(int);
    void operator -=(int);
    void operator = (Pointer&);
    bool operator == (Pointer&);
    bool operator != (Pointer&);
private:
    COORD pointer;
};

#endif //Pointer_h