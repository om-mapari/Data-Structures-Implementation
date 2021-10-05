
#include <iostream>
using namespace std;
//array of object with member having array
class student{
	public:
	string name;
	int marks[5];
	int rollno;
	float percentage;
	int totelmarks;
};

void bubbleSort(student stud[]){
	for(int i=0;i<4;i++){
		bool sort = true;
		for (int j=0;j<4-1-i;j++){
			if(stud[j].percentage>stud[j+1].percentage){

				swap(stud[j],stud[j+1]);
				sort = false;

			}
		}
		if(sort){break;}
	}
} ;

int main() {
	student stud[4];
	double percentage[4];
	for (int i=0;i<4;i++){
		cout<< "Enter Name : ";
		cin>>stud[i].name;
		cout<< "Roll No : ";
		cin>>stud[i].rollno;

	    int sum = 0;
		for (int j=0;j<5;j++){
			cout<<"Enter marks of Subject "<<j+1<<" :";
			cin>> stud[i].marks[j];
			sum+=stud[i].marks[j];
		}

		stud[i].totelmarks=sum;
		stud[i].percentage=stud[i].totelmarks/5;
		percentage[i] = stud[i].percentage;
        cout<<"\n";

	}
	bubbleSort(stud);

	for (int i = 0; i < 4 ; i++){
		cout<<stud[i].name<<" "<<stud[i].rollno<< " "<<stud[i].percentage<<" "<<stud[i].totelmarks<<endl;
	}

}
