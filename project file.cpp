/*FASTAG ENROLLMENT SYSTEM PROJECT FINAL CPP CODE
Having 5 modules
 1.Registration of Fastag Account,
 2.Displaying Fastag accounts,
 3.Sorting the Fastag accounts,
 4.Closing the Fastag accounts
 5.Modifying the Fastag accounts */

#include<iostream>

#include<bits/stdc++.h>

#include<string.h>

#include<fstream>//file header file

#include<cstdlib>

using namespace std;

int main_exit;// main exit global variable is using in all modules to get back to main menu

class FastagReg//fastag enrollment class
{
    char reg_no[20],chassis_no[20],name[20],veh_type;//Registration data members
    int amount,number;
    public:
    void getdata()//Getting data from the customer using getdata method
     {
        cout << "\nEnter the user name:" << endl;//taking customer name
        cin >> name;
        cout << "\nEnter the Vehicle Registration Number:" << endl; // standard format AP27GH3456
        cin >> reg_no;
        cout << "\nEnter the Chassis Number:" << endl; // length of chassis number should be 12
        cin >> chassis_no;
        cout << "\nEnter the vehicle type (H for Heavy)/(L for Light)" << endl; //should give input as H 0r L
        cin >> veh_type;
        cout << "\nEnter Amount to paid (10000 for Heavy/6000 for Light)" << endl; // Amount 10000 for H / 6000 for L
        cin >> amount;
        validate_reg_no(reg_no);
        validate_chassis_no(chassis_no); // validating each input
        validate_veh_type(veh_type);
        validate_amount(veh_type,amount);
     }
     void validate_reg_no(char* reg_no) // validating vehicle registration number
     {
         if(reg_no[0]=='A' && reg_no[1]=='P')//checking index 0 & index 1 with A & P respectively
         {
             if(reg_no[4] >= 'A' && reg_no[4] <= 'Z') // checking index 4 of registration number with any of one alphabets
             {
                if(reg_no[5] >= 'A' && reg_no[5] <= 'Z')//checking index 5 of registration number with any of one alohabets

                 {
                 }
             }
         }
         else
         {
             system("cls");//for moving control to new screen
             cout << "Invalid registration number" <<endl;
             menu(); // calling main function
         }
     }

     void validate_chassis_no(char* chassis_no)//validating chassis Number method
     {
         int length;
         length=strlen(chassis_no);
         if(length == 12)
         {
         }
         else
         {
             system("cls");
             cout << "Invalid chassis number" << endl;//if invalid moving to menu for new registration
             menu();
         }
     }

     void validate_veh_type(char veh_type) // validating type of vehicle
     {
         if(veh_type == 'H' || veh_type == 'h' || veh_type == 'L' || veh_type  == 'l')
         {
         }
         else
         {
             system("cls");
             cout << "Invalid vehicle type" << endl;
             menu();
         }
     }

     void validate_amount(char veh_type,int amount) // validating amount
     {
         if (veh_type == 'H' || veh_type == 'h')
         {
             if(amount == 10000)//for Heavy vehicles 10000 amount is checking
             {
             }
         }
         else if(veh_type == 'L' || veh_type == 'l')
         {
             if(amount == 6000)// for light vehicles 6000 amount is checking
             {
             }
         }
         else
         {
             system("cls");
             cout << "Invalid payable amount" << endl;
             menu();//calling main method
         }
     }

    void new_acc()// Adding new account method
    {
        ofstream fout;
        FastagReg obj;//FastagReg class object
        fout.open("C:\\Users\\hp\\Documents\\fastag3.txt",ios::out|ios::app); // opening the file fastag
        cout << "\t\t*****************ADDING NEW FASTAG ACCOUNT********************" << endl;
        obj.getdata(); // calling getdata method
        obj.generatenumber();//calling generate fastag number method
        fout.write( (char*) &obj, sizeof(obj) ); // write the recordes into file
        cout << "Account is created successfully" << endl;
        fout.close(); // closing fastag  file
        add_invalid:
                cout << "\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:" << endl; // choosing option to get back to main menu
                cin >> main_exit;
                system("cls");
                if (main_exit==1)
                    menu();
                else if(main_exit==0)
                        exit(0);
                else
                    {
                        cout << "\nInvalid!!!!" << endl;
                        goto add_invalid;
                    }

        }

    void generatenumber()//fastag card number generation method
    {
       srand((unsigned) time(0));// random number generating for fastag account
       int number=rand();
    }
 void sort_data()
    {
        FastagReg obj1;
        FastagReg obj;
        list <int> li;
        int num;
        ifstream input,fin;
        char choice1;
        fin.open("C:\\Users\\hp\\Documents\\fastag3.txt",ios::in);
        if(fin.fail())
        {
            cout << "could not open the file" << endl;
        }
        fin.read((char*)&obj1,sizeof(obj1));
        while(!fin.eof())
        {
            li.push_back(obj1.number);
            fin.read((char*)&obj1,sizeof(obj1));
        }
        li.sort();
        fin.close();
        input.open("C:\\Users\\hp\\Documents\\fastag3.txt",ios::in);
        list <int> :: iterator itr;
        for(itr = li.begin();itr != li.end();itr++)
        {
            num = (*itr);
            input.read((char*)&obj1,sizeof(obj1));
            while(!input.eof())
            {
                if(obj1.number == num)
                {
                    putdata(obj1);
                }
                input.read((char*)&obj1,sizeof(obj1));
            }
            input.close();
            input.open("C:/Files/fastag3.txt",ios::in);
        }
        input.close();
        cout << "\n\n\tEnter choice y or n to go to main menu or to exit: " ;
        cin >>choice1;
        if(choice1=='y'||choice1=='Y')
        {
                  system("cls");
                  menu();
        }
    }


    void modify() //modify data method  of the customer
    {
    fstream file;
    FastagReg obj;
    char user[15];
    cout<<"\n\n\t\tEnter Name of the customer: ";
    cin>>user;
    file.open("C:\\Users\\hp\\Documents\\fastag3.txt",ios::in|ios::out);// opening the fastag file in and out mode
    file.read((char*)&obj,sizeof(obj)); // reading the data in fastag file
    while (file.eof()==0)
   {
       if (strcmp(obj.name,user)==0)
       {
       cout << "Name: " << obj.name << endl;
       cout << "Vehicle Registration Number: " << obj.reg_no << endl;
       cout << "Vehicle Chassis Number: " << obj.chassis_no << endl;
       cout << "Vehicle Type: " << obj.veh_type << endl;
       cout << "Amount Paid: " << obj.amount <<  endl;
       cout << "Fastag card number: " << obj.number << endl;

       cout<<"\nEnter New Vehicle Registration Number: ";//modifying with new registration,chassis number and Type of vehicle
       cin>>obj.reg_no;
       cout<<"\nEnter New Vehicle Chassis Number: ";
       cin>>obj.chassis_no;
       cout<<"\nEnter New Vehicle type(Heavy or Light)";
       cin>> obj.veh_type;
       cout<<"\nEnter New Vehicle fastag amount";
       cin>>obj.amount;
        validate_reg_no(obj.reg_no);             // validating the new inputs
        validate_chassis_no(obj.chassis_no);
        validate_veh_type(obj.veh_type);
        validate_amount(obj.veh_type,obj.amount);

       file.seekp(file.tellg()-sizeof(obj));
       file.write((char*)&obj,sizeof(obj));
       cout<<"\n\nRecord Updated";
       break;
  }

  file.read((char*)&obj,sizeof(obj));
 }
 file.close();

 add_invalid:
                cout << "\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:" << endl; // choosing option to get back to main menu
                cin >> main_exit;
                system("cls");
                if (main_exit==1)
                    menu();
                else if(main_exit==0)
                        exit(0);
                else
                    {
                        cout << "\nInvalid!!!!" << endl;
                        goto add_invalid;
                    }

}

    void delete_acc() // closing fastag account method
    {
      char cus_name[20];
      int flag=0;
      FastagReg obj;
      cout << "\n\n\t\tEnter the name of the customer to close the fastag account: ";
      cin >> cus_name;
      ifstream myfile;
      ofstream temp;
      myfile.open("C:\\Users\\hp\\Documents\\fastag3.txt",ios::in);
      temp.open("C:\\Users\\hp\\Documents\\temp.txt",ios::out); // creating new temp file
      while (!myfile.eof())
      {
        myfile.read((char*)&obj,sizeof(obj));
        if(myfile)
        {
            if(strcmp(cus_name,obj.name)==0) // comparing name of the customer with datebase if matches removing the record
            {
                flag=1;
            }
            else{
                temp.write((char*)&obj,sizeof(obj));
            }
        }
       }
  myfile.close(); //closing the files
  temp.close();
  remove("C:\\Users\\hp\\Documents\\fastag3.txt"); // deleting the old file
  rename("C:\\Users\\hp\\Documents\\temp.txt", "C:\\Users\\hp\\Documents\\fastag3.txt"); // renaming the temp file to fastag3
  if(flag==1)
    cout << "\nRecord successfully deleted\n" << endl; // if flag==1 data is deleted
  else
    cout << "\nRecord not found"<<endl; // if flag!=1 record is not found
    add_invalid:
                cout << "\n\n\n\t\tEnter 1 to go to the main menu and 0 to exit:" << endl;
                cin >> main_exit;
                system("cls");
                if (main_exit==1)
                    menu();
                else if(main_exit==0)
                        exit(0);
                else
                    {
                        cout << "\nInvalid!!!!" << endl;
                        goto add_invalid;
                    }


}

    void putdata(FastagReg &obj)//putdata method to allign the data to display in console
    {
        cout << "Name: " << obj.name << endl;
        cout << "Vehicle Registration Number: " << obj.reg_no << endl;
        cout << "Vehicle Chassis Number: " << obj.chassis_no << endl;
        cout << "Vehicle Type: " << obj.veh_type << endl;
        cout << "Amount Paid: " << obj.amount <<  endl;
        cout << "Fastag card number: " << obj.number << endl;
        cout << endl << endl << endl;
    }
    void displaydata()//display data method to display all the records of registered customers
    {
                fstream f;
                FastagReg obj;
                char choice1;
                int sno=1;
                f.open("C:\\Users\\hp\\Documents\\fastag3.txt", ios::in);
                cout << "\t\t\t******************FASTAG RECORDS*************************\n" << endl;
                while( (f.read( (char *) &obj, sizeof(obj) )) )
                {
                    cout << "Sno: " << sno++ << endl;
                    putdata( obj );
                }
                f.close();
                cout << "\n\n\tEnter choice y or n to go to main menu or to exit: " << endl;
                cin >>choice1;
                if(choice1=='y'||choice1=='Y')
                {
                  system("cls");
                  menu();
                }
                else
                {
                    exit(0);
                }
            }
    void fordelay(int j)//delay method for loading effect
    {
             int i,k;
            for(i=0;i<j;i++)
                 k=i;
    }
    void menu(void) //menu method
    {
               int choice;
                cout <<"\n\n\n\t\t\t WELCOME TO THE MAIN MENU" << endl;
                cout <<"\n\n\t\t1.Create new account\n\t\t2.Displaying Fastag Account\n\t\t3.sorting customer's list\n\t\t4.Closing account\n\t\t5.Modifying Account\n\t\t6.exit\n\n\n\n\t\t";
                cout << "Enter your choice:";
                cin >> choice;//choosing your choice displaying on the screen
                switch(choice)
                {
                    case 1: system("cls");
                            new_acc();
                             break;
                    case 2: system("cls");
                             displaydata();
                             break;
                    case 3: system("cls") ;
                            sort_data();
                            break;
                    case 4: system("cls");
                            delete_acc();
                            break;
                    case 5: system("cls");
                            modify();
                            break;
                    case 6: system("cls");
                            cout << "\n\n\n\t\t\t*****THANK YOU!! VISIT AGAIN*****" << endl;
                            exit(0);
                            break;
                }
          }
};
int main() //driver function
{
    FastagReg fr;//fastag class object
    char empname[10]="elite",empid[10],pass[10],password[10]="fastag";
    int i=0;
    cout << "\n\t\t\tWELCOME TO FASTAG ENROLLMENT SYSTEM\t" << endl;
    cout <<"\n\n\n\t\t\tEMPLOYEE ID:  ";
    cin >> empid;
    cin.ignore();
    cout <<"\n\n\n\t\t\tPASSWORD:  ";
    cin >> pass;
    cin.ignore();
    if ((strcmp(empid,empname)&&strcmp(pass,password))==0)/*if matches with the correct id and password then allowing employee
                                                               to open the system ready to enroll for customers*/
      {
            cout << "\n\nPassword Match!\nLOADING" << endl;
            for(i=0;i<=6;i++)
            {
                fr.fordelay(100000000);
                printf(".");
            }
                    system("cls");
                 fr.menu();
        }
    else
        {
            cout << "\n\nWrong username or password!!" << endl;
            login_try:
            cout << "\nEnter 1 to try again and 0 to exit:" << endl;/* if password/user id not matches then giving option 1 to try
            cin >> main_exit;                                           again 0 to exit*/
            system("cls");
            if (main_exit==1)
                    {
                        main();
                    }
            else if (main_exit==0)
                    {
                       exit(0);
                    }
            else
                    {
                        cout << "Invalid choice!!!";
                        fr.fordelay(1000000000);//calling delay function for loading effect
                        goto login_try; //back to try login again
                    }
        }
        return 0;
}
