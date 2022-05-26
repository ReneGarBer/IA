#ifndef Pointer_h
#define Pointer_h

#include <Windos.h>
#include "wtypes.h"

class Pointer{
public:
    Pointer();
    Pointer(int,int);
    void setColor(int);
    void setCurrentPosition();
    void setPosition(int x, int y);
    void move();
    void nextLine();
    void prevLine();
    void setColor();
    void defaulColor();
    void operator ++();
    void operator --();
private:
    COORD pointer;
};

#endif //Pointer_h