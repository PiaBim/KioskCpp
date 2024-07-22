#ifndef _COFFEEMACHINE_H_
#define _COFFEEMACHINE_H_

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "Coffee.h"

using namespace std;

// MainData 전방 선언
class MainData;

class CoffeeMachine {
private:
    vector<Coffee> CofArr;
    vector<Coffee> cart;
    vector<Coffee> bestMenu;
    vector<Coffee> coffeeMenu;
    vector<Coffee> NonCoffeeMenu;
    vector<Coffee> juiceMenu;
    vector<Coffee> smoothieMenu;
    vector<Coffee> dessertMenu;
    MainData* mainData;

public:
    CoffeeMachine(MainData* data);
    void OrderMenu();
    void InShop();
    void OutShop();
    void Smoothie(bool inShop);
    void Juice(bool inShop);
    void Dessert(bool inShop);
    void NonCofMenu(bool inShop);
    void CofMenu(bool inShop);
    void BestMenu(bool inShop);
    void AddToCart(const Coffee& coffee);
    void CartEmpty() ;
    vector<Coffee>& GetCart();
    int GetCartSize() const;
    double GetTotalCartAmount() const;
    void ApplyDiscount(double discountAmount);
    
};

#endif // _COFFEEMACHINE_H_
