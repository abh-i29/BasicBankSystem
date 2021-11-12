#include<iostream>
#include<string>
using namespace std;

void resolve(string input,int &dollar,int &cent)
{
    int count=0;
    for(int i=0;i<input.size();i++)
    {
      if(input[i]=='D') {
        dollar=count;
        count=0;
        i+=2;
      }
      else if(input[i]=='C')
      {
        cent=count;
        count=0;
        i++;
      }
      if(i>=input.size()) break;
      count=count*10+(input[i]-'0');
    }
    
    return;
}


class Account{
  int Dollars,Cents;
  public:
  Account()
  {
    Dollars=0,Cents=0;
  }
  void Debit(string input)
  {
    int dollar=0,cent=0;
    resolve(input,dollar,cent);
    Dollars-=dollar;
    Cents-=cent;
    cout<<"Amount Debited Successfully!\n";
  }

  void Credit(string input)
  {
    int dollar=0,cent=0;
    resolve(input,dollar,cent);
    Dollars+=dollar;
    Cents+=cent;
    Dollars+=Cents/100;
    Cents%=100;
    cout<<"Amount Credited Successfully!\n";
  }

  void Check_Balance()
  {
    cout<<"Current Balance is ";
    if(Dollars==0) cout<<Cents<<"C\n";
    else if(Cents==0) cout<<Dollars<<"D\n";
    else cout<<Dollars<<"D "<<Cents<<"C\n";
  }
};

int main()
{
    int y=1;
    Account ob;
    while(y)
    {
      string input;
      cout<<"$ Select an option:\n";
      cout<<"1. Credit\n";
      cout<<"2. Debit\n";
      cout<<"3. Check Balance\n";
      cout<<"4. Exit\n";
      int ch;
      cin>>ch;
      cin.ignore();
      switch(ch)
      {
        case 1: cout<<"Enter Amount to be credited\n";
                getline(cin,input);
                ob.Credit(input);
                break;
        case 2: cout<<"Enter Amount to be debited\n";
                getline(cin,input);
                ob.Debit(input);
                break;
        case 3: ob.Check_Balance();
                break;
        case 4: cout<<"Do you want to close the Application? Press('y') else Press'n'\n";
                char choice;
                cin>>choice;
                if(choice=='y'||choice=='Y') y=0;
                cout<<"Logging off!";
                break;
        default: cout<<"Invalid Key! Please try again.\n";
      }
    }
}



