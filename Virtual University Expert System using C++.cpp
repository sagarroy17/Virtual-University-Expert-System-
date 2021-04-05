///****************************************************************
///                   HEADER FILE USED IN PROJECT
///****************************************************************
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;


///****************************************************************
///                  STUDENT CLASS
///****************************************************************

class student
{
private:
    float s1,s2,s3,s4,s5,s6;
    float cgpa;

    float sum ;
    int password=456;  ///for


    char mname[50];   //father name & mother name
    char fname[50];
    int pass ;

    int dd,mm,yy;
    int UserNumber;
    char Grade;
    char sub_name[20];
	int rollno;
	char name[50];
	char dename[50];

	double per;
	char grade;
	void calculate();
	void show_result();

public:
	void inputdata();	///function to accept data from user
	void showdata() ;	///function to show data on screen
	void show_tabular() const;
	int retrollno() const;
    int retpass() const;
    int othpw() const;
}; ///class ends here


void student::calculate()
{

cout<<"**STUDENT MARKS SHEAT CALCULATOR**"<<endl;

cout<<"\n\n\n";

cout<<endl;
cout<<"enter obtained marks of 1st subjct"<<endl;
cin>>s1;
cout<<"enter obtained marks of 2nd subjct"<<endl;
cin>>s2;
cout<<"enter obtained marks of 3rd subjct"<<endl;
cin>>s3;
cout<<"enter obtained marks of 4th subjct"<<endl;
cin>>s4;
cout<<"enter obtained marks of 5th subjct"<<endl;
cin>>s5;
cout<<"enter obtained marks of 6th subjct"<<endl;
cin>>s6;
cout<<"********************************"<<endl;

 sum=s1+s2+s3+s4+s5+s6;
cgpa=(sum)/(6);
}

void student ::show_result()
{
cout<<"your cgpa ....."<<cgpa<<endl;
}

void student::inputdata()
{
	cout<<"\n 1 . Enter The roll number of student "<<endl;
	cin>>rollno;
	cin.ignore();
	cout<<"\n 2 . Enter The Name of student "<<endl;
	gets(name);
	cin.ignore();
	cout<<"\n 3 . Enter Father name  :"<<endl;
	gets(fname);
    cin.ignore();
    cout<<"\n 4 . Enter mother name : "<<endl;
    gets(mname);
    cin.ignore();
    cout<<"\n 5 . Enter password no. :"<<endl;
    cin>>pass;
    cin.ignore();
    cout<<"\n 6. enter department name"<<endl;
    gets(dename);
    cin.ignore();
    cout<<"\n 7. Enter date of birth :"<<endl;

    cout<<"   Date:"<<endl;
    cin>>dd;

    cout<<"   Month:"<<endl;
    cin>>mm;

    cout<<"   Year :"<<endl;
    cin>>yy;

	calculate();
}

void student::showdata()
{
	cout<<"\nRoll number of student : "<<rollno<<endl;
	cout<<"\nName of student : "<<name<<endl;
	cout<<"\nfather name: "<<fname<<endl;
	cout<<"\nmother name: "<<mname<<endl;
	cout<<"\npassword number  : "<<pass<<endl;
	cout<<"\ndepartment name : "<<dename<<endl;

    cout<<"\nDate of birth....."<<endl;
    cout<<dd<<"/"<<mm<<"/"<<yy<<endl;

show_result();

}


int  student::retrollno() const
{
	return rollno;
}


int student :: retpass() const
{
    return pass;
}

int student:: othpw() const
{
    return password;
}
///***************************************************************
///    	STAND-ALONE FUNCTION
///****************************************************************

void write_student();	//write the record in binary file
void display_all();		//read all records from binary file
void display_studentdata(int, int );	//accept rollno and read record from binary file
void modify_student(int, int );	//accept rollno and update record of binary file
void delete_student(int, int );	//accept rollno and delete selected records from binary file
void class_result();	//display all records in tabular format from binary file
void result();	//display result menu

void entry_menu(int);	///FOR OTHRITY


///***************************************************************
///    	THE MAIN FUNCTION OF PROGRAM
///****************************************************************


int main()
{
    int num;
    int digit;
	char ch;
	cout.setf(ios::fixed|ios::showpoint);///
	cout<<setprecision(2); /// program outputs decimal number to two decimal places

	do
	{
		system("cls");
        cout<<"\n\n\n\t\t\t****WELCOME*****"<<endl;
        cout<<endl;
        cout<<"\n\n\n\n\n\n\n\t\t\t~~~~~VIRTUAL UNIVERSITY & EXPERT SYSTEM~~~~~"<<endl;
        cout<<endl<<endl<<endl;
		cout<<"\n\n\n\t~~~~~MAIN MENU~~~~~"<<endl<<endl;
		cout<<"\n\n\t01. STUDENT MENU ";
		cout<<"\n\n\t02. AUTHORITY MENU";
		cout<<"\n\n\t03. EXIT";
		cout<<"\n\n\tPlease Select Your Option (1-3) "<<endl;
		cin>>ch;
		switch(ch)
		{
			case '1':

			    cout<<"\n\n\tPlease Enter The roll number ";
			     cin>>num;
			    cout<<"\n\n\tPlease Enter The password number ";
			    cin>>digit;

				display_studentdata(num, digit);
				 break;

			case '2': entry_menu(num);
				break;
			case '3':
				break;
			//default :cout<<"\a";
		}
    }while(ch!='3');
	return 0;
}




///***************************************************************
///    	ENTRY / EDIT MENU FUNCTION
///****************************************************************

void entry_menu(int pw)
{
   student st;
   cout<<"enter othraty password"<<endl;
   cin>>pw;
   if(st.othpw()==pw)
    {

	char ch;

	int num;
	int digit;

	system("cls");

	cout<<"\n\n\n\tENTRY MENU";
	cout<<"\n\n\t1.CREATE STUDENT RECORD";
	cout<<"\n\n\t2.DISPLAY ALL STUDENTS RECORDS";
    cout<<"\n\n\t3.MODIFY STUDENT RECORD";
	cout<<"\n\n\t4.DELETE STUDENT RECORD";
	cout<<"\n\n\t5.BACK TO MAIN MENU";
	cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
	cin>>ch;
	system("cls");
	switch(ch)
	{
	case '1':	write_student();
	            break;
	case '2':	display_all();
	             break;

	case '3':	cout<<"\n\n\tPlease Enter The roll number ";
	           cin>>num;
	           cout<<"\n\n\tPlease Enter The password  ";
	            cin>>digit;
				modify_student(num, digit);
				break;

	case '4':	cout<<"\n\n\tPlease Enter The roll number ";
                cin>>num;
                cout<<"\n\n\tPlease Enter The password ";
                 cin>>digit;
				delete_student(num, digit);
				break;

	case '5':	break;

	//default:	cout<<"\a"; entry_menu();
	}
}
else
{
    cout<<"file cannot open"<<endl;
    cin.ignore();
}
}
///***************************************************************
///   	function to write in file
///****************************************************************

void write_student()
{
	student st;
	ofstream outFile;
	outFile.open("student.dat",ios::binary|ios::app);
	st.inputdata();
	outFile.write((char *) (&st), sizeof(student));
	outFile.close();
    cout<<"\n\nStudent record Has Been Created ";
	cin.ignore();
	cin.get();
}

///***************************************************************
///    	function to read all records from file
///****************************************************************

void display_all()
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	cout<<"\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n";
	while(inFile.read((char *)(&st), sizeof(student)))
	{
		st.showdata();
		cout<<"\n\n====================================\n";
	}
	inFile.close();
	cin.ignore();
	cin.get();
}

///***************************************************************
///    	function to read specific record from file
///****************************************************************

void display_studentdata(int n, int p)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();  ///instead of having your program close as soon as it executes it waits for you to press a key so you can see its output.
		return;
	}


	bool flag=false;
    while(	inFile.read((char *)(&st), sizeof(student)))
	{
		if(st.retrollno()==n && st.retpass()==p )
		{
		    flag=true;
	  		 st.showdata();
			//flag=true;

		}
	}

	inFile.close();

	if(flag==false)

		cout<<"\n\nrecord not exist";

	cin.ignore();
	cin.get();
}

///***************************************************************
///    	function to modify record of file
///****************************************************************

void modify_student(int n, int p)
{
	bool found=false;
	student st;
	fstream File;
	File.open("student.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		//cin.get();
		return;
	}

	while(!File.eof() && found==false)
	{
		File.read((char *) (&st), sizeof(student));
		if(st.retrollno()==n && st.retpass()==p)
		{
			st.showdata();
			cout<<"\n\nPlease Enter The New Details of student"<<endl;
			st.inputdata();
		    int pos=(-1)*static_cast<int>(sizeof(st));
		    File.seekp(pos,ios::cur);
		    File.write((char *)(&st), sizeof(student));
		    cout<<"\n\n\t Record Updated";
		    found=true;
		}
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
	cin.ignore();
	cin.get();

}

///***************************************************************
///    	function to delete record of file
///****************************************************************

void delete_student(int n ,int p)
{
	student st;
	ifstream inFile;
	inFile.open("student.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read((char *) (&st), sizeof(student)))
	{
		if(st.retrollno()!=n)
		{
			outFile.write((char *) (&st), sizeof(student));
		}
	}
	outFile.close();
	inFile.close();
	remove("student.dat");
	rename("Temp.dat","student.dat");
	cout<<"\n\n\tRecord Deleted ..";
	cin.ignore();
	cin.get();
}


///***************************************************************
///   			END OF PROJECT
///***************************************************************
