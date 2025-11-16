#include<iostream>
#include<fstream> // File handling
#include<iomanip> // For pointing value
#include<string>
#include<windows.h> // sleep , cls

using namespace std;


void menu();  // Forward declaration


class customer
{
protected:
    string name , gender , address;
    int age , cusID; 
    string mobile_no;  

public:
    void getdetails()
    {
        ofstream out("old_customer.txt", ios::app);

        cout<<"Enter Customer Id         = ";
        cin>>cusID;

        cout<<"Enter Customer name       = ";
        cin.ignore();
        getline(cin,name);

        cout<<"Enter Customer age        = ";
        cin>>age;

        cout<<"Enter Customer Mobile no. = ";
        cin.ignore();
        getline(cin,mobile_no);

        cout<<"Enter Customer address        = ";
        getline(cin,address);

        cout<<"Enter Customer Gender         = ";
        getline(cin,gender);

        out<<"\n Customer Id : "<<cusID
           <<"\n Name        : "<<name
           <<"\n Age         : "<<age
           <<"\n Mobile No.  : "<<mobile_no
           <<"\n Address     : "<<address
           <<"\n Gender      : "<<gender<<endl;

        out.close();

        cout<<"\n We Saved Your Details \n Note : For future Purpose "<<endl;
    }

    void showdetails()
    {
        ifstream in("old_customer.txt" );

        if(!in)
        {
            cout<<"File Error \n";
        }

        string line;  // To read all line in file 
        while(getline(in,line))
        {
            cout<<line<<endl;
        }

        in.close();
    }
}; 

class cab 
{
protected:   // Can inherited by another class but safe outside class can't access
    int cab_choice;
    int kilometer;
    float cost =0.0;  // prevent garbage value
    float final_cost=0.0;

public:
    void cabDetails()
    {
        cout<<"We Provide cab servies fastest , safest , comfortable around tha counntry "<<endl;
        cout<<"--------------------------------- ABC Cabs ------------------------------\n";
        cout<<"1. Rent a Standard Cab - Rs 20 per kilometer \n";
        cout<<"2. Rent a Premium cab  - Rs 30 per kilometer \n"<<endl;

        cout<<"To calculate the cost of cab service \n";
        cout<<"Enter the Cab choice ";
        cin>>cab_choice;

        cout<<"Enter the Kilometer you have to travel ";
        cin>>kilometer;

        int hire_cab; 

        if(cab_choice==1){
            cost=kilometer*20.00;
            cout<<"Your Total cost for standard cab (in Rupees)= "<<cost<<endl;
            cout<<"Press 1 to hire this cab : or "<<endl;
            cout<<"Press 2 to select another cab: "<<endl;
            cin>>hire_cab;

            system("cls");

            if(hire_cab==1){
                final_cost=cost;
                cout<<"You have successfully Hired a Standard cab "<<endl;
                cout<<"Goto Menu and take receipt "<<endl;
            }
            else if(hire_cab==2){
                cabDetails();
            }
        }
        else if(cab_choice==2){
            cost=kilometer*30.00;
            cout<<"Your Total cost for premium cab (in Rupees)= "<<cost<<endl;
            cout<<"Press 1 to hire this cab : or "<<endl;
            cout<<"Press 2 to select another cab: "<<endl;
            cin>>hire_cab;

            system("cls");

            if(hire_cab==1){
                final_cost=cost;
                cout<<"You have successfully Hired a Premium cab "<<endl;
                cout<<"Goto Menu and take receipt "<<endl;
            }
            else if(hire_cab==2){
                cabDetails();
            }
            else{
                cout<<"Incorrect choice Redirecting to precious menu \n";
                Sleep(109);
                system("cls");
                cabDetails();
            }
        }
        else{
            cout<<"Invalid Input Redirecting to Main menu ";
            Sleep(2000);
            system("cls");
            cabDetails();
        }

        cout<<"\n Press 1 to redirect to menu : ";
        cin>>hire_cab;
        system("cls");
        // Removed menu() call here to fix linker error
    }
};

class Booking
{
protected:
    int choiceHotels;
    int packchoice;
    float hotelCost;

public:
    void Hotels()
    {
        string Hotelno[]={"Arvinda","Dhramraj","Vinayak"};

        cout<<"We currently collaborate with these Hotels : "<<endl;

        for(int i= 0;i<3;i++){

            if(i==0){
                cout<<(i+1)<<" - "<<Hotelno[i]<<"  Family Hotel"<<endl;
            }
            else if(i==1){
                cout<<(i+1)<<" - "<<Hotelno[i]<<"  Family & Children Hotel"<<endl;
            }
            else if(i==2){
                cout<<(i+1)<<" - "<<Hotelno[i]<<"  Alcoholic Hotel"<<endl;
            }
        }

        cout<<"Press any key to go back or\nEnter the Hotel No. You want to book :";
        cin>>choiceHotels;

        system("cls");

        if(choiceHotels==1){

            cout<<"-----------Welcome to Arvinda Hotels----------"<<endl;
            cout<<"We provide best room ,food and services as your budget and lifestyle \n";

            cout<<"1. Standard pack just for (in Rupees) Rs. 5000.00 \n";
            cout<<"2. Premium pack just for (in Rupees) Rs. 10000.00 \n";
            cout<<"3. Luxury pack just for (in Rupees) Rs. 15000.00 \n";

            cout<<"Press another key to back / or Enter the package number : \n";
            cin>>packchoice ;

            if(packchoice==1)
            {
                hotelCost=5000.00;
                cout<<"You have successfully booked standard Pack at Arvinda Hotels \n";
                cout<<"Goto menu and take your receipt \n";
            }
            else if(packchoice==2)
            {
                hotelCost=10000.00;
                cout<<"You have successfully booked Premium Pack at Arvinda Hotels \n";
                cout<<"Goto menu and take your receipt \n";
            }
            else if(packchoice==3)
            {
                hotelCost=15000.00;
                cout<<"You have successfully booked Luxury Pack at Arvinda Hotels \n";
                cout<<"Goto menu and take your receipt \n";
            }
            else{
                cout<<"Ivalid Input ! Redirecting to Previous menu \n Please wait... \n";
                Sleep(2000);
                system("cls");
                cin.clear();
                cin.ignore();
                Hotels();
            }

            int gotomenu;
            cout<<"Press 1 to go main menu : \n";
            cin>>gotomenu;
            system("cls");
            // Removed menu() call here to fix linker error
        }
        else if(choiceHotels==2){

            cout<<"-----------Welcome to Dhramraj Hotels----------"<<endl;
            cout<<"We provide Food , beverage , water park and Fun game for childrens \n";

            cout<<"1. Standard pack just for (in Rupees) Rs. 6000.00 \n";
            cout<<"2. Premium pack just for (in Rupees) Rs. 8000.00 \n";
            cout<<"3. Luxury pack just for (in Rupees) Rs. 16000.00 \n";

            cout<<"Press another key to back / or Enter the package number : \n";
            cin>>packchoice ;

            if(packchoice==1)
            {
                hotelCost=6000.00;
                cout<<"You have successfully booked standard Pack at Arvinda Hotels \n";
                cout<<"Goto menu and take your receipt \n";
            }
            else if(packchoice==2)
            {
                hotelCost=8000.00;
                cout<<"You have successfully booked Premium Pack at Arvinda Hotels \n";
                cout<<"Goto menu and take your receipt \n";
            }
            else if(packchoice==3)
            {
                hotelCost=16000.00;
                cout<<"You have successfully booked Luxury Pack at Arvinda Hotels \n";
                cout<<"Goto menu and take your receipt \n";
            }
            else{
                cout<<"Ivalid Input ! Redirecting to Previous menu \n Please wait... \n";
                Sleep(2000);
                system("cls");
                cin.clear();
                cin.ignore();  // to prevent recusrsion or buffer before calling hotel again
                Hotels();
            }

            int gotomenu;
            cout<<"Press 1 to go main menu : \n";
            cin>>gotomenu;
            system("cls");  // clear screen
            // Removed menu() call here to fix linker error

        }
        else if(choiceHotels==3){

            cout<<"-----------Welcome to Vinayak Hotels----------"<<endl;
            cout<<"We provide Disco Nights , Alcoholic Party , Non-veg and Pool party \n";

            cout<<"1. Standard pack just for (in Rupees) Rs. 10000.00 \n";
            cout<<"2. Premium pack just for (in Rupees) Rs. 18000.00 \n";
            cout<<"3. Luxury pack just for (in Rupees) Rs. 25000.00 \n";

            cout<<"Press another key to back / or Enter the package number : \n";
            cin>>packchoice ;

            if(packchoice==1)
            {
                hotelCost=10000.00;
                cout<<"You have successfully booked standard Pack at Arvinda Hotels \n";
                cout<<"Goto menu and take your receipt \n";
            }
            else if(packchoice==2)
            {
                hotelCost=18000.00;
                cout<<"You have successfully booked Premium Pack at Arvinda Hotels \n";
                cout<<"Goto menu and take your receipt \n";
            }
            else if(packchoice==3)
            {
                hotelCost=25000.00;
                cout<<"You have successfully booked Luxury Pack at Arvinda Hotels \n";
                cout<<"Goto menu and take your receipt \n";
            }
            else{
                cout<<"Ivalid Input ! Redirecting to Previous menu \n Please wait... \n";
                Sleep(2000);  // 2s wait after execute above line to show professsional looks
                system("cls");
                cin.clear();
                cin.ignore();
                Hotels();
            }

            int gotomenu;
            cout<<"Press 1 to go main menu : \n";
            cin>>gotomenu;
            system("cls");
            // Removed menu() call here to fix linker error

        }
        else {
            cout<<"Redirecting Main menu \n";
            cout<<"Please wait...";
            Sleep(2000);
            system("cls");
            // Removed menu() call here to fix linker error
        }
    }
};

class charges : public customer , public cab , public Booking
{
public:
    void printBill()
    {
        ofstream outf("reciept.txt" , ios::app);  // open in append mode so data can store muliple customer 
        outf << fixed << setprecision(2); // Ensure that the value is floating

        outf<<"------------ ABC Travel Agency ------------- "<<endl;
        outf<<"   ---------------- Recipt ---------------   \n"<<endl;
        

        outf<<"Customer ID : "<< cusID <<endl;
        outf<<"Description \t \t Total"<<endl;
        outf<<"Hotel Cost  \t \t"<<hotelCost<<endl;
        outf<<"Travel (cab) cost \t  "<<final_cost<<endl;

        outf<<"___________________________________________"<<endl;
        outf<<"Total charged \t\t"<<hotelCost+final_cost<<endl;
        outf<<"___________________________________________"<<endl;
        outf<<"--------------- THANK YOU ------------------"<<endl;
        outf<<endl;

        outf.close();
    }

    void showBill()
    {
        ifstream inf("reciept.txt");

        string line2;

        if(!inf){
            cout<<"File Error !"<<endl;
        }

        while(getline(inf,line2))
        {
            cout<<line2<<endl;
        }

        inf.close();
    }

    void menu()
    {
        int mainChoice;
     
        while(true) // <-- main menu loop
        {
            system("cls");

            cout<<"\t\t\t      * ABC Travels *         \n"<<endl;
            cout<<"\t------------------------ Main Menu ----------------------"<<endl;
            cout<<"\t _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _"<<endl;
            cout<<"\t|\tCustomer Management     -> 1\t\t\t|"<<endl;
            cout<<"\t|\tCabs Management         -> 2\t\t\t|"<<endl;
            cout<<"\t|\tHotel Booking Mangement -> 3\t\t\t|"<<endl;
            cout<<"\t|\tCharges and Bill        -> 4\t\t\t|"<<endl;
            cout<<"\t|\tExit                    -> 5\t\t\t|"<<endl;
            cout<<"\t|_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|\n"<<endl;

            cout<<"\n Enter the choice : ";
            cin>>mainChoice;
            system("cls");

            int inchoice, gotoMenu;

            if(mainChoice==1)
            {
                cout<<"-----------Customers-----------"<<endl;
                cout<<"1. Enter New Customer Details :"<<endl;
                cout<<"2. See Old Customer Details   :"<<endl;

                cout<<"Enter the choice : ";
                cin>>inchoice;
                system("cls");

                if(inchoice==1){
                    getdetails();
                }
                else if(inchoice==2){
                    showdetails();
                }
                else{
                    cout<<"Invalid Input ! Redirecting into Previous menu \n";
                    cout<<"Please wait...\n";
                    Sleep(2000);
                    continue;
                }

                cout<<"\nPress 1 to redirect main menu ";
                cin>>gotoMenu;
            }
            else if(mainChoice==2){
                cabDetails();
            }
            else if(mainChoice==3){
                cout<<"\n Book a Hotel using this system"<<endl;
                Hotels();
            }
            else if(mainChoice==4){
                cout<<"--- Get Your Receip from Here ---"<<endl;
                printBill();

                cout<<"Your receipt is already printed in file path \n"<<endl;

                cout<<"Enter 1 to display Your receipt in your screen \n";
                cout<<"Enter any key to back main menu\n";

                cin>>gotoMenu;

                if(gotoMenu==1){
                    system("cls");
                    showBill();
                    cout<<"\n Press 1 to redirect menu :";
                    cin>>gotoMenu;
                }
            }
            else if(mainChoice==5){
                cout<<"----Good Bye----"<<endl;
                break; // exit while loop to quit menu
            }
            else{
                cout<<"Invalid Input ! Redirecting into Previous menu \n";
                cout<<"Please wait...\n";
                Sleep(2000);
                continue; // continue while loop
            }
        }
    }
};

class ManageMenu
{
protected:
    string username;

public:
    ManageMenu()  // use constructor to call admin name at first 
    {
        cout<<"\n\n\n\n\t\t Enter Your Name to continue as an Admin : ";
        getline(cin,username);
        system("cls");
        
    }

    ~ManageMenu(){}
};

int main()
{

   ManageMenu start;
   
   charges c1;
   c1.menu();
   

}
