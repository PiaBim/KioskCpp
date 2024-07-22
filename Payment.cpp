#include "Payment.h"



void PayMent::Paymenu() {
    cout << "1.카드결제" << endl;
    cout << "2.간편결제" << endl;
    cout << "3.결제 가이드" << endl;
    cout << "9.종료" << endl;
    
}

void PayMent::PayView() {
    while(true){
        Paymenu();
        cout<<"입력:";
        int choice;
        cin>>choice;
        switch(choice){
            case 1:
                CardUse();
                break;
            case 2:
                SimpleUse();
                break;
            case 3:
                PayGuide();
                break;
            case 9:
                cout << "종료" << endl;
                return;
            default:
                cout << "잘못 입력하고 있습니다." << endl;
                continue;
        }
    }
}

void PayMent::CardUse(){

    string choice;
    cout << "카드결제를 진행하시겠습니까?(YES/NO)" << endl;
    cout << "입력:";
    cin >> choice;
    if (choice=="YES"||choice=="yes"||choice=="y"||choice=="Y"){
        coffeeMachine->CartEmpty();
        cout << "카드결제가 완료되었습니다." << endl;
        return;
    }else if(choice=="NO"||choice=="no"||choice=="n"||choice=="N"){
        cout<<"카드결제 취소"<<endl;
        return;
    }
    else{
        cout << "잘못 입력하였습니다 다시." << endl;
    }

}

void PayMent::SimpleUse(){
    string choice;
    cout << "간편결제를 진행하시겠습니까?(YES/NO)" << endl;
    cout << "입력:";
    cin >> choice;
    if (choice=="YES"||choice=="yes"||choice=="y"||choice=="Y"){
        coffeeMachine->CartEmpty();
        cout << "간편결제가 완료되었습니다." << endl;
        return;
    }else if(choice=="NO"||choice=="no"||choice=="n"||choice=="N"){
        cout<<"간편결제 취소"<<endl;
        return;
    }
    else{
        cout << "잘못 입력하였습니다 다시." << endl;
    }
}

void PayMent::PayGuide(){
    cout << "카드결제의 경우 카드만 결제 진행됩니다." << endl;
    cout << "간편결제의 경우 현금으로만 결제 진행됩니다." << endl;

}