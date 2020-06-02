//Developed By
//Shriganesh Hegde
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <map>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include<dos.h>
#include<ctype.h>
#include<time.h>
#include<string.h>

using namespace std;
COORD coord={0,0};//sets coordinates to 0,0
COORD res_max,cursor_size;

void gotoxy(int x,int y)
{
    coord.X=x;coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);//Sets the cursors position for the following
}
void delay(unsigned int milli)
{
    clock_t goal=milli+clock();
    while(goal>clock());
}
void LOADER_ANIMATION()
{
    system("cls");
    int loader;
    gotoxy(50,12);
    printf("LOADING...");
    gotoxy(50,14);
    for(loader=1;loader<20;loader++)
    {
        if(loader<=5)
            delay(100);
        else if(loader<=10)
            delay(50);
        else if(loader==15)
             delay(4000);
        else
            delay(200);

        printf("%c",219);
    }gotoxy(20,5);

}
class Product
{
private:
    long ProductId;
    string ProductName;
    int Quantity;
    float Price;
    static long NextProductId;

public:
    Product(){}
    Product(string ProductName,int Quantity,float Price);
    long getProductId(){return ProductId;}
    string getProductName(){return ProductName;}
    int getQuantity(){return Quantity;}
    float getPrice(){return Price;}
void AddProduct(int Quantity);
 void IssueProduct(int Quantity);
  static void setLastProductId(long ProductId);
   static long getLastProductId();
    friend ofstream & operator<<(ofstream &ofs,Product &pro);
     friend ifstream & operator>>(ifstream &ifs,Product &pro);
      friend ostream & operator<<(ostream &os,Product &pro);

};
long Product::NextProductId=0;
class Sales
{
private:
    map<long,Product> products;
public:
    Sales();
    Product AddNewProduct(string ProductName,int Quantity,float Price);
    Product ProductEnquiry(long ProductId);
    Product AddProduct(long ProductId,int Quantity);
    Product IssueProduct(long ProductId,int Quantity);
    void RemoveProduct(long ProductId);
    void ShowAllProducts();
    ~Sales();
};
Sales sal;
Product pro;
void MAIN_MENU()
{
    system("cls");


int choice;
string ProductName;
int Quant;
char enter;

long ProductId;
float Price;
gotoxy(40,7);
cout<<"*** Sales Management System ***"<<endl;

    gotoxy(38,9);
    cout<<"Select one option below ";
    gotoxy(38,10);
    cout<<"1. Add New Product";
    gotoxy(38,12);
    cout<<"2. Product Enquiry";
    gotoxy(38,14);
    cout<<"3. Add Product";
    gotoxy(38,16);
    cout<<"4. IssueProducts";
    gotoxy(38,18);
    cout<<"5. Remove Product";
    gotoxy(38,20);
    cout<<"6. Show All Products";
    gotoxy(38,22);
    cout<<"7. Quit";
    gotoxy(38,24);
    cout<<"Enter your choice:";
    cin>>choice;
    switch(choice)
    {
    case 1:
        system("cls");
        gotoxy(40,7);
        cout<<"Enter the PRODUCT Name: ";
        cin>>ProductName;
        gotoxy(40,9);
        cout<<"Enter Quantity: ";
        cin>>Quant;
        gotoxy(40,11);
        cout<<"Enter PRICE: ";

        cin>>Price;
        pro=sal.AddNewProduct(ProductName,Quant,Price);
        gotoxy(40,13);
        cout<<endl<<"Congratulation Product  is successfully Added"<<endl;
        gotoxy(40,15);
        cout<<"Press ENTER to return to Main Menu";
        getch();
        MAIN_MENU();

       // cout<<pro;
    case 2:
        system("cls");
        gotoxy(40,7);
        cout<<"Enter Product Id: ";
        cin>>ProductId;
        pro=sal.ProductEnquiry(ProductId);
        cout<<"\t\tYour Product Details:"<<endl<<endl;
        cout<<pro;
           gotoxy(40,20);
        cout<<"Press ENTER to return to Main Menu";
        getch();
        MAIN_MENU();


    case 3:
        system("cls");
        gotoxy(40,7);
        cout<<"Enter Product Id: ";
        cin>>ProductId;
        gotoxy(40,9);
        cout<<"Enter Quantity: ";
        cin>>Quant;
        pro=sal.AddProduct(ProductId,Quant);
        gotoxy(40,13);
        cout<<"Product is Added!!!!";
           gotoxy(40,17);
        cout<<"Press ENTER to return to Main Menu";
        getch();
         MAIN_MENU();

       // cout<<pro;
    case 4:
        system("cls");
        gotoxy(40,7);
        cout<<"Enter ProductId: ";
        cin>>ProductId;
        gotoxy(40,9);
        cout<<"Enter Quantity: ";
        cin>>Quant;
        pro=sal.IssueProduct(ProductId,Quant);
           gotoxy(40,15);
        cout<<"Press ENTER to return to Main Menu";
        getch();
         MAIN_MENU();

        //cout<<pro;
    case 5:
        system("cls");
        gotoxy(40,7);
        cout<<"Enter the ProductId:";
        cin>>ProductId;
        sal.RemoveProduct(ProductId);
        gotoxy(40,11);
        cout<<"Product is Removed!!!";
           gotoxy(40,15);
        cout<<"Press ENTER to return to Main Menu";
        getch();
         MAIN_MENU();

        //cout<<pro;

    case 6:
        system("cls");
        sal.ShowAllProducts();
        cout<<"Press ENTER to return to Main Menu";
        getch();
        MAIN_MENU();

    case 7:system("cls");
         gotoxy(40,8);
         printf("Developed By:");
         gotoxy(40,10);
         printf("SHRIGANESH HEGDE");
         gotoxy(40,12);
         printf("Mobile:8217895605\t\temail:shri274023@gmail.com");
         delay(1000);
         exit(0);

    default:
        cout<<"\nEnter the correct choice";
        exit(0);

}
}
int main()
{
   LOADER_ANIMATION();
   MAIN_MENU();

return 0;


}
Product::Product(string ProductName,int Quant,float Price)
{
    NextProductId++;
    ProductId=NextProductId;
    this->ProductName=ProductName;
    Quantity=Quant;
    this->Price=Price;

}
void Product::AddProduct(int another)
{
    Quantity+=another;
}
void Product::IssueProduct(int Quant)
{
    if((Quantity-Quant)<0)
       cout<<"\n\n\t\t\t\tSorry Product is outOfStock"<<endl;
    else{
       Quantity-=Quant;
       cout<<"Product Issued"<<endl;
    }


}
void Product::setLastProductId(long ProductId)
{
    NextProductId=ProductId;
}
long Product::getLastProductId()
{
    return NextProductId;
}
ofstream & operator<<(ofstream &ofs,Product &pro)
{
    ofs<<pro.ProductId<<endl;
    ofs<<pro.ProductName<<endl;
    ofs<<pro.Quantity<<endl;
    ofs<<pro.Price<<endl;

    return ofs;
}
ifstream & operator>>(ifstream &ifs,Product &pro)
{
    ifs>>pro.ProductId;
    ifs>>pro.ProductName;
    ifs>>pro.Quantity;
    ifs>>pro.Price;

    return ifs;
}
ostream & operator<<(ostream &os,Product &pro)
{
    os<<"\t\tProduct Name:"<<pro.getProductName()<<endl;
    os<<"\t\tQuantity:"<<pro.getQuantity()<<endl;
    os<<"\t\tProductId:"<<pro.getProductId()<<endl;
    os<<"\t\tPrice:"<<pro.getPrice()<<endl;

    return os;
}

Sales ::Sales()
{
    Product pro;
    ifstream infile;

    infile.open("ProductDet.data");
    if(!infile)
    {
        return;
    }
    while(!infile.eof())
    {
        infile>>pro;
        products.insert(pair<long,Product>(pro.getProductId(),pro));
    }
    Product::setLastProductId(pro.getProductId());

    infile.close();
}
Product Sales::AddNewProduct(string ProductName,int Quant,float balance)
{
    ofstream outfile;
    Product pro(ProductName,Quant,balance);
    products.insert(pair<long,Product>(pro.getProductId(),pro));

    outfile.open("ProductDet.data",ios::trunc);
    map<long,Product>::iterator itr;
    for(itr=products.begin();itr!=products.end();itr++)
    {
        outfile<<itr->second;
    }
    outfile.close();

    return pro;
}
Product Sales::ProductEnquiry(long ProductId)
{
    map<long,Product>::iterator itr=products.find(ProductId);
    return itr->second;
}
Product Sales::AddProduct(long ProId,int Quant)
{
    map<long,Product>::iterator itr=products.find(ProId);
    itr->second.AddProduct(Quant);

    return itr->second;
}
Product Sales::IssueProduct(long ProId,int Quant)
{
map<long,Product>::iterator itr=products.find(ProId);
    itr->second.IssueProduct(Quant);

    return itr->second;

}
void Sales::RemoveProduct(long PId)
{
    map<long,Product>::iterator itr=products.find(PId);
    products.erase(PId);
}
void Sales::ShowAllProducts()
{
    map<long,Product>::iterator itr;
    for(itr=products.begin();itr!=products.end();itr++)
    {
        cout<<""<<itr->second<<endl;
    }
}
Sales::~Sales()
{
    ofstream outfile;
    outfile.open("ProductDet.data",ios::trunc);

    map<long,Product>::iterator itr;
    for(itr=products.begin();itr!=products.end();itr++)
    {
        outfile<<itr->second;
    }
    outfile.close();
}

