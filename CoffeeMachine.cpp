#include "CoffeeMachine.h"
#include "MainData.h"


CoffeeMachine::CoffeeMachine(MainData* data)
    : mainData(data) {
    mainData->LoadData();
    CofArr = mainData->GetCofArr();
}

vector<Coffee>& CoffeeMachine::GetCart(){
    return cart;
}

int CoffeeMachine::GetCartSize() const {
    return cart.size();
    
}

void CoffeeMachine::CartEmpty() {
    cart.clear();
}

void CoffeeMachine::AddToCart(const Coffee& coffee) {
    // 무료 커피 여부와 관계없이 장바구니에 추가
    cart.push_back(coffee);
}
double CoffeeMachine::GetTotalCartAmount() const {
    double totalAmount = 0.0;
    for (const auto& coffee : cart) {
        totalAmount += coffee.GetPrice();
    }
    return totalAmount;
}

void CoffeeMachine::ApplyDiscount(double discountAmount) {
    for (auto& coffee : cart) {
        int newPrice = coffee.GetPrice() - static_cast<int>(discountAmount);
        coffee.setPrice(max(newPrice, 0)); // 가격이 음수가 되지 않도록 처리
        discountAmount -= coffee.GetPrice();
        if (discountAmount <= 0) break; // 남은 할인 금액이 없으면 종료
    }
}

void CoffeeMachine::OrderMenu() {
    while (true) {
        cout << "1.매장" << endl;
        cout << "2.포장" << endl;
        int choice;
        cout << "입력:";
        cin >> choice;
        if (choice == 1) {
            cout << "매장메뉴로 들어갑니다." << endl;
            InShop(); // 매장 주문 함수 호출
            break;
        }
        else if (choice == 2) {
            cout << "포장메뉴로 들어갑니다." << endl;
            OutShop(); // 포장 주문 함수 호출
            break;
        }
        else {
            cout << "잘못 입력하셨습니다." << endl;
            continue;
        }
    }
}

void CoffeeMachine::InShop() {
    while (true) {
        cout << "==============================================" << endl;
        cout << "1.베스트|2.커피|3.논커피|4.스무디|5.주스|6.디저트" << endl;
        cout << "==============================================" << endl;
        cout << "9.종료" << endl;
        cout << "0.포장 주문으로 변경" << endl;

        int choice;
        cout << "입력:";
        cin >> choice;
        switch (choice) {
        case 0:
            cout << "포장 주문으로 변경" << endl;
            OutShop();
            return;
        case 1:
            BestMenu(true); 
            break;
        case 2:
            CofMenu(true);
            break;
        case 3:
            NonCofMenu(true);
            break;
        case 4:
            Smoothie(true);
            break;
        case 5:
            Juice(true);
            break;
        case 6:
            Dessert(true);
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

void CoffeeMachine::OutShop() {
    while (true) {
        cout << "==============================================" << endl;
        cout << "1.베스트|2.커피|3.논커피|4.스무디|5.주스|6.디저트" << endl;
        cout << "==============================================" << endl;
        cout << "9.종료" << endl;
        cout << "0.매장 주문으로 변경" << endl;

        int choice;
        cout << "입력:";
        cin >> choice;
        switch (choice) {
        case 0:
            cout << "매장 주문으로 변경" << endl;
            InShop();
            return;
        case 1:
            BestMenu(false);
            break;
        case 2:
            CofMenu(false);
            break;
        case 3:
            NonCofMenu(false);
            break;
        case 4:
            Smoothie(false);
            break;
        case 5:
            Juice(false);
            break;
        case 6:
            Dessert(false);
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

    #include "CoffeeMachine.h"

    void CoffeeMachine::Juice(bool inShop) {
        cout << "[주스 메뉴]" << endl;
        int idx = 1;

        juiceMenu.clear();

        for (const auto& Cof : mainData->GetCofArr()) {
            if (Cof.GetType() == "주스") {
                juiceMenu.push_back(Cof);
            }
        }

        for (const auto& Cof : juiceMenu) {
            if (Cof.IsSoldOut()) { // 품절 상태를 확인하여 출력
                cout << idx << "." << Cof.GetName() << "  -   품절" << endl;
            } else {
                cout << idx << "." << Cof.GetName() << "  -   " << Cof.GetPriceStr() << "원" << endl;
            }
            idx++;
        }
        cout << "-1.메뉴선택로 돌아갑니다." << endl;

        int choice;
        cout << "입력:";
        string input;
        cin >> input;
        stringstream ss(input);
        if (!(ss >> choice)) {
            cout << "#숫자만 입력하세요.#" << endl;
            return;
        }
        if (choice == -1) {
            cout << "메뉴선택으로 돌아갑니다." << endl;
            return;
        }

        if (choice < 1 || choice > juiceMenu.size()) {
            cout << "잘못 입력했습니다." << endl;
            Juice(inShop);
        } else {
            Coffee Cof = juiceMenu[choice - 1];
            if (Cof.IsSoldOut()) {
                cout << Cof.GetName() << "은(는) 품절된 상품입니다." << endl;
            } else {
                Cof.setOrderType(inShop ? "매장" : "포장");
                int priceValue = Cof.GetPrice();
                int pointValue = static_cast<int>(priceValue * 0.01);
                Cof.setPoint(pointValue);
                cart.emplace_back(Cof);
                
                // Add points to MainData
                mainData->AddPoints(pointValue);
                mainData->IncrementOrderCount();
                
                cout << Cof.GetName() << "를 주문에 추가합니다." << endl;
                cout << "현재 포인트: " << mainData->GetPoints() << endl; // 포인트 출력
            }
        }
    }
void CoffeeMachine::Smoothie(bool inShop) {
        cout << "[스무디 메뉴]" << endl;
        int idx = 1;

        smoothieMenu.clear();

        for (const auto& Cof : mainData->GetCofArr()) {
            if (Cof.GetType() == "스무디") {
                smoothieMenu.push_back(Cof);
            }
        }

        for (const auto& Cof : smoothieMenu) {
            if (Cof.IsSoldOut()) { // 품절 상태를 확인하여 출력
                cout << idx << "." << Cof.GetName() << "  -   품절" << endl;
            } else {
                cout << idx << "." << Cof.GetName() << "  -   " << Cof.GetPriceStr() << "원" << endl;
            }
            idx++;
        }
        cout << "-1.메뉴선택로 돌아갑니다." << endl;

        int choice;
        cout << "입력:";
        string input;
        cin >> input;
        stringstream ss(input);
        if (!(ss >> choice)) {
            cout << "#숫자만 입력하세요.#" << endl;
            return;
        }
        if (choice == -1) {
            cout << "메뉴선택으로 돌아갑니다." << endl;
            return;
        }

        if (choice < 1 || choice > smoothieMenu.size()) {
            cout << "잘못 입력했습니다." << endl;
            Smoothie(inShop);
        } else {
            Coffee Cof = smoothieMenu[choice - 1];
            if (Cof.IsSoldOut()) {
                cout << Cof.GetName() << "은(는) 품절된 상품입니다." << endl;
            } else {
                Cof.setOrderType(inShop ? "매장" : "포장");
                int priceValue = Cof.GetPrice();
                int pointValue = static_cast<int>(priceValue * 0.01);
                Cof.setPoint(pointValue);
                cart.emplace_back(Cof);
                
                // Add points to MainData
                mainData->AddPoints(pointValue);
                mainData->IncrementOrderCount();
                cout << Cof.GetName() << "를 주문에 추가합니다." << endl;
                cout << "현재 포인트: " << mainData->GetPoints() << endl; // 포인트 출력
            }
        }
    }
void CoffeeMachine::Dessert(bool inShop) {
        cout << "[디저트 메뉴]" << endl;
        int idx = 1;

        dessertMenu.clear();

        for (const auto& Cof : mainData->GetCofArr()) {
            if (Cof.GetType() == "디저트") {
                dessertMenu.push_back(Cof);
            }
        }

        for (const auto& Cof : dessertMenu) {
            if (Cof.IsSoldOut()) { // 품절 상태를 확인하여 출력
                cout << idx << "." << Cof.GetName() << "  -   품절" << endl;
            } else {
                cout << idx << "." << Cof.GetName() << "  -   " << Cof.GetPriceStr() << "원" << endl;
            }
            idx++;
        }
        cout << "-1.메뉴선택로 돌아갑니다." << endl;

        int choice;
        cout << "입력:";
        string input;
        cin >> input;
        stringstream ss(input);
        if (!(ss >> choice)) {
            cout << "#숫자만 입력하세요.#" << endl;
            return;
        }
        if (choice == -1) {
            cout << "메뉴선택으로 돌아갑니다." << endl;
            return;
        }

        if (choice < 1 || choice > dessertMenu.size()) {
            cout << "잘못 입력했습니다." << endl;
            Dessert(inShop);
        } else {
            Coffee Cof = dessertMenu[choice - 1];
            if (Cof.IsSoldOut()) {
                cout << Cof.GetName() << "은(는) 품절된 상품입니다." << endl;
            } else {
                Cof.setOrderType(inShop ? "매장" : "포장");
                int priceValue = Cof.GetPrice();
                int pointValue = static_cast<int>(priceValue * 0.01);
                Cof.setPoint(pointValue);
                cart.emplace_back(Cof);
                
                // Add points to MainData
                mainData->AddPoints(pointValue);
                mainData->IncrementOrderCount();
                cout << Cof.GetName() << "를 주문에 추가합니다." << endl;
                cout << "현재 포인트: " << mainData->GetPoints() << endl; // 포인트 출력
            }
        }
    }

void CoffeeMachine::NonCofMenu(bool inShop) {
        cout << "[논커피 메뉴]" << endl;
        int idx = 1;

        NonCoffeeMenu.clear();

        for (const auto& Cof : mainData->GetCofArr()) {
            if (Cof.GetType() == "논커피") {
                NonCoffeeMenu.push_back(Cof);
            }
        }

        for (const auto& Cof : NonCoffeeMenu) {
            if (Cof.IsSoldOut()) { // 품절 상태를 확인하여 출력
                cout << idx << "." << Cof.GetName() << "  -   품절" << endl;
            } else {
                cout << idx << "." << Cof.GetName() << "  -   " << Cof.GetPriceStr() << "원" << endl;
            }
            idx++;
        }
        cout << "-1.메뉴선택로 돌아갑니다." << endl;

        int choice;
        cout << "입력:";
        string input;
        cin >> input;
        stringstream ss(input);
        if (!(ss >> choice)) {
            cout << "#숫자만 입력하세요.#" << endl;
            return;
        }
        if (choice == -1) {
            cout << "메뉴선택으로 돌아갑니다." << endl;
            return;
        }

        if (choice < 1 || choice > NonCoffeeMenu.size()) {
            cout << "잘못 입력했습니다." << endl;
            NonCofMenu(inShop);
        } else {
            Coffee Cof = NonCoffeeMenu[choice - 1];
            if (Cof.IsSoldOut()) {
                cout << Cof.GetName() << "은(는) 품절된 상품입니다." << endl;
            } else {
                Cof.setOrderType(inShop ? "매장" : "포장");
                int priceValue = Cof.GetPrice();
                int pointValue = static_cast<int>(priceValue * 0.01);
                Cof.setPoint(pointValue);
                cart.emplace_back(Cof);
                
                // Add points to MainData
                mainData->AddPoints(pointValue);
                mainData->IncrementOrderCount();
                cout << Cof.GetName() << "를 주문에 추가합니다." << endl;
                cout << "현재 포인트: " << mainData->GetPoints() << endl; // 포인트 출력
            }
        }
    }

void CoffeeMachine::CofMenu(bool inShop) {
        cout << "[커피 메뉴]" << endl;
        int idx = 1;

        coffeeMenu.clear();

        for (const auto& Cof : mainData->GetCofArr()) {
            if (Cof.GetType() == "커피") {
                coffeeMenu.push_back(Cof);
            }
        }

        for (const auto& Cof : coffeeMenu) {
            if (Cof.IsSoldOut()) { // 품절 상태를 확인하여 출력
                cout << idx << "." << Cof.GetName() << "  -   품절" << endl;
            } else {
                cout << idx << "." << Cof.GetName() << "  -   " << Cof.GetPriceStr() << "원" << endl;
            }
            idx++;
        }
        cout << "-1.메뉴선택로 돌아갑니다." << endl;

        int choice;
        cout << "입력:";
        string input;
        cin >> input;
        stringstream ss(input);
        if (!(ss >> choice)) {
            cout << "#숫자만 입력하세요.#" << endl;
            return;
        }
        if (choice == -1) {
            cout << "메뉴선택으로 돌아갑니다." << endl;
            return;
        }

        if (choice < 1 || choice > coffeeMenu.size()) {
            cout << "잘못 입력했습니다." << endl;
            CofMenu(inShop);
        } else {
            Coffee Cof = coffeeMenu[choice - 1];
            if (Cof.IsSoldOut()) {
                cout << Cof.GetName() << "은(는) 품절된 상품입니다." << endl;
            } else {
                Cof.setOrderType(inShop ? "매장" : "포장");
                int priceValue = Cof.GetPrice();
                int pointValue = static_cast<int>(priceValue * 0.01);
                Cof.setPoint(pointValue);
                cart.emplace_back(Cof);
                
                // Add points to MainData
                mainData->AddPoints(pointValue);
                mainData->IncrementOrderCount();
                cout << Cof.GetName() << "를 주문에 추가합니다." << endl;
                cout << "현재 포인트: " << mainData->GetPoints() << endl; // 포인트 출력
            }
        }
    }

void CoffeeMachine::BestMenu(bool inShop) {
        cout << "[베스트 메뉴]" << endl;
        int idx = 1;

        bestMenu.clear();

        for (const auto& Cof : mainData->GetCofArr()) {
            if (Cof.GetType() == "베스트") {
                bestMenu.push_back(Cof);
            }
        }

        for (const auto& Cof : bestMenu) {
            if (Cof.IsSoldOut()) { // 품절 상태를 확인하여 출력
                cout << idx << "." << Cof.GetName() << "  -   품절" << endl;
            } else {
                cout << idx << "." << Cof.GetName() << "  -   " << Cof.GetPriceStr() << "원" << endl;
            }
            idx++;
        }
        cout << "-1.메뉴선택로 돌아갑니다." << endl;

        int choice;
        cout << "입력:";
        string input;
        cin >> input;
        stringstream ss(input);
        if (!(ss >> choice)) {
            cout << "#숫자만 입력하세요.#" << endl;
            return;
        }
        if (choice == -1) {
            cout << "메뉴선택으로 돌아갑니다." << endl;
            return;
        }

        if (choice < 1 || choice > bestMenu.size()) {
            cout << "잘못 입력했습니다." << endl;
            BestMenu(inShop);
        } else {
            Coffee Cof = bestMenu[choice - 1];
            if (Cof.IsSoldOut()) {
                cout << Cof.GetName() << "은(는) 품절된 상품입니다." << endl;
            } else {
                Cof.setOrderType(inShop ? "매장" : "포장");
                int priceValue = Cof.GetPrice();
                int pointValue = static_cast<int>(priceValue * 0.01);
                Cof.setPoint(pointValue);
                cart.emplace_back(Cof);
                
                // Add points to MainData
                mainData->AddPoints(pointValue);
                mainData->IncrementOrderCount();
                cout << Cof.GetName() << "를 주문에 추가합니다." << endl;
                cout << "현재 포인트: " << mainData->GetPoints() << endl; // 포인트 출력
            }
        }
    }
