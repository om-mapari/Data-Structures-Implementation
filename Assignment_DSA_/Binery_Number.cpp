
#include <iostream>
using namespace std;
class binery
{
    string b;

public:
    void read();
    void check_bin();
    void once_complemnt();
    void display();
};
void binery ::read()
{
    cout << "Enter binery number : ";
    cin >> b;
}
void binery ::check_bin()
{
    for (int i = 0; i < b.length(); i++)
    {
        if (b.at(i) != '0' && b.at(i) != '1')
        {
            cout << "Not a binery number ";
            exit(0);//Direct Exit the Program
        }
        else {
            cout << "Number is binery "<<endl;
            break;
        }
    }
}
void binery :: once_complemnt(){
    for (int i = 0; i < b.length(); i++)
    {
        if (b.at(i)=='0'){
            b.at(i)='1';
        }
        else
        {
            b.at(i)='0';
        }
        
    }
    display()   ;
}
void binery:: display(){
    for (int i = 0; i < b.length(); i++)
    {
        cout<<b.at(i);
    }
    cout<<""<<endl;
    
}
    int main()
    {
        binery bin;
       

        int choice=0;
        while (choice!=5)
        {
            cout<<"\nEnter 1 to read : "<<endl;
            cout<<"Enter 2 to check binery : "<<endl;
            cout<<"Enter 3 for once complement : "<<endl;
            cout<<"Enter 4 to display : "<<endl;
            cout<<"Enter 5 to Exit : "<<endl;
            cout<<"Enter Choice : ";
            cin>>choice;

           switch (choice)
           {
           case 1:
                bin.read();
               break;
           case 2:
               bin.check_bin();
               break;
           case 3:
               bin.once_complemnt();
               break;
           case 4:
               bin.display();
               break;    
           default:
               cout<<"\nEnter correct Choice : "<<endl;
               break;
           }
        }
        

        return 0;
    }