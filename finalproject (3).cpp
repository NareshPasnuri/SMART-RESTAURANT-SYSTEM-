
#include<iostream>
#include<fstream>
#include<string.h>
#include <cmath>  
#include <limits> 
#include <map> 
#include<conio.h> 
#include<vector>


using namespace std;

//-----------Keeping Track of Operations-----------------

class expenses{
	public:
		void purchase();
		void dis_mon(int mon,int year);
		void pur_mon(int mon,int year);
};

vector <pair<int,int> > amt;
vector<pair<int,int> > amt_maintain;
vector <pair<int,int> > month;
vector<string>outf;

void expenses::dis_mon(int mon,int year)
{
	int a;
	for(int i=0;i<month.size();i++)
	{
		if(month[i].second==year && month[i].first==mon)
		{
			if(amt[i].second==year && amt_maintain[i].second==year){
		cout<<"Total Expenses in month "<<month[i].first<<" in year "<<month[i].second<<" is "<<amt[i].first+amt_maintain[i].first<<"$"<<endl;
	}
		}
	}
}

void expenses::pur_mon(int mon,int year)
{
	cout<<"Your expenses in month "<<mon<<" in year "<<year<<" the following: "<<endl;
	for(int i=0;i<month.size();i++)
	{
		if(month[i].second && month[i].first==mon)
		{
			if(amt[i].second==year && amt_maintain[i].second==year){
			
			cout<<"Money spent on on Items: "<<outf[i]<<" items for "<<amt[i].first<<endl;
			cout<<"Money spent on Hotel Maintanace is: "<<amt_maintain[i].first<<endl;
			}
		}
	}
}

void expenses::purchase(){
	int ch,mon,amount,year;
	int amount_maintain;
	expenses ex;
	
string items;
cout<<"**KEEPING TRACK OF RECORDS**"<<endl;
while(ch!=4){
	cout<<"Menu\n1. Add Monthly Expenses\n2. Track spending per month\n3. View expenses per month\n4. Exit"<<endl;
	cout<<"Enter your choice: ";
	cin>>ch;
	switch(ch)
	{
		case 1:
		cout<<"Please Enter the Year of Purchase: ";
		cin>>year;
		
		cout<<"Please Enter the month of purchase: ";
		cin>>mon;
		if(mon>12||mon<1)
		{
			cout<<"Invalid month";
		}
		month.push_back({mon,year});
		cout<<"Please enter the no.of items purchased: ";
		cin>>items;
		outf.push_back(items);
		cout<<"Please enter Price of items purchased: ";
		cin>>amount;
		amt.push_back({amount,year});
		cout<<"Enter the amount spent on Restaurant Maintanance: ";
		cin>>amount_maintain;
		amt_maintain.push_back({amount_maintain,year});
		break;
	
		case 2:
		cout<<"Please enter the year of purchase: ";
		cin>>year;
		cout<<"Please Enter the month of purchase: ";
		cin>>mon;
		ex.dis_mon(mon,year);
		break;
	
		case 3:
		cout<<"Please enter the year of purchase: ";
		cin>>year;
		cout<<"Please Enter the month of purchase: ";
		cin>>mon;
		ex.pur_mon(mon,year);
		break;
}

}
}


//------------------Customer Feedback-------------------------

class customer_feedback{
	public:
		void StoreComplaint();
};

class admin_feedback{
	public:
		void view_complaint();

};

struct node
{
int complaint_number;
string customerName;
string date;
string x;
 
node *prev;
node *next;
node *link;
 
}*q, *temp;
 
 
node *start_ptr = NULL;
node *head = NULL;
node *last = NULL;
 


void customer_feedback::StoreComplaint()
{

	cout<<" ================================================\n";
	cout<<"|            -------FEEDBACK----------         |\n";
	cout<<" ================================================\n\n";
	cout <<"\nAdd Your Feedback Details\n";
	cout <<"____________\n\n";
	 
	node *temp;
	temp = new node;
	cout << "Type Feedback no: ";
	cin >> temp->complaint_number;
	cout<< "Enter Your Name: ";
	cin.ignore();
	getline(cin, temp->customerName);
	cout<<"Enter Date(DD/MM/YY) : ";
	cin>>temp->date;
	cout << "Feedback Description:";
	cout<<"( 1000 words maximum ) \n";
	cin.ignore();
	getline(cin, temp->x);
	 
	cout<<"==========================================================================="<<endl;
	cout << "Feedback added Successfully"<<endl;
	cout<<"==========================================================================="<<endl;
	 
	
	 
	temp->next=NULL;
	if(start_ptr!=NULL)
	{
	temp->next=start_ptr;
	}
	start_ptr=temp;

}

 
void admin_feedback::view_complaint()
{
	int num;
	bool found; //variable to search
	
	node *temp;
	 
	temp=start_ptr;
	found = false;
	cout<<"\n";
	cout<<" ================================================\n";
	cout<<"|          ---------FEEDBACK-----------          |\n";
	cout<<" ================================================\n\n";
	cout<<" Enter the Feedback Number To Look into The Complaint Details\n";
	cin>>num;
	cout<<"\n";
	cout<<"---------------------------------------------------------------------------"<<endl;
	cout <<"\t\tHere is the Feedback\n";
	cout<<"---------------------------------------------------------------------------"<<endl;
	 
	 
	if(temp == NULL)
	{
	cout << "\tThere is no Feedback to show\n\t\t\tSo The List is Empty\n\n\n";
	}
	while(temp !=NULL && !found)
	{
	if (temp->complaint_number==num)
	{
	found = true;
	}
	else
	{
	temp = temp -> next;
	}
	        
	if (found){
	        	
	cout <<"Feedback Number : "<<temp->complaint_number;
	cout <<"\n";
	cout<<"Customer Name: "<<temp->customerName<<endl;
	 
	cout<<"Feedback Date : "<<temp->date<<endl;
	 
	cout<<"___________________________"<<endl;
	cout<<"-------------------------"<<endl;
	cout<<"|Feedback description: |"<<endl;
	cout<<"-------------------------"<<endl;
	cout<<temp->x;
	 
	cout <<"\n";
	cout<<"___________________________"<<endl;
	 
	}
	else{
		cout<<"No Feedback is registered under this number"<<endl;
	}
	 
	 
	}
}





//------------------------PARKING--------------------------------

int parking_space = 0;
int parking_hist = 0;
int req_slot=0;
vector<int> v;


class parking{
	public:
		void menu();
		void insert_vehicle();
		void exit_vehicle();
		void View_allInfos();
		void history_infos();
		void view_historyParkingInfos();
};


//Total parking slots available- 50

struct infos
{
 char name[15];
 char number[12];
 int Park_slot;
};

struct his_info{
 char name[15];
 char number[12];
 int Park_slot;
};


infos park_info[50];
his_info hist[99];

void parking::menu(){

		int choice;
	do
	{
	cout<<"-----Menu-----"<<endl;
	cout<<"----1 Park Your Vehicle----"<<endl;
	cout<<"----2 Exit Your Vehicle----"<<endl;
	cout<<"----3 View All Parked Vehicles Information----"<<endl;
	cout<<"----4 Number of Parking Slots Available----"<<endl;
	cout<<"----5 History/Log ----"<<endl;
	cout<<"----6. Exit-------"<<endl;
	

	cin>>choice;
	switch(choice)
	{
	case 1:
		insert_vehicle();
		break;
	
	case 2:
		exit_vehicle();
		break;
	
	case 3:
		View_allInfos();
		break;
	
	case 4:
		cout<<endl<<"-------------(Info)---------------------------"<<endl<<endl;
		cout<<"Space Slot Total Available = "<<50-parking_space<<endl;
		cout<<endl<<"-------------(Info)---------------------------"<<endl<<endl;
		break;
	
	case 5:
		view_historyParkingInfos();
		break;
	
	case 6:
		break;
	
	
	}
	
	
	}while(choice!=6);
	}
	
	void parking::insert_vehicle()
	{
	
	    cout<<"----------PARKING-------------"<<endl;
	
	//add new vehicle owner information to fill the parking slot ticket is currently processing for purchasing
	cout<<"Please provide your name : ";
	cin.ignore();
	cin.getline(park_info[parking_space].name,15,'\n');
	
	cout<<"Please provide your Vehicle no : ";
	istream& ignore (streamsize n = 1, int delim = EOF);
	cin.getline(park_info[parking_space].number,15,'\n');
	
	
	
	if(v.size()!=0){
		park_info[parking_space].Park_slot=v[0];
		v.erase(v.begin());
	}
	else{
	park_info[parking_space].Park_slot = req_slot+1;
	req_slot++;
	}
	cout<<"please park your vehicle at parking slot number :"<<park_info[parking_space].Park_slot;
	cout<<endl;
	
	
	//copy all new info to history logs as well
	history_infos();
	
	parking_space++;

}


void parking::exit_vehicle()
{
	if(parking_space==0){
		cout<<"No vehicles are parked!";
	}
	else{
cout<<"Do you wish to remove vehicle from parking slot?..Press Y for Yes and N for No : "<<endl;
char cho;
cin>>cho;
if(cho == 'Y' || cho == 'y')
{
int slot;
cout<<"please enter slot # :"<<endl;
cin>>slot;

int del = 0;
//verifying vehicle is available in slot that is mentioned by operator
for(int j=0;j<=parking_space;j++)
{
if(slot == park_info[j].Park_slot)
{
del = j;
break;
}
}

v.push_back(park_info[del].Park_slot);
//swap next values inside the old slots
char *name[15];
char *phn[15];
int slot_pos = 0;

for(int k=del;k<parking_space;k++)
{

if(k==parking_space)
{
strcpy(park_info[k+1].name,'\0'); 

strcpy(park_info[k+1].number,'\0');

park_info[k+1].Park_slot = '\0';
break;

}


if(k<parking_space)
{
strcpy(park_info[k].name,park_info[k+1].name); 
//*park_info[k].name  = *park_info[k+1].name;

strcpy(park_info[k].number,park_info[k+1].number);
//*park_info[k].phone = *park_info[k+1].phone;

slot_pos = park_info[k+1].Park_slot;
park_info[k].Park_slot = slot_pos;
}

} 



//program must control or divert & stop the negative value of global variable

if(parking_space > 0)
{
parking_space--;
} 

}
}
}


void parking::View_allInfos()
{
if(parking_space == 0)
{
cout<<endl<<"-------------Info---------------------------"<<endl<<endl;
cout<<"All Slots are Available no vehicle is Parked right now"<<endl;
cout<<endl<<"-------------Info---------------------------"<<endl<<endl;

return;
}
else
{
cout<<endl<<"-------------Info---------------------------"<<endl<<endl;
for(int i=0;i<parking_space;i++)
{
cout<<endl<<endl;

cout<<"name : "<<park_info[i].name<<endl;
cout<<"Vehicle No : "<<park_info[i].number<<endl;
cout<<"Slot number :"<<park_info[i].Park_slot<<endl;

}
cout<<endl<<"-------------Info---------------------------"<<endl<<endl;
}
}


void parking::history_infos()
{
strcpy(hist[parking_hist].name,park_info[parking_space].name);
strcpy(hist[parking_hist].number,park_info[parking_space].number);
hist[parking_hist].Park_slot = park_info[parking_space].Park_slot;

parking_hist++;
}


void parking::view_historyParkingInfos()
{
if(parking_hist == 0)
{
cout<<endl<<"-------------Info---------------------------"<<endl<<endl;
cout<<"In history no Vehicle is Parked right now"<<endl;
cout<<endl<<"-------------Info---------------------------"<<endl<<endl;

return;
}
else
{

cout<<endl<<"-------------(Info)---------------------------"<<endl<<endl;
for(int i=0;i<parking_hist;i++)
{
cout<<endl<<endl;
cout<<"name : "<<hist[i].name<<endl;
cout<<"cell no : "<<hist[i].number<<endl;
cout<<"Slot number :"<<hist[i].Park_slot<<endl;

}
cout<<endl<<"-------------(Info)---------------------------"<<endl<<endl;
}


}




//-------------------------------TABLE RESERVATIONS---------------------------------------

class table{
	public:
		void display();
		void reserve();
		void bookTable();
		void cancelTable();
};

map<int,bool> m;
int tableNumber;
void table::display(){

    cout<<"\t\t\t\t*****SMART RESTAURANT*****\t\t\t\t"<<endl<<endl;

    cout<<"--------(1)Table Reservation------"<<endl;
    cout<<"-----(2)Cancel the Reservation----"<<endl;
    cout<<"-----------(3)EXIT----------------"<<endl;

}

void table::reserve(){

    int choice;

    display();

    cout<<"Enter the choice: ";
    cin>>choice;
    cout<<endl;

    switch(choice){
    case 1:
        bookTable();
        break;

    case 2:
        cancelTable();
        break;

    case 3:
        break;
    }
}


void table::bookTable(){

    int chairs[5][7];
    int a=1;
    string str;

    for(int i=0;i<5;i++){
        for(int j=0;j<7;j++){
            chairs[i][j]=a++;
        }
    }


    cout<<"------------TABLE RESERVATION---------"<<endl;
    for(int i=0;i<5;i++){
        for(int j=0;j<7;j++){
            cout<<chairs[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"Enter Table Number: ";
    cin>>tableNumber;
    cout<<endl;

    if(tableNumber<1 || tableNumber>35){
        cout<<"Enter a valid Table Number(1-35)"<<endl;
        bookTable();
    }
    else{

     if(m.find(tableNumber)!=m.end()){
        cout<<"This table is already reserved"<<endl;
        cout<<"Select another table "<<endl;
        bookTable();

    }
    else{
            m[tableNumber]=true;
            cout<<"Table Number "<<tableNumber<<" has been successfully reserved."<<endl;
                cout<<endl;
                cout<<"--------------------------------------"<<endl;
                cout<<"Would you like to book another table(Y/N): ";
                cin>>str;
                cout<<endl;

                if(str=="Y")
                    bookTable();
                else{
                    cout<<"THANK YOU"<<endl;
                    reserve();
                }

    }
    }

}

void table::cancelTable(){

    string str;

    cout<<"Enter the Table Number you want to cancel the reservation for: ";
    cin>>tableNumber;
    cout<<endl;
    

    if(m[tableNumber]==true){
        m[tableNumber]==false;
        cout<<"Your Reservation is Cancelled!!"<<endl;
    }
    else{
    	cout<<"The table Number you entered is not yet reserved"<<endl;
	}

    cout<<"Would you like to cancel the reservation for another table(Y/N): ";
    cin>>str;
    cout<<endl;

                if(str=="Y")
                    table::cancelTable();
                else{
                    cout<<"THANK YOU"<<endl;
                    table t;
                    t.reserve();
                }

}




// -----------------------------------ONLINE ORDERS-------------------------------------------

class online_orders{
	public:
		void menu();
		void order();
		void show_bill(float,float,float,float);
};



void online_orders::menu(){
	

 cout<<"*****************************  MENU   ****************************"<<endl;

 cout<<"** (0) Chicken Biryani                      Rs.150              **"<<endl<<endl;
 cout<<"** (1) Chicken Palao                        Rs.120              **"<<endl<<endl;
 cout<<"** (2) Veg Biryani                          Rs.80               **"<<endl<<endl;
 cout<<"** (3) Coke                                 Rs.70 per litre     **"<<endl<<endl;
 cout<<"** (4) Exit                                 Exit the menu       **"<<endl<<endl;
 cout<<"******************************************************************"<<endl<<endl;
 cout<<endl;

}

void online_orders::order(){

     int choice;
     int no_items;
     float tax=0,sum=0,total=0;
     int price[]={150,120,80,70}; //prices of individual items placed in an array considering choice as index

     do{
            online_orders::menu();
            while(choice!=4){
                cout<<"Please select the Order Number: ";
                cin>>choice;
                if(choice==4){
                    break;
                }

                if(choice<0 || choice>4){
                    cout<<"Please enter valid Choice"<<endl;
                    cin>>choice;
                }

                 cout<<"Please enter the No.of Items: ";
                cin>>no_items;
                sum+=price[choice]*no_items;

                tax=0.01*sum;
                total=tax+sum;
                }
                
     }while(choice!=4);

 	int delivery_charges=0;
    int selection;
	int sector_distance=0;
  
  cout<<"FOOD DELIVERY"<<endl;
  
  int  Distance[12]={10,14,15,21,25,28,30,33,35,40,42,44};
  cout<<"We Deliver in these sectors"<<endl;
  cout<<"press 1 for sector  i8 "<<endl;
  cout<<"press 2 for sector  i9 "<<endl;
  cout<<"press 3 for sector  i10"<<endl;
  cout<<"press 4 for sector  i11"<<endl;
  cout<<"press 5 for sector  g8 "<<endl;
  cout<<"press 6 for sector  g9 "<<endl;
  cout<<"press 7 for sector  g10"<<endl;
  cout<<"press 8 for sector  g11"<<endl;
  cout<<"press 9 for sector  f8 "<<endl;
  cout<<"press 10 for sector f9 "<<endl;
  cout<<"press 11 for sector f10"<<endl;
  cout<<"press 12 for sector f11"<<endl;
  cout<<"Select your sector "<<endl;
  cin>>selection;
  sector_distance=Distance[selection]-20;
  if(Distance[selection-1]>20)
  {
   delivery_charges=sector_distance*2;  
    
  }
  else
  {
   delivery_charges=0;
   cout<<"Free Delivery!!"<<endl;
  } 
  total=total+delivery_charges;
  show_bill(sum,total,tax,delivery_charges);
  
}

void online_orders::show_bill(float bill,float total,float taxCal,float delivery_charges){
     cout<<"Bill: "<<"Rs."<<bill<<endl;
     cout<<"Delivery Charges: "<<"Rs."<<delivery_charges<<endl;
     cout<<"Tax: "<<"Rs."<<taxCal<<endl;
     cout<<"Total: "<<"Rs."<<total<<endl;
 }



//-----------------------------LOGIN-------------------------

string usn;
int tm;


class login{
	public:
		void menu();
		void login_customer();
		void login_admin();
		void valid(string str);
}; 

void login::menu(){
	int choice;

	cout<<"---------------------------------------Welcome to Smart Restaurant system!--------------------------------------------"<<endl;
	cout<<"Choose one option: "<<endl;
	cout<<"(1) Customer Login"<<endl;
	cout<<"(2) Administrator Login"<<endl;
	cout<<"(3) Exit"<<endl;
    cin>>choice;
    
    switch(choice){
    	case 1: 
	    	login::login_customer();
	    	break;
    	case 2:
    		login::login_admin();
    		break;
		case 3:
			break; 
	}
}

void login::valid(string str)
{
    string dir,user;
    ifstream file;
    dir = str+".txt";
    file.open(dir.c_str());
    if(!file.is_open() && file.fail())
    {
        //file.close();
        return;
    }
    else
    {
        tm++;
        if(tm==3)
        {
            cout<<"\nThis username already exists\nPlease try Again.";
            //file.close();
            return;
        }
        cout<<"\nThis username already exists!\nCreate a username:";
        cin>>usn;
        //file.close();
        valid(usn);
    }
}

void login::login_customer(){
	
	
	int i,exit=0;
    string ans,psd,name,fname,bio,usern,pw,line,nusn;
    ofstream fileo;
    ifstream filei;
    
    cout<<"----------------------------Welcome to Smart Restaurant system!--------------------------------"<<endl;
    while(exit==0)
    {
    	int choice;
		
		cout<<"Choose one option: "<<endl;
		cout<<"(1) Login"<<endl;
		cout<<"(2) SignUp"<<endl;
		cout<<"(3) Log out"<<endl;
		cin>>choice;
        if(choice==1)
        {
            cout<<"Enter your username:";
            cin>>usn;
            cout<<"\nEnter your password:";
            cin>>psd;
            fname=usn+".txt";
            filei.open(fname.c_str());
            if(!filei.is_open() && filei.fail())
            {
                cout<<"\nYou are not registered, please register before logging in.\n";
                filei.close();
                continue;
            }
            getline(filei,usern);
            getline(filei,line);
            getline(filei,pw);
            if(usn==usern && psd==pw)
            {
                cout<<"\nYou are successfully logged in\n";
                int option;
            do{
	  
                cout<<"Choose one option: "<<endl;
				cout<<"(1) Order your food in Online"<<endl;
				cout<<"(2) Reserve a table at Restaurant"<<endl;
				cout<<"(3) View Parking at Restaurant"<<endl;
				cout<<"(4) Give Feedback"<<endl;
				cout<<"(5) Exit"<<endl;
				cin>>option;
          
                switch(option){
                	case 1:
                		online_orders ordering;
                		ordering.order();
                		break;
                	case 2:
                		table t;
                		t.reserve();
                		break;
                	case 3:
                		parking p;
                		p.menu();
                		break;
                	case 4:
                		customer_feedback c;
                		c.StoreComplaint();
                		break;
                	case 5:
                		break;
				}
			}while(option!=5);
				
                getline(filei,line);
                filei.close();
            }
            else{
                cout<<"\nWrong username or password!\nPlease try Again.\n";
            }
            cout<<endl;
        }
        else if(choice==2)
        {
            cout<<"\nEnter your name:";
            cin.ignore();
            getline(cin,name);
            cout<<"\nCreate a username:";
            cin>>usn;
            tm=0;
            login::valid(usn);
            if(tm>=3)
            {
                continue;
            }
            cout<<"\nCreate a password:";
            cin>>psd;
            fname=usn+".txt";
            //cout<<fname;
            fileo.open(fname.c_str());
            fileo<<usn<<endl<<name<<endl<<psd<<endl;
            cout<<"\nYou are successfully registered:)";
            cin.ignore();
            getline(cin,bio);
            fileo.close();
        }
        else if(choice==3)
        {
        	
            exit=1;
            login::menu();
        }
        else{
        	break;
		}
    }
    cout<<"\n------------------------------Thank you for visiting:)---------------------------------\n";

}

void login::login_admin(){
	
	int choice,i,exit=0;
	string ans,psd,name,fname,bio,usern,pw,line,nusn;
    ofstream fileo;
    ifstream filei;
    cout<<"----------------------------Welcome to Smart Restaurant system!--------------------------------"<<endl;
    while(exit==0)
    {
        
		cout<<"Choose one option: "<<endl;
		cout<<"(1) Login"<<endl;
		cout<<"(2) SignUp"<<endl;
		cout<<"(3) Log out"<<endl;
		cin>>choice;
        if(choice==1)
        {
            cout<<"Enter your username:";
            cin>>usn;
            cout<<"\nEnter your password:";
            cin>>psd;
            fname=usn+".adm";
            filei.open(fname.c_str());
            if(!filei.is_open() && filei.fail())
            {
                cout<<"\nYou are not registered, please register before logging in.\n";
                filei.close();
                continue;
            }
            getline(filei,usern);
            getline(filei,line);
            getline(filei,pw);
            if(usn==usern && psd==pw)
            {
                cout<<"\nYou are successfully logged in\n";
                int choice;
                do{
				
                cout<<"Choose an option: "<<endl;
                cout<<"(1) View Feedback"<<endl;
                cout<<"(2) Keeping track of Records"<<endl;
                cout<<"(3) Exit"<<endl;
                cin>>choice;
                
                switch(choice){
                	case 1:
                		admin_feedback a;
						a.view_complaint();
						break;
						
					case 2:
						expenses ex;
						ex.purchase();
						break;
				}
				}while(choice!=3);
	
                getline(filei,line);
                filei.close();
            
        }
            else{
                cout<<"\nWrong username or password!\nPlease try Again.\n";
            }
            cout<<endl;
        }
        else if(choice==2)
        {
            cout<<"\nEnter your name:";
            cin.ignore();
            getline(cin,name);
            cout<<"\nCreate a username:";
            cin>>usn;
            tm=0;
            login::valid(usn);
            if(tm>=3)
            {
                continue;
            }
            cout<<"\nCreate a password:";
            cin>>psd;
            fname=usn+".adm";
            //cout<<fname;
            fileo.open(fname.c_str());
            fileo<<usn<<endl<<name<<endl<<psd<<endl;
            cout<<"\nYou are successfully registered:)";
            cin.ignore();
            getline(cin,bio);
            fileo.close();
        }
        else if(choice==3)
        {
            exit=1;
            login::menu();
        }
        else{
        	break;
		}
    }
    cout<<"\n------------------------------------Thank you!!-------------------------------------------\n";
}


 


int main(){
	login l;
	l.menu();
	return 0;
}

