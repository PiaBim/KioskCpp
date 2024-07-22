#include "Coupon.h"
#include <iostream>

using namespace std;

void Coupon::Couponmenu() {
    cout << "1. 쿠폰 사용하기" << endl;
    cout << "2. 쿠폰 가이드" << endl;
    cout << "9. 종료" << endl;
}

void Coupon::CouPonMenu() {
    while (true) {
        Couponmenu();
        cout << "입력: ";
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                CouponUse();
                break;
            case 2:
                CouponGuide();
                break;
            case 9:
                cout << "종료" << endl;
                return;
            default:
                cout << "잘못 입력하였습니다." << endl;
                continue;
        }
    }
}

void Coupon::CouponUse() {
    // 사용자가 쿠폰 코드를 입력하도록 요구
    string couponCode;
    cout << "쿠폰 코드를 입력하세요: ";
    cin >> couponCode;

    // 예제: 쿠폰 코드가 "DISCOUNT10"이면 10% 할인 적용
    if (couponCode == "DISCOUNT10") {
        // 현재 장바구니의 총 금액을 가져와서 10% 할인 적용
        double discountRate = 0.10; // 10% 할인
        double totalAmount = coffeeMachine->GetTotalCartAmount(); // 장바구니의 총 금액을 가져오는 메서드
        double discountAmount = totalAmount * discountRate;

        coffeeMachine->ApplyDiscount(discountAmount); // 할인 적용

        cout << "쿠폰이 적용되어 10퍼 할인되었습니다." << endl;
    } else {
        cout << "유효하지 않은 쿠폰 코드입니다." << endl;
    }
}


void Coupon::CouponGuide() {
    cout << "쿠폰 사용 방법:" << endl;
    cout << "1. 쿠폰 코드를 입력하면 장바구니의 총 금액에 할인율이 적용됩니다." << endl;
}
