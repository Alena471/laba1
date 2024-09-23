#include <string>
#include <iostream>
#include <stdlib.h>

using namespace std;

class ATS {
    string addres;
    double count;
    double ab_plata;
public:
    ATS(string addr, double kolvo, double plata) :
        addres(addr), count(kolvo), ab_plata(plata) {}
    double total_pl()const {
        return count * ab_plata;
    }
    void displayInfo() const {
        cout << "Адрес: " << addres << endl;
        cout << "Абонентская плата: " << ab_plata << " руб." << endl;
        cout << "Число абонентов: " << count << endl;
        
        cout << "Абонентская плата всех пользователей: " << total_pl() << " руб." << endl;
    }
    void change_ad(string new_ad) {
        addres = new_ad;
    }
    void change_c(double new_c) {
        count = new_c;
    }
    void change_ab(double new_ab) {
        ab_plata = new_ab;
    }

};



int main()
{
    setlocale(LC_ALL, "RU");
    cout << "Начальная АТС:  "<<endl;
    ATS myAts("Улица Пушкина, дом 10", 150, 500.00);
    myAts.displayInfo();

    bool flag = 0;
    cout << "Хотите изменить АТС? Нажмите 1" << endl;
    cin >> flag;
    cin.ignore();
    if (flag == 1) {

        string add = "";
        cout << "Введите новый адрес: ";
       
        getline(cin, add);
        myAts.change_ad(add);
        
        
        
        double ab = 0;
        cout << "Введите новую абонентскую плату: ";
        cin >> ab;
        if (cin.fail() || ab < 0) {
            cout << "Ошибка";
            return -1;
        }
        else {
            myAts.change_ab(ab);
        }
        double c = 0;
        cout << "Введите новое число абонентов: ";
        cin >> c;
        if (cin.fail() || (c - int(c)) != 0 || c < 0 ) {
            cout << "Ошибка";
            return -1;

        }

        myAts.change_c(c);
        cout << "Данные о Новой АТС:" << endl;
        myAts.displayInfo();
    }
    

    return 0;
}

