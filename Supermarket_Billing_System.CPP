#include<iostream>
#include<fstream>
#include<windows.h>
#include<stdlib.h>
using namespace std;
class shopping{
protected:
    int pcode;
    float price;
    float dis;
    string pname;
    float amount=0;
    float total=0;
	string Custname;
	int arrc[100];
    int arrq[100];
    int c=0;
    int flag=0;
    string cname;
    string cpassword;
    string name;
    string password;
public:
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void lis();
    void check();
    void order();
    void login();
    void signin();
};
void shopping ::menu(){
  m:
  int choice;
  string email;
  string password;
  system("cls");
  char arr[]={'S','U','P','E','R',' ','M','A','R','K','E','T',' ','B','I'
			,'L','L','I','N','G',' ','S','Y','S','T','E','M'};
			cout<<"\n\n\n\n\n\t\t\t\t";
			for(int i=0;i<27;i++){
				cout<<arr[i];
				Sleep(30);
			}
			Sleep(1000);
  cout<<"\n\t\t\t\t___________________________\n";
  cout<<"\t\t\t\t                           \n";
  cout<<"\t\t\t\t    Supermarket Main Menu  \n";
  cout<<"\t\t\t\t___________________________\n";
  cout<<"\t\t\t\t                           \n";
  cout<<"\t\t\t\t| 1)Adminsttrator  |\n";
  cout<<"\t\t\t\t|                  |\n";
  cout<<"\t\t\t\t| 2)Buyer          |\n";
  cout<<"\t\t\t\t|                  |\n";
  cout<<"\t\t\t\t| 3)Exit           |\n";
  cout<<"\t\t\t\t|                  |\n";
  cout<<"\n\t\t\t Please select!";
  cin>>choice;
  switch(choice)
  {

  case 1:
      {
    cout<<"\t\t\t Please login\n ";
    cout<<"\t\t\t Enter Email:";
    cin>>email;
    cout<<"\t\t\t Password:";
    cin>>password;
    if(email=="gowtham@email.com" && password=="gowtham@123"){
        administrator();

    }
    else{
        cout<<"\t\tInvalid Username/Password ....Please Enter the correct one\n ";
        goto m;
    }
    break;
}


  case 2:
    {
        buyer();

    }
  case 3:
    {
       // exit(0);
        break;
    }
  default:
    {
        cout<<"\t\tPlease select from the given option!!";
         goto m;
    }
  }


}


void shopping::administrator()
{
    m:
    int choice;
    cout<<"\n\n\n\t\t    Administartor menu ";
    cout<<"\n\t\t\t|_____1) Add the Product____|";
    cout<<"\n\t\t\t|                           |";
    cout<<"\n\t\t\t|_____2)Modify the product__|";
    cout<<"\n\t\t\t|                           |";
    cout<<"\n\t\t\t|_____3)Delete the product__|";
    cout<<"\n\t\t\t|                           |";
    cout<<"\n\t\t\t|_____4)Back to menu________|";
    cout<<"\n\n\t Please enter your choice";
    cin>>choice;
    switch(choice){
    case 1:
        {
            add();
            goto m;
            break;
        }
    case 2:
        {
            edit();
            goto m;
            break;
        }
    case 3:
        {
            rem();
            goto m;
            break;
        }
    case 4:
        {
            menu();
            break;
        }
    default :
        {
            cout<<"Invalid Choice!";
            goto m;
        }

    }
}

void shopping:: buyer()
{
    m:
    int choice;
    cout<<"\n\t\t\t          Buyer \n";
    cout<<"\t\t\t_______________________________\n";
    cout<<"                      \n";
    cout<<"\t\t\t\t| 1)Buy Product\n";
    cout<<"                      \n";
    cout<<"\t\t\t\t| 2)Go Back     \n";
    cout<<"\t\t\t\t Enter your Choice: ";
    cin>>choice;
    switch(choice)
    {
    case 1:
        check();
        break;

    case 2:
            menu();
            break;
    default:
        cout<<"Invalid Choice";
         goto m;
    }


}
void shopping::check()
{
    m:
    int ch;
    cout<<"\t\t\t\tPlease Login/Signup to Proceed shopping\n \t\t\t\t1.Login \n \t\t\t\t2. Sign in\n \t\t\t\t3. Menu\n";
    cin>>ch;
    switch(ch)
    {
    case 1:
        login();
        break;
    case 2:
        signin();
        break;
    case 3:
        menu();
        break;
    default:
        {
         cout<<"\t\t\t\tInvalid Choice...\n";
         goto m;
        }
    }
}

void shopping::login()
{
fstream data2;
int f,f1=0;
cout<<"\t\t\t\tPlease Login in to Proceed\n";
cout<<"\t\t\t\tEnter your Username\n";
cin>>name;
cout<<"\t\t\t\tEnter your Password\n";
cin>>password;
  data2.open("customer.txt",ios::in);
  data2>>cname>>cpassword;
  while(!data2.eof())
  {
      if((cname.compare(name) == 0)&&(cpassword.compare(password) == 0))
      {
          f1=1;
          order();
          break;
      }
    data2>>cname>>cpassword;
  }
  if(f1==0)
  {
   cout<<"\t\t\t\t Invalid Credentials...\n";
    m:
    cout<<"\t\t\t\t Please press 1.Signin\n2.Menu\n";
    cin>>f;
    switch(f)
    {
    case 1:
        signin();
        break;
    case 2:
        menu();
        break;
    default:
        {
         cout<<"\t\t\t\t Invalid Choice...\n";
         goto m;
        }
    }
  }
}
void shopping::signin()
{
m:
fstream data2;
int token1=0;
string d;
string n;
cout<<"\t\t\t\t Please Sign in to Proceed\n";
cout<<"\t\t\t\t Please enter username\n";
cin>>cname;
cout<<"\t\t\t\t Please enter password\n";
cin>>cpassword;
data2.open("customer.txt",ios::in);
    if(!data2){
        data2.open("customer.txt",ios::app|ios::out);
        data2<<" "<<cname<<" "<<cpassword<<"\n";
        data2.close();
    }
    else
    {
        data2>>n>>d;
        while(!data2.eof()){
            if(cname.compare(n) == 0){
                token1++;
            }
            data2>>n>>d;
        }
        data2.close();

    if(token1==1)
    {
        cout<<"\t\t\t\tUsername Already Available..Please choose another\n";
        goto m;
    }
    else//token is not incremented
    {
    data2.open("customer.txt",ios::app|ios::out);
        data2<<" "<<cname<<" "<<cpassword<<"\n";
        data2.close();
    }
    }
    cout<<"\t\t\t\t Signed in Successfully\n";
    login();
}
void shopping :: add()
{
    m:
    fstream data;
    int c1;
    int token=0;
    float p;
    float d;
    string n;
    cout<<"\n\n\t\t\t Add new Product ";
    cout<<"\n\n\t Product Code of the Product ";
    cin>>pcode;
    cout<<"\n\n\t Name Of the product ";
    cin>>pname;
    cout<<"\n\n\t Price of the product";
    cin>>price;
    cout<<"\n\n\t Discount on the product ";
    cin>>dis;
    data.open("database.txt",ios::in);
    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else
    {
        data>>c1>>n>>p>>d;
        while(!data.eof()){
            if(c1==pcode){
                token++;
            }
            data>>c1>>n>>p>>d;
        }
        data.close();


    if(token==1)
    {
        cout<<"\t\t\t\tProductcode is already available..!!Please choose Another...!!!";
        goto m;
    }
    else//token is not incremented
    {
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    }

    cout<<"\n\n\t\t Record inserted Succesfully !";
}
void shopping:: edit()
{

    fstream data,data1;
    int pkey ;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t Product Code ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n File doesn't exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            {
                cout<<"\n\t\t Product new code :";
                cin>>c;
                cout<<"\n\t\t Name of the product";
                cin>>n;
                cout<<"\n\t\t Price :";
                cin>>p;
                cout<<"\n\t\t Discount: ";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record Edited";
                token ++;

            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";

            }
            data>>pcode>>pname>>price>>dis;

        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
        {
            cout<<"\n\n Record Not Found Sorry";

        }
    }

}
void shopping ::rem()
{

    fstream data,data1;
    int pkey;
    int token;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Product  Code:";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {

        cout<<"File doesnt exist";

    }
    else
    {

        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode==pkey)
            {
                cout<<"\n\n\t Product deleted Successfully";
            }
            else{
                data1<<"  "<<pcode<<"  "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt","database.txt");
        if(token==0)
        {

            cout<<"\n\n Record not found";

        }
    }
}
void shopping:: lis()
{

    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|____________________________________________________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice(perquantity)\t\tDiscount(%)\n";
    cout<<"\n\n|_____________________________________________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\t\t\t\t"<<dis<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();

}
void shopping::order()
{

    fstream data,data1;

    char choice;

    flag=1;
    //cout<<"\n\n\t\t\t\t RECIPT";
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty Database";
    }
    else{

        data.close();
        lis();
        cout<<"\n________________________________\n";
        cout<<"\n|                               \n";
        cout<<"\n       Please Place the order   \n";
        cout<<"\n|_______________________________\n";
        cout<<"\n\n Enter Customer Name";
        cin>>Custname;
        do{
            m:
            cout<<"\n\n Enter the product code:";
            cin>>arrc[c];
            cout<<"\n\nEnter the Product Quantity:";
            cin>>arrq[c];
            for(int i=0;i<c;i++)
            {

                if(arrc[c]==arrc[i])
                {
                    cout<<"\n\n Duplicate product code.Please try again!";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another product? if yes then press y else n";
            cin>>choice;

            }
            while(choice=='y');
    }


}

class bill:public shopping
{
public:
     void Receipt()
    {
        if(flag==1)
        {
			fstream data;
			system("cls");
			cout<<"\t\t\t\tSUPER MARKET BILLING SYSTEM\n\n";
			cout<<"CUSTOMER NAME : \t"<<Custname;
			cout<<"\n\n\t\t______________________RECEIPT______________________\n";
                cout<<"\nProductno\tProduct Name\t productquantity\tpriceAmount\tAmount With Discount\n";


                    data.open("database.txt",ios::in);
                    data>>pcode>>pname>>price>>dis;
                    while(!data.eof())
                    {
                        for(int i=0;i<c;i++)
                            {

                                if(pcode==arrc[i])
                                {
                                    amount=price*arrq[i];
                                    dis=amount-(amount*dis/100);
                                    total=total+dis;
                                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t        "<<arrq[i]<<"\t\t    "<<price<<"\t\t    "<<dis;
                                }


                            }
                        data>>pcode>>pname>>price>>dis;
                    }
                data.close();
                cout<<"\n\n_______________________________________";
                cout<<"\n Total Amount :"<<total<<endl;
                cout<<"\t\tThanks for Purchasing ...You are Always Welcome!!!!\n\n";
        }
    }
};
int main()
{
    bill s;
    s.menu();
    s.Receipt();
    return 0;
}

