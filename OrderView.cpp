#include <iostream>
#include "OrderView.h"

using namespace std;

OrderView::OrderView(MainData* data)
    : coffeeMachine(data->GetCoffeeMachine()) { }

void OrderView::MenuView() {
    if (coffeeMachine->GetCartSize() == 0) {
        cout << "장바구니가 없습니다." << endl;
        return;
    }
    cout << "[장바구니 보기]" << endl;
    int idx = 1;
    for (const auto& coffee : coffeeMachine->GetCart()) {
        cout << idx << ". " << coffee.GetName() << " - " 
             << (coffee.IsFree() ? "무료" : to_string(coffee.GetPrice()) + "원") 
             << "\t\t[" << coffee.GetType() << "]" 
             << " [" << coffee.GetOrderType() << "]" << endl;
        idx++;
    }
}
