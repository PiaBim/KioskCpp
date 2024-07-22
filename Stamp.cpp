#include "Stamp.h"
#include <iostream>

using namespace std;

void Stamp::StampMenu() {
    cout << "1. 적립한 스탬프 확인" << endl;
    cout << "2. 스탬프 사용" << endl;
    cout << "3. 스탬프 가이드" << endl;
    cout << "9. 종료" << endl;
}

void Stamp::Stampmenu() {
    while (true) {
        StampMenu();
        cout << "입력: ";
        int choice;
        cin >> choice;
        switch (choice) {
        case 1:
            StampView();
            break;
        case 2:
            StampUse();
            break;
        case 3:
            StampGuide();
            break;
        case 9:
            cout << "종료" << endl;
            return;
        default:
            cout << "잘못 입력하셨습니다." << endl;
            continue;
        }
    }
}

void Stamp::StampView() {
    cout << "현재 적립된 스탬프: " << mainData->GetStamp() << "개" << endl;
}

void Stamp::StampUse() {
    if (mainData->GetStamp() > 0) {
        string stampUse;
        cout << "스탬프를 사용하여 무료 커피를 받겠습니까? (Y/N): ";
        cin >> stampUse;
        if (stampUse == "Y" || stampUse == "y") {
            cout << "원하는 무료 커피를 선택하세요:" << endl;
            cout << "1. 콜드 브루 플로트" << endl;
            cout << "2. 라벤더 카페 브레베" << endl;
            cout << "입력: ";
            int coffeeChoice;
            cin >> coffeeChoice;
            switch (coffeeChoice) {
                case 1: {
                    // 콜드 브루 플로트 커피 객체 생성 후 장바구니에 추가
                    Coffee coldBrewFloat("음료", "콜드 브루 플로트", 0, 0, false, true);
                    coffeeMachine->AddToCart(coldBrewFloat);
                    break;
                }
                case 2: {
                    // 라벤더 카페 브레베 커피 객체 생성 후 장바구니에 추가
                     Coffee lavenderCafeBreve("음료", "라벤더 카페 브레베", 0, 0, false,true);
                    coffeeMachine->AddToCart(lavenderCafeBreve);
                    break;
                }
                default:
                    cout << "잘못된 선택입니다." << endl;
                    return;
            }
            mainData->SetStamps(mainData->GetStamp() - 1); // 스탬프 1개 감소
            cout << "무료 커피를 장바구니에 담았습니다." << endl;
        } else {
            cout << "스탬프 사용을 취소하였습니다." << endl;
        }
    } else {
        cout << "사용 가능한 스탬프가 없습니다." << endl;
    }
}

void Stamp::StampGuide() {
    cout << "스탬프는 커피를 10개 구매할 때마다 1개가 적립됩니다." << endl;
    cout << "적립한 스탬프로는 커피 1컵이 무료로 제공됩니다." << endl;
}
