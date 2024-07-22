#ifndef _ORDERVIEW_H_
#define _ORDERVIEW_H_

#include "CoffeeMachine.h"
#include "MainData.h"

class OrderView {
private:
    CoffeeMachine* coffeeMachine;

public:
    OrderView(MainData* data); // 생성자 수정
    void MenuView();
};

#endif // _ORDERVIEW_H_
