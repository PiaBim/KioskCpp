#include "Point.h"
#include "CoffeeMachine.h"
#include "Coffee.h"
#include <iostream>

using namespace std;

PointView::PointView(MainData* data, CoffeeMachine* machine)
    : mainData(data), coffeeMachine(machine) {  // MainData 포인터를 통해 초기화

}

void PointView::PointMenu() {
    cout << "[포인트 메뉴]" << endl;
    cout << "1. 적립 포인트 확인" << endl;
    cout << "2. 포인트 사용" << endl;
    cout << "3. 포인트 이용 안내" << endl;
    cout << "9. 종료" << endl;
}

void PointView::Pointmenu() {
    int choice;
    while (true) {
        PointMenu();
        cout << "입력: ";
        cin >> choice;
        if (choice == 1) {
            pointview();
        } else if (choice == 2) {
            pointuse();
        } else if (choice == 3) {
            pointguide();
        } else if (choice == 9) {
            break;
        } else {
            cout << "잘못 입력하셨습니다. 다시 입력하세요." << endl;
        }
    }
}

void PointView::pointview() {
    cout << "현재 적립 포인트: " << mainData->GetPoints() << endl;
}

void PointView::pointuse() {
    int pointsToUse;
    cout << "사용할 포인트를 입력하세요: ";
    cin >> pointsToUse;
    if (pointsToUse > mainData->GetPoints()) {
        cout << "포인트가 부족합니다." << endl;
    } else {
        // 포인트 사용 처리
        mainData->UsePoints(pointsToUse);
        cout << "포인트를 사용했습니다. 현재 남은 포인트: " << mainData->GetPoints() << endl;

        // 장바구니의 커피 가격을 할인
        for (auto& coffee : coffeeMachine->GetCart()) {
            int newPrice = coffee.GetPrice() - pointsToUse;
            coffee.setPrice(max(newPrice, 0)); // 가격이 음수가 되지 않도록 처리
            pointsToUse -= coffee.GetPrice();
            if (pointsToUse <= 0) break; // 남은 포인트가 없으면 종료
        }
    }
}

void PointView::pointguide() {
    cout << "[포인트 이용 안내]" << endl;
    cout << "포인트는 커피를 구매할 때 가격의 10%가 적립됩니다." << endl;
    cout << "적립된 포인트는 추후 구매 시 사용할 수 있습니다." << endl;
}
