
#include <iostream>
using namespace std;
  
void move(int n, char from, char to, char inter)                   
{  
    //base condition
    if (n == 1){cout << "Moving disk 1 from  " << from <<" to " << to<<endl;return;};
             
    move(n - 1, from, inter, to);  
    cout << "Moving disk " << n << " from  " << from << " to " << to << endl;                                
    move(n - 1, inter, to, from);  
}  
//Activation Record
//

int main()  
{   
    move(5, 'A', 'C', 'B'); 
    return 0;  
}  
