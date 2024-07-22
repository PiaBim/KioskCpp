#ifndef _PAYMENT_H_
#define _PAYMENT_H_

#include <iostream>
#include "MainData.h"
#include "CoffeeMachine.h"
using namespace std;



class PayMent{
    private:
    MainData* mainData;
    CoffeeMachine* coffeeMachine;

    public:
    PayMent(MainData* data, CoffeeMachine* machine): mainData(data), coffeeMachine(machine) {};
    void Paymenu();
    void PayView();
    void CardUse();
    void SimpleUse();
    void PayGuide();
};






#endif

