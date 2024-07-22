#ifndef __PROCESS_MENU_H__
#define __PROCESS_MENU_H__

#include <iostream>
#include <string>
#include "CoffeeMachine.h"
#include "OrderView.h"
#include "Point.h"
#include "MainData.h"
#include "Stamp.h"
#include "CouPon.h"
#include "Payment.h"

class Process {
private:
    MainData* mainData; // MainData 객체 추가
    CoffeeMachine* coffeeMachine; // CoffeeMachine 객체 추가

public:
    Process(MainData* data); // 생성자 수정
    void ProcessMenu();
    void showmenu();
    void OrderMenu();
};

#endif // __PROCESS_MENU_H__
