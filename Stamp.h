#ifndef _STAMP_H_
#define _STAMP_H_

#include "MainData.h"

class CoffeeMachine;

using namespace std;


class Stamp {
private:
    CoffeeMachine *coffeeMachine;
    MainData *mainData;
public:
    Stamp(MainData* data, CoffeeMachine* machine): mainData(data), coffeeMachine(machine) {};
    void Stampmenu();
    void StampView();
    void StampMenu();
    void StampUse();
    void StampGuide();
};


#endif