#ifndef _CouPon_H_
#define _CouPon_H_

using namespace std;

#include "MainData.h"

class CoffeeMachine;

class Coupon{

    private:
    MainData* mainData;
    CoffeeMachine *coffeeMachine;

    public:
    Coupon(MainData* data, CoffeeMachine* machine): mainData(data), coffeeMachine(machine) {};
    void Couponmenu();
    void CouPonMenu();
    void CouponUse();
    void CouponGuide();
};


#endif