#include <iostream>
#include "ProcessMenu.h"

int main() {
    // 데이터 파일 경로
    std::string filePath = "ShopMenu.txt";
    string couponPath="Coupon.txt";

    // Process 객체 생성 및 메뉴 처리 시작
    Process process(new MainData(filePath));
    process.ProcessMenu();

    return 0;
}
