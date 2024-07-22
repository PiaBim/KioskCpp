#include "MainData.h"
#include <iostream>
#include <fstream>

using namespace std;

MainData::MainData(const string& dataFilePath)
    : filePath(dataFilePath), points(0), coffeeMachine(nullptr), Stamp(0), OrderCount(0) {
    coffeeMachine = new CoffeeMachine(this);
}

MainData::~MainData() {
    delete coffeeMachine;
}

void MainData::LoadData() {
    ifstream file(filePath);
    if (!file.is_open()) {
        cout << "파일을 열 수 없습니다. 파일 경로: " << filePath << endl;
        return;
    }

    CofArr.clear();

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string CofType, CofName, priceStr, soldOutStr;
        int price;
        bool soldOut;

        getline(ss, CofType, ',');
        getline(ss, CofName, ',');
        getline(ss, priceStr, ',');
        getline(ss, soldOutStr);

        if (priceStr == "품절") {
            soldOut = true;
            price = 0;
        } else {
            try {
                price = stoi(priceStr);
                soldOut = (soldOutStr == "true");
            } catch (const invalid_argument& e) {
                cout << "가격 형식이 잘못되었습니다: " << priceStr << endl;
                continue;
            }
        }

        Coffee coffee(CofType, CofName, price, 0, soldOut);
        CofArr.push_back(coffee);
    }

    file.close();
}

const vector<Coffee>& MainData::GetCofArr() const {
    return CofArr;
}

int MainData::GetPoints() const {
    return points;
}

void MainData::UsePoints(int p) {
    if (points >= p) {
        points -= p;
    } else {
        cout << "포인트가 부족합니다." << endl;
    }
}

void MainData::AddPoints(int p) {
    points += p;
    cout << "포인트가 적립되었습니다. 현재 포인트: " << points << endl;
}

CoffeeMachine* MainData::GetCoffeeMachine() {
    return coffeeMachine;
}

void MainData::SetCoffeeMachine(CoffeeMachine* machine) {
    coffeeMachine = machine;
}

int MainData::GetStamp() const {
    return Stamp;
}

void MainData::AddStamp() {
    Stamp++;
}

void MainData::IncrementOrderCount() {
    OrderCount++;
    if (OrderCount % 10 == 0) {
        AddStamp();
    }
}
void MainData::SetStamps(int stampCount) {
    Stamp = stampCount;
}

