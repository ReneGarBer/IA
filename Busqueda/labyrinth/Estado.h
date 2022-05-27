#pragma once
#ifndef Estado_h
#define Estado_h
#include <string>

class Estado{
    friend class Laberinto;
public:
    Estado();
    Estado(int,int,int,std::string&);
    void operator = (Estado&);
protected:
    int i;
    int j;
    int tipo;
    std::string path;
};

#endif //Estad_h