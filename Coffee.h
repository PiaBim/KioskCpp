#ifndef __COFFEE_H__
#define __COFFEE_H__

#include <string>

using namespace std;

class Coffee {
private:
    string CofType;
    string CofName;
    int price;
    string OrderType;
    int Point;
    bool soldOut;
    bool free;

public:
    Coffee(const string& _CofType, const string& _CofName, int _price, int _Point, bool _soldOut = false, bool _free = false);
    
    const string& GetType() const;
    const string& GetName() const;
    int GetPrice() const; // 가격을 정수로 반환
    string GetPriceStr() const; // 가격을 문자열로 반환
    int GetOriginalPrice() const; // 원래 가격을 반환
    const string& GetOrderType() const;
    int GetPoint() const;
    bool IsSoldOut() const;
    bool IsFree() const;
    void setPrice(int _price); // 가격 설정 메서드
    void setPoint(int _Point);
    void setOrderType(const string& type);
    void setSoldOut(bool _soldOut);
};

#endif // __COFFEE_H__
