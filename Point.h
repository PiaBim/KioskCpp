#ifndef _POINTVIEW_H_
#define _POINTVIEW_H_

#include "MainData.h"

class CoffeeMachine;

class PointView {
private:
    MainData* mainData; // MainData 포인터
    CoffeeMachine *coffeeMachine;
public:
    PointView(MainData* data, CoffeeMachine* machine); // 생성자 수정
    void PointMenu();
    void Pointmenu();
    void pointview();
    void pointuse();
    void pointguide();
};

#endif // _POINTVIEW_H_
