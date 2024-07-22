#include "Coffee.h"

Coffee::Coffee(const string& _CofType, const string& _CofName, int _price, int _Point, bool _soldOut, bool _free)
    : CofType(_CofType), CofName(_CofName), price(_price), Point(_Point), soldOut(_soldOut), free(_free) { }

const string& Coffee::GetType() const {
    return CofType;
}

const string& Coffee::GetName() const {
    return CofName;
}

int Coffee::GetPrice() const {
    return price;
}

int Coffee::GetOriginalPrice() const {
    return price;
}

string Coffee::GetPriceStr() const {
    return to_string(price); // 정수를 문자열로 변환
}

const string& Coffee::GetOrderType() const {
    return OrderType;
}

int Coffee::GetPoint() const {
    return Point;
}

bool Coffee::IsSoldOut() const {
    return soldOut;
}

void Coffee::setPoint(int _Point) {
    Point = _Point;
}

void Coffee::setPrice(int _price) {
    price = _price;
}

void Coffee::setOrderType(const string& type) {
    OrderType = type;
}

void Coffee::setSoldOut(bool _soldOut) {
    soldOut = _soldOut;
}

bool Coffee::IsFree() const {
    return free;
}