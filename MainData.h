#ifndef __MAINDATA_H__
#define __MAINDATA_H__

#include <string>
#include <vector>
#include "CoffeeMachine.h"


class MainData {
private:
    std::vector<Coffee> CofArr;
    std::string filePath;
    int points;
    int Stamp;
    int OrderCount;
    CoffeeMachine* coffeeMachine;
    vector<std::string> cart; 

public:
    MainData(const std::string& dataFilePath);
    ~MainData();  // 소멸자 추가
    void LoadData();
    const std::vector<Coffee>& GetCofArr() const;
    int GetPoints() const;
    void UsePoints(int p);
    void AddPoints(int p);
    CoffeeMachine* GetCoffeeMachine();
    void SetCoffeeMachine(CoffeeMachine* machine);
    int GetStamp() const;
    void AddStamp();
    void IncrementOrderCount();    
    void SetStamps(int stampCount);
    
};

#endif // __MAINDATA_H__
