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
    const string& GetOrderType() const; // 주문 타입 확인 메서드
    int GetPoint() const; // 포인틀 저장
    bool IsSoldOut() const; 
    bool IsFree() const; // 공짜인지 아닌지 판별 메서드
    void setPrice(int _price); // 가격 설정 메서드
    void setPoint(int _Point); // 포인트 설정 메서드
    void setOrderType(const string& type);
    void setSoldOut(bool _soldOut);
};

#endif // __COFFEE_H__
