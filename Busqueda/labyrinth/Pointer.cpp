#include "Pointer.h"

Pointer::Pointer(){
    setCurrentPosition();
}

Pointer::Pointer(int x, int y){
    setPosition(x,y);
}

void Pointer::setCurrentPosition(){
    HANDLE hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi = { };
    BOOL ok = GetConsoleScreenBufferInfo(hConsoleOutput, &csbi);
    this->pointer.X = csbi.dwCursorPosition.X;
    this->pointer.Y = csbi.dwCursorPosition.Y;
}

void Pointer::setPosition(int x, int y){
    this->pointer.X = x;
    this->pointer.Y = y;
}

void Pointer::move(){
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hcon, this->pointer);
}

void Pointer::nextLine(){
    this->pointer.X++;
}

void Pointer::prevLine(){
    this->pointer.X--;
}

void Pointer::operator ++(){
    this->pointer.Y++;
    this->pointer.Y++;
}

void Pointer::operator --(){
    this->pointer.Y--;
    this->pointer.Y--;
}

void setColor(int color){
    if(color < 0)
        color = 0;
    if(color > 16)
        color = 16;

    HANDLE ventana = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(ventana, color);    
}