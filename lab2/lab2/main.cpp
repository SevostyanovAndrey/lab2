#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
    struct book
    {
        int reg_nom;
        string avtor;
        string nazva;
        int god;
        string izdatel;
        int stran;
    };
class library{
    vector<book> lib;
    void add_book(book nev_book){lib.push_back(nev_book);};//добавить одну книгу
public:
    int in_book();//добавляем книги с клавы
    int my_sort();//сортировать книги по автору
    int out_after_year_public();//выводит книги после н-ого года

};
bool sor(book a,book b){//ф-я сравнения
    return a.avtor<b.avtor;
}

int main (){
    setlocale(LC_ALL,"Russian");//коректн рус
    library new_lib;//создадим библиатеку
    new_lib.in_book();//вводим книги
    new_lib.my_sort();//сортируем
    new_lib.out_after_year_public();//выводим на монитор
    system("pause");
return 0;
}
int library::in_book(){
    book temp;
    char Y_N='Y';
    do{
        cout << "Vvedite registratsionnuy nomer\n";
        cin >> temp.reg_nom;
        cout << "Vvedite avtora\n";
        cin >> temp.avtor;
        cout << "vvedite nazvanie knigi\n";
        cin >> temp.nazva;
        cout << "vvedite god izdaniya\n";
        cin >> temp.god;
        cout <<"vvedite izdatelstvo\n";
        cin >> temp.izdatel;
        cout << "vveditw kolichestvo stranits\n";
        cin >> temp.stran;
        cout<<"\n----------------------------------\n";
        add_book(temp);
        cout << "Вы хотите еще добавить книгу (Y/N)?\n" ;
        cin>>Y_N;
    }while(Y_N =='Y');
    return 0;
}
int library::out_after_year_public(){//выводит книги после ного года
    int year;
    cout<<"====================="<<endl;
    cout<<"Vvedite god"<<endl;
    cin>>year;
    for(int i=0;i<lib.size();i++){
        if(lib[i].god>year){
            cout<<lib[i].avtor<<endl;
            cout<<lib[i].god<<endl;
            cout<<lib[i].izdatel<<endl;
            cout<<lib[i].nazva<<endl;
            cout<<lib[i].reg_nom<<endl;
            cout<<lib[i].stran<<endl<<endl;
        }
    }
    return 0;
}
int library::my_sort(){
    sort(lib.begin(),lib.end(),sor);
    return 0;
}
