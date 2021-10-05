
#include <iostream>
using namespace std;
#define MAX 100
 
class student
{
    private:
        char  name[30];
        int   rollNo;
        int   total;
        float perc;
    public:
        void getDetails(void);
        void putDetails(void);
};
 
void student::getDetails(void){
    cout << "Enter name: " ;
    cin >> name;
    cout << "Enter roll number: ";
    cin >> rollNo;
    cout << "Enter total marks out of 500: ";
    cin >> total;
     
    perc=(float)total/500*100;
}
 
void student::putDetails(void){
    cout << "Student details:\n";
    cout << "\nName : "<< name << "\nRoll Number : " << rollNo << "\nTotal :" << total << "\nPercentage:" << perc;
}


 
int main()
{
    student std[MAX]; // array of object
    int n,loop;
    cout << "Enter total number of students: ";
    cin >> n;
     
    for(loop=0;loop< n; loop++){
        cout << "Enter details of student " << loop+1 << ":\n";
        std[loop].getDetails();
    }
     
    cout << endl;
    for(loop=0;loop< n; loop++){
        cout << "Details of student " << (loop+1) << ":\n";
        std[loop].putDetails();
    }
     
    return 0;
}