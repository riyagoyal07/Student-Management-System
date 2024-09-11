#include<iostream>
#include<fstream>
using namespace std;

class record{
	string rollno, name, fname, address, search;
	fstream file;
	public:
		 void addStu();
		 void viewStu();
		 void searchStu();
}obj;

int main(){
	int choice;
	do
	{
	cout<<"\n\n\t\t\t\t ---------------------"<<endl;
	cout<<"\n\n\t\t\t\t 1. ADD STUDENT RECORD "<<endl;
	cout<<"\n\n\t\t\t\t 2. VIEW ALL STUDENTS RECORD "<<endl;
	cout<<"\n\n\t\t\t\t 3. SEARCH FOR A RECORD"<<endl;
	cout<<"\n\n\t\t\t\t 4. Exit "<<endl;
	cout<<"\n\n\t\t\t\t ---------------------"<<endl;
	
	//cout<<"Do you want to do m ?(Y/N)"<<endl;
	cin>>choice;
	
	switch(choice){
		case 1:
			cin.ignore();
			obj.addStu();
		break;
	    case 2:
	    	cin.ignore();
	    	obj.viewStu();
	    break;
	    case 3:
	    	cin.ignore();
		    obj.searchStu();
		break;
		case 4:
		    return 0;
		break;
		default: 
		    cout<<" Please Enter valid choice!...."<<endl;
	}
}while(true);
cout<<"\n\t\t\t Thank You  "<<endl;
	
}

void record::addStu(){
	cout<<"Enter Roll No. of Student"<<endl;
	getline(cin,rollno);
    cout<<"Enter Name of Student"<<endl;
	getline(cin,name);
	cout<<"Enter Father's Name of Student"<<endl;
	getline(cin,fname);
	cout<<"Enter Address of Student"<<endl;
	getline(cin,address);
	
	file.open("student.txt", ios::in | ios::app);
	file<<rollno<<"*";
	file<<name<<"*";
	file<<fname<<"*";
	file<<address<<endl;
	file.close();
	cout<<"Record added successfully!!!!"<<endl;
}

void record:: viewStu(){
	file.open("student.txt", ios::in);
	// read data from files
	getline(file,rollno, '*');
    getline(file,name, '*');
	getline(file,fname, '*');
	getline(file,address, '\n');
	if (!file) {
        cout << "No records found!" << endl;
        return;
    }
	// print the data
	while(!file.eof()){
		cout<<'\n';
		cout<<"Student Roll No : "<<rollno<<endl;
		cout<<"Student Name : "<<name<<endl;
		cout<<"Student Father's Name : "<<fname<<endl;
		cout<<"Student Address : "<<address<<endl;
	// for next round 
	getline(file,rollno, '*');
    getline(file,name, '*');
	getline(file,fname, '*');
	getline(file,address, '\n');
	}
	file.close();
}

void record:: searchStu(){
	cout<<"Enter Student Roll Number : ";
    getline(cin,search);
    
    file.open("student.txt",ios :: in);
    
    if (!file) {
        cout << "No records found!" << endl;
        return;
    }
    
    bool found= false;
    getline(file,rollno,'*');
    getline(file,name,'*');
    getline(file,fname,'*');
    getline(file,address,'\n');
    
    while(!file.eof()){
        if(rollno == search){
        	found = true;
            cout<<endl;
            cout<<"Student Roll Number :: "<<rollno<<endl;
            cout<<"Student Name :: "<<name<<endl;
            cout<<"Student Father Name :: "<<fname<<endl;
            cout<<"Student Address :: "<<address<<endl;       
        }
        getline(file,rollno,'*');
        getline(file,name,'*');
        getline(file,fname,'*');
        getline(file,address,'\n');
        
    }

    if(!found){
    	cout<<"record not found"<<endl;
	}

    file.close();
}
