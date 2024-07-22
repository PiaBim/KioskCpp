#include "ProcessMenu.h"

Process::Process(MainData* data)
    : mainData(data), coffeeMachine(data->GetCoffeeMachine()) { }

void Process::ProcessMenu() {
    OrderView view(mainData); // OrderView 객체 생성
    PointView poinview(mainData,mainData->GetCoffeeMachine()); // mainData를 전달하여 PointView 객체 생성
    Stamp stamp(mainData,mainData->GetCoffeeMachine());
    Coupon coupon(mainData,mainData->GetCoffeeMachine());
    PayMent payment(mainData,mainData->GetCoffeeMachine());
    int choice;

    while (true) {
        showmenu();
        cout << "입력: ";
        cin >> choice;

        switch (choice) {
            case 1:
                OrderMenu(); // 주문 메뉴 호출
                break;
            case 2:
                view.MenuView(); // 주문 확인 호출
                break;
            case 3:
                poinview.Pointmenu(); // 포인트 메뉴 호출
                break;
            case 4:
                stamp.Stampmenu(); // 스탬프 적립 호출
                break;
            case 5:
                coupon.CouPonMenu(); // 쿠폰 사용 호출
                break;
            case 6:
                payment.PayView(); // 결제 호출
                break;
            case 9:
                cout << "종료" << endl;
                exit(0);
            default:
                cout << "잘못된 선택입니다." << endl;
                break;
        }
    }
}

// showmenu와 OrderMenu 메서드 구현...


void Process::OrderMenu() {
    while (true) {
        std::cout << "1. 매장" << std::endl;
        std::cout << "2. 포장" << std::endl;
        int choice;
        std::cout << "입력: ";
        std::cin >> choice;

        if (choice == 1) {
            std::cout << "매장메뉴로 들어갑니다." << std::endl;
            coffeeMachine->InShop(); // 매장 주문 처리
            break;
        } else if (choice == 2) {
            std::cout << "포장메뉴로 들어갑니다." << std::endl;
            coffeeMachine->OutShop(); // 포장 주문 처리
            break;
        } else {
            std::cout << "잘못 입력하셨습니다." << std::endl;
            continue;
        }
    }
}
void Process::showmenu() {
    std::cout << "1. 매장 주문하기" << std::endl;
    std::cout << "2. 주문 확인하기" << std::endl;
    std::cout << "3. 포인트 메뉴" << std::endl;
    std::cout << "4. 스탬프 메뉴" << std::endl;
    std::cout << "5. 쿠폰 사용하기" << std::endl;
    std::cout << "6. 결제하기" << std::endl;
    std::cout << "9. 종료" << std::endl;
}