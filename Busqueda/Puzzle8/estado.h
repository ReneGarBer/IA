#pragma once
#ifndef estado_h
#define estado_h
#include <string>

class estado {
    friend class puzzle8;

public:
    estado();
    void operator = (estado&);
    bool operator == (estado&);
    bool operator < (estado&);
    bool operator <= (estado&);

private:
    char puzzle[9];
    int blank;
    std::string path;
};

#endif //estado_h