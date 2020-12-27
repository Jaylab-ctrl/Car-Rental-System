#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<fstream>
#include<windows.h>
#include<iomanip>
#include<conio.h>

#pragma warning(disable:4305)
#pragma warning(disable:4101)
#pragma warning(disable:4566)
#pragma warning(disable:4018)
#pragma warning(disable:4326)
using namespace std;


int selection = 0;

void first_display();

int get_size(const char* filename)
{
    int count = 0;
    string line;

    ifstream file(filename);
    while (getline(file, line))
        count++;

    return count;
}

class Car
{
    string vehicleID, carName, type, status = "notBooked", date = "date", Customer_ID, Hours; 
    float baseFare, Amount;
public:
    void add_Car();
    void display_Cars();
    void book_car(string custID);
    void view_reservation();
    void modify_details();
    string getVehicleID()
    {
        return vehicleID;
    }
    string getCarName()
    {
        return carName;
    }
    string getCarType()
    {
        return type;
    }
    string getStatus()
    {
        return status;
    }
    float getFare()
    {
        return baseFare;
    }
    string getDate()
    {
        return date;
    }
    string getCustomer_ID()
    {
        return Customer_ID;
    }
    string getHours()
    {
        return Hours;
    }
    float getAmount()
    {
        return Amount;
            
    }
    void setcarName(string carName)
    {
        this->carName = carName;
    }
    void setvehicleID(string vehicleID)
    {
        this->vehicleID = vehicleID;
    }
    void setcarType(string carType)
    {
        this->type = carType;
    }
    void setstatus(string status)
    {
        this->status = status;
    }
    void setDate(string date)
    {
        this->date = date;
    }
    void setCustomer_ID(string Customer_ID)
    {
        this->Customer_ID = Customer_ID;
    }
    void setHours(string Hours)
    {
        this->Hours = Hours;
    }
    void setbaseFare(float baseFare)
    {
        this->baseFare = baseFare;
    }
    void setAmount(float Amount)
    {
        this->Amount = Amount;
    }

};

class Billing
{
private:
    int hours;
    float amt = 0, tax = 0.05, bf, amount; //amt = amt + bf * hours + ( tax * bf)
    string carr_Name, vID, car_Type, car_Status, dat, customer_ID;
public:
    Billing(string car_name, string VID, string Ttype, string Status, float baseF, string datee, string CustID)
    {
        carr_Name = car_name;
        vID = VID;
        car_Type = Ttype;
        car_Status = Status;
        bf = baseF;
        dat = datee;
        customer_ID = CustID;
    }

    float calculate_bill()
    {
        cout << "\n\n\tHow many hours do you want the car for: ";
        cin >> hours;
        amt = bf * hours + (tax * bf);
        return amt;
    }

    void generate_bill()
    {
        fstream finout,fin;
        finout.open("bookings.txt", ios::app);
        amount = calculate_bill();
        system("CLS");
        if (car_Status.compare("booked") == 0)
        {
            cout << "\n\n\n";
            cout.width(94);
            cout.fill('*');
            cout << " ~ B I L L ~ " << setw(81) << setfill('*');
            cout << "\n\n\n";
            cout << "\n\t\t\t\t\t\t\t\t\t\tBOOKED BY:" << customer_ID;
            cout << "\n\n\t\t\t\t\t\t\t\t\t\tCAR NAME:" << carr_Name;
            cout << "\n\t\t\t\t\t\t\t\t\t\tVEHICLE ID: " << vID;
            cout << "\n\t\t\t\t\t\t\t\t\t\tCAR TYPE: " << car_Type;
            cout << "\n\t\t\t\t\t\t\t\t\t\tCAR STATUS: " << car_Status;
            cout << "\n\t\t\t\t\t\t\t\t\t\tBASE FARE:" << bf;
            cout << "\n\t\t\t\t\t\t\t\t\t\tDURATION: " << hours;
            cout << "\n\t\t\t\t\t\t\t\t\t\tDATE: " << dat;
            cout << "\n\n\n\t\t\t\t\t\t\t\t\t\tFINAL AMOUNT TO BE PAID: " << amount;
            cout << "\n\n\n\n\n\n\t\t\t\t\t\t\t\t~ T H A N K   Y O U   F O R   C H O O S I N G   U S ~ " << endl;

            finout << customer_ID << "\n" << carr_Name << "\n" << vID << "\n" << car_Type << "\n" << car_Status << "\n" << bf << "\n" << hours<< "\n" <<dat << "\n" << amount << endl << endl;
        }
        finout.close();    
        cust_append();
    }

    void cust_append()
    {
        fstream in;
        in.open(customer_ID.c_str(), fstream::app);
        in << carr_Name << "\n" << vID << "\n" << car_Type << "\n" << car_Status << "\n" << bf << "\n" << hours << "\n" << dat << "\n" << amount << endl << endl;
        in.close();                
    }

};

void Car::add_Car()
{    
    char ans = 'y';
    fstream finout;
    finout.open("cars.txt", ios::app);
    do
    {
        system("cls");
        cout << "\n\n\n";
        cout.width(103);
        cout.fill('*');
        cout << " ~ W E L C O M E   A D M I N ~ " << setw(72) << setfill('*');
        cout << "\n\n\n";
        cout.width(97);
        cout.fill('*');
        cout << " ~ A D D  C A R S ~ " << setw(80) << setfill('*');
        cout << "\n\n\n\n\t" <<"Enter the car details:";
        cout << "\n\n\n\t\t\t\tCAR NAME: ";
        cin >> carName;
        cout << "\n\t\t\t\tVEHICLE ID: ";
        cin >> vehicleID; 
        cout << "\n\t\t\t\tBASE FARE: ";
        cin >> baseFare;
        cout << "\n\t\t\t\tCAR TYPE: ";
        cin >> type;

        finout << carName << "\n" << vehicleID << "\n" << baseFare << "\n" << type << "\n" << status << "\n" << date << "\n\n";
        cout << "\n\n\t Do you want to enter more cars? (y/n)\n\t Your choice is: ";
        cin >> ans;
    } while (ans == 'y');
    finout.close();
}

void Car::display_Cars()     // for user and admin
{
    system("cls");
    cout << "\n\n\n";
    cout.width(102);
    cout.fill('*');
    cout << " ~ D I S P L A Y  C A R S ~ " << setw(72) << setfill('*');
    cout << "\n\n";
    fstream fin;
    int CarNo;
    fin.open("cars.txt", ios::in);
    Car* check;
    int size = get_size("cars.txt");
    check = new Car[size];

    for (int i = 0; i < size; i++)
    {
        fin >> check[i].carName;
        fin >> check[i].vehicleID;
        fin >> check[i].baseFare;
        fin >> check[i].type;
        fin >> check[i].status;
        fin >> check[i].date;
    }

    cout << "\n\n\tThese are the available cars:"<<endl<<endl;
    for (int i = 0; i < size / 7; i++)
    {
        cout << "\n\t\t\t\t" << i + 1 << ".";
        cout << "  CAR NAME: " << check[i].carName << endl;
        cout << "\t\t\t\t    CAR ID: " << check[i].vehicleID << endl;
        cout << "\t\t\t\t    CAR FARE: " << check[i].baseFare << endl;
        cout << "\t\t\t\t    CAR TYPE: " << check[i].type << endl;
        cout << "\t\t\t\t    BOOKING STATUS: " << check[i].status << endl;
        cout << "\t\t\t\t    BOOKING DATE: " << check[i].date << endl << endl;
    }
    fin.close();
}

void Car::book_car(string CustID)
{
    fstream fin;
    int CarNo;
    fin.open("cars.txt", ios::in);
    Car* check;
    int size = get_size("cars.txt");
    check = new Car[size];

    for (int i = 0; i < size; i++)
    {
        fin >> check[i].carName;
        fin >> check[i].vehicleID;
        fin >> check[i].baseFare;
        fin >> check[i].type;
        fin >> check[i].status;
        fin >> check[i].date;
    }
    fin.close();
    cout << "\n\n";
    cout.width(98);
    cout.fill('*');
    cout << " ~ B O O K   A   C A R ~ " << setw(128) << setfill('*');

    label:
    cout << " \n\n\tDo you want to book a car? (y/n)\n\tYour choice is: ";
    char ans;
    cin >> ans;
    if (ans == 'y')
    {
        cout << "\n\n\t\t\t\tEnter the car number you want to book: ";
        cin >> CarNo;
        if (check[CarNo - 1].status == "notBooked")
        {
            check[CarNo - 1].status = "booked";
            this->status = "booked";
            cout << "\n\t\t\t\tEnter the date to book the car :";
            cin >> check[CarNo - 1].date;
            this->date = check[CarNo - 1].date;

            cout << "\n\n\tThe details of your booked car are: ";
            cout << "\n\n\n\t\t\t\tCAR NAME: " << check[CarNo - 1].carName;
            cout << "\n\t\t\t\tCAR ID: " << check[CarNo - 1].vehicleID;
            cout << "\n\t\t\t\tCAR FARE: " << check[CarNo - 1].baseFare;
            cout << "\n\t\t\t\tCAR TYPE: " << check[CarNo - 1].type;
            cout << "\n\t\t\t\tBOOKING STATUS: " << check[CarNo - 1].status;
            cout << "\n\t\t\t\tDATE: " << check[CarNo - 1].date<<endl;
        }
        else
        {
            cout << "\n\n\tSorry, that car is already booked";
            goto label;
        }
    }
    else
        exit(0);

    fin.close();

    fstream fout;
    fout.open("cars.txt", ios::out);
    for (int i = 0; i < size / 7; i++)
    {
        fout << check[i].carName << endl;
        fout << check[i].vehicleID << endl;
        fout << check[i].baseFare << endl;
        fout << check[i].type << endl;
        fout << check[i].status << endl;
        fout << check[i].date << endl;
        fout << "\n";
    }
    fout.close();

    Billing bill(check[CarNo - 1].carName, check[CarNo - 1].vehicleID, check[CarNo - 1].type, check[CarNo - 1].status, check[CarNo - 1].baseFare, check[CarNo - 1].date, CustID);
    bill.generate_bill();
}

void Car::view_reservation()
{
    system("cls");
    cout << "\n\n\n";
    cout.width(103);
    cout.fill('*');
    cout << " ~ W E L C O M E   A D M I N ~ " << setw(72) << setfill('*');
    cout << "\n\n\n";
    cout.width(106);
    cout.fill('*');
    cout << " ~ V I E W  R E S E R V A T I O N ~ " << setw(68) << setfill('*');
    cout << "\n\n";
    fstream fin;
    fin.open("bookings.txt", ios::in);
    Car* check;
    int size = get_size("bookings.txt");
    check = new Car[size];

    for (int i = 0; i < size; i++)
    {
        fin >> check[i].Customer_ID;
        fin >> check[i].carName;
        fin >> check[i].vehicleID;
        fin >> check[i].type;
        fin >> check[i].status;
        fin >> check[i].baseFare;
        fin >> check[i].Hours;
        fin >> check[i].date;
        fin >> check[i].Amount;
    }    

    if (fin.tellg() == 0)
    {
        cout << "\n\n\tNo cars have been booked!";
    }
    else
    {
        cout << "\n\tAll the cars that have been booked are :" << "\n\n";
        for (int i = 0; i < size / 9; i++)
        {
            if (check[i].status == "booked")
            {
                cout << "\n\t\t\t\t" << i + 1 << ".";
                cout << "  BOOKED BY: " << check[i].Customer_ID << endl;
                cout << "\t\t\t\t    CAR NAME: " << check[i].carName << endl;
                cout << "\t\t\t\t    CAR ID: " << check[i].vehicleID << endl;
                cout << "\t\t\t\t    CAR FARE: " << check[i].baseFare << endl;
                cout << "\t\t\t\t    CAR TYPE: " << check[i].type << endl;
                cout << "\t\t\t\t    BOOKING STATUS: " << check[i].status << endl;
                cout << "\t\t\t\t    DURATION (hours): " << check[i].Hours << endl;
                cout << "\t\t\t\t    BILL AMOUNT: " << check[i].Amount << endl;
                cout << "\t\t\t\t    BOOKING DATE: " << check[i].date << endl << endl;
            }
        }
    }
    fin.close();
}

void Car::modify_details()
{
    system("cls");
    cout << "\n\n\n";
    cout.width(103);
    cout.fill('*');
    cout << " ~ W E L C O M E   A D M I N ~ " << setw(72) << setfill('*');
    cout << "\n\n\n";
    cout.width(104);
    cout.fill('*');
    cout << " ~ M O D I F Y  D E T A I L S ~ " << setw(70) << setfill('*');
    cout << "\n\n";
    fstream fin;
    int carNo;
    fin.open("cars.txt", ios::in);
    Car* check;
    int size = get_size("cars.txt");
    check = new Car[size];

    for (int i = 0; i < size; i++)
    {
        fin >> check[i].carName;
        fin >> check[i].vehicleID;
        fin >> check[i].baseFare;
        fin >> check[i].type;
        fin >> check[i].status;
        fin >> check[i].date;

    }
    cout << "\n\t Present details of Cars: \n\n";
    for (int i = 0; i < size / 7; i++)
    {
        cout << "\n\t\t\t" << i + 1 << " ";
        cout << "  CAR NAME: " << check[i].carName << endl;
        cout << "\t\t\t    CAR ID: " << check[i].vehicleID << endl;
        cout << "\t\t\t    CAR FARE: " << check[i].baseFare << endl;
        cout << "\t\t\t    CAR TYPE: " << check[i].type << endl;
        cout << "\t\t\t    BOOKING STATUS: " << check[i].status << endl;
        cout << "\t\t\t    BOOKING DATE: " << check[i].date << endl << endl;
    }
    cout << "\n\n\t Enter the car no. you want to modify: ";
    cin >> carNo;

    cout << "\n\n\t Enter new details: \n";
    cout << "\n\n\t\t\t CAR NAME: ";
    cin >> check[carNo - 1].carName;
    cout << "\n\t\t\t VEHICLE ID: ";
    cin >> check[carNo - 1].vehicleID; //add check numerical only
    cout << "\n\t\t\t BASE FARE: ";
    cin >> check[carNo - 1].baseFare;
    cout << "\n\t\t\t CAR TYPE: ";
    cin >> check[carNo - 1].type;
    fin.close();
    cout << "\n\n\tYour modifications has been saved!" << "\n";


    fstream fout;
    fout.open("cars.txt", ios::out);
    for (int i = 0; i < size / 7; i++)
    {
        fout << check[i].carName << endl;
        fout << check[i].vehicleID << endl;
        fout << check[i].baseFare << endl;
        fout << check[i].type << endl;
        fout << check[i].status << endl;
        fout << check[i].date << endl;
        fout << "\n";
    }
    fout.close();
}

class user
{
protected:
    string ID[10], pass[10];
public:
    virtual void login() = 0;
};

class admin : public user
{
public:
    void login()
    {
        system("CLS");
        string temp_ID, temp_pass;
        cout << "\n\n\n";
        cout.width(100);
        cout.fill('*');
        cout << " ~ L O G I N  P A G E ~ " << setw(100) << setfill('*');
        cout << "\n\n\n\n\t\t\t\t\t\t\t\t\tEnter Username: ";
        cin >> temp_ID;

        char password[50];
        char c;
        int i = 0;

        cout << "\n\t\t\t\t\t\t\t\t\tEnter password: ";
        while (c = _getch())
        {
            if (c == '\r')
            {
                break;
            }
            else if (c == '\b')
            {
                cout << "\b \b";
                i--;
            }
            else
            {
                password[i] = c;
                i++;
                cout << "*";
            }
        }
        password[i] = '\0';
        temp_pass = password;
        int size = get_size("Login_Admin.txt");

        ifstream in("Login_Admin.txt");
        for (int i = 0; i < size/3; i++)
        {
            in >> ID[i];
            in >> pass[i];
        }
        
        bool isLogin = false;
        int n = 0;

        for (int i = 0; i < size/3; i++)
        {
            if (temp_ID == ID[i])
            {
                n = i;
                if (temp_pass == pass[i])
                {
                    cout << "\n\n\n\t\t\t\t\t\t\tSuccessful Login!\n\t\t\t\t\t\t\tPress any key to continue";
                    _getch();
                    adminDisplay();
                    isLogin = true;                    
                }
                break;
            }
            else
            {
                isLogin = false;
            }
        }
        if (!isLogin)
        {
            if (temp_ID == ID[n])
            {
                cout << "\n\n\n\tOOPS! The entered password was unmachted!" << "\n\tpress any key to continue";
                _getch();

                back:
                system("CLS");

                cout << "\n\n\t1. Press 1 to re-enter the details" << endl << "\n\t2. Press 2 exit" << endl << "\n\n\tYour selection is : ";
                cin >> selection;

                switch (selection)
                {
                case 1:
                    login();
                    break;
                case 2:
                    exit(0);
                    break;
                default:
                    cout << "\n\n\tEnter valid selection!";
                    goto back;
                }
            }
            else
            {
                cout << "\n\n\tWrong ID Password\n\tPress any key to continue";
                _getch();                
            }
        }
    }

    void adminDisplay()
    {
        system("cls");
        Car objCar;
        int selection;
        label:
        system("cls");
        cout << "\n\n\n";
        cout.width(100);
        cout.fill('*');
        cout << " ~ W E L C O M E   A D M I N ~ " << setw(250) << setfill('*');
        cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t1. ADD CARS \n\n\t\t\t\t\t\t\t\t\t\t2. VIEW RESERVATIONS \n\n\t\t\t\t\t\t\t\t\t\t3. DISPLAY CARS \n\n\t\t\t\t\t\t\t\t\t\t4. UPDATE CARS' DETAILS\n\n\t\t\t\t\t\t\t\t\t\t5. LOGOUT\n\n\n\t\t\t\t\t\t\t        Your selection is: ";
        cin >> selection;

        switch (selection)
        {
        case 1:
            objCar.add_Car();
            break;
        case 2:
            objCar.view_reservation();
            break;
        case 3:
            objCar.display_Cars();
            break;
        case 4:
            objCar.modify_details();
            break;
        case 5:
            exit(0);
        default:
            cout << "\n\n\tEnter valid selection!";
            goto label;
        }
        cout << "\n\n\t1. GO BACK TO MAIN MENU\n\t2. LOGOUT\n\n\tYour selection is: ";
        int ans;
        cin >> ans;
        if (ans == 1)
        {
            goto label;
        }
    }
};

class Register
{
    string fname, lname, emailID, gender, pass, re_pass, phone;
    int day=0, month=0, year=0;  
public:
    void terms_condition()
    {
        system("CLS");
        cout << "\n\n\n";
        cout.width(108);
        cout.fill('*');
        cout << " ~ R E G I S T E R A T I O N  P A G E ~ " << setw(66) << setfill('*');
        cout << "\n\n";
        cout.width(110);
        cout.fill('*');
        cout << " ~ T E R M S  A N D  C O N D I T I O N S ~ " << setw(146) << setfill('*');
        cout << "\n\n\n\n\t\t\t\t\t\t\tView the following terms and conditions before registering yourself here:";
        cout << "\n\n\n\n\t\t1. Your age should be 18 or above.\n\t\t2. You must have a driving license.\n\t\t3. All information provided by you should be true";
        cout << "\n\t\t5. You agree to pay for any damages caused to the car during your rental period.\n\t\t6. License will be checked at the time of car pick up";
        cout << "\n\t\t7. Your booking will be considered void if the provided details while registration does not match at the time of pick up.";
        cout << "\n\t\t8. In such a case you will also be charged ₹1000.\n\t\t9. Advance payment will be requested before you pick up the car.";
        cout << "\n\t\t10. Online payment is not accepted.\n\t\t11. Company is not responsible for any valuables that you leave in the car after dropping the car off.";
        Again_1:
        cout << "\n\n\n\n\n\t\t\t\t\t\t\tDo you agree to all the above terms and condition?\n\n\n\t\t1. YES\n\t\t2. NO\n\n\t\tYour selection is: ";
        cin >> selection;

        switch (selection)
        {
        case 1:
            get_name();
            break;
        case 2:
            exit(0);
            break;
        default:
            cout << "\n\tEnter valid option!";
            goto Again_1;
        }
    }
    
    void get_name()
    {
        system("CLS");
        cout << "\n\n\n";
        cout.width(108);
        cout.fill('*');
        cout << " ~ R E G I S T E R A T I O N  P A G E ~ " << setw(105) << setfill('*');
        cout << "\n\n\n\n\tPlease enter the following details: " << endl;
        cout << "\n\n\n\t\t\t\t\tFIRST NAME: ";
        cin >> fname;
        validate_fname(fname);
    }
    void validate_fname(string fname)
    {
        string str = fname;
        int count = 0;
        bool check_fname = false;

        for (int i = 0; i < str.length(); i++)
        {
            if (isalpha(str[i]))
            {
                count++;
                check_fname = true;
            }
            else
            {
                check_fname = false;
            }            
        }
        if (count == str.length() && check_fname == true)
        {
            validate_lname();
        }
        else
        {
            cout << "\n\tPlease enter valid Name!" << endl;
            s_again:
            cout << "\n\n\t1. Re-Enter.\n\t2. Exit.\n\n\tYour selection is: ";
            cin >> selection;

            switch (selection)
            {
            case 1:
                get_name();
                break;
            case 2:
                exit(0);
                break;
            default:
                cout << "\n\tEnter valid option!";
                goto s_again;
            }
        }
    }

    void validate_lname()
    {
        cout << "\n\t\t\t\t\tLAST NAME: ";
        cin >> lname;

        string str = lname;
        int count = 0;
        bool check_lname = false;

        for (int i = 0; i < str.length(); i++)
        {
            if (isalpha(str[i]))
            {
                count++;
                check_lname = true;
            }
            else
            {
                check_lname = false;
            }
        }
        if (count == str.length() && check_lname == true)
        {
            validate_gender();
        }
        else
        {
            cout << "\n\tPlease enter valid Name!" << endl;
            S_again:
            cout << "\n\t1. Press 1 to re-enter.\n\t2. Press 2 to exit.\n\n\tYour selection is: ";
            cin >> selection;

            switch (selection)
            {
            case 1:
                cout << "\n\t\t\t\t\tFIRST NAME: " << fname<<endl;
                validate_lname();
                break;
            case 2:
                exit(0);
                break;
            default:
                cout << "\n\tEnter valid option!";
                goto S_again;
            }
        }
    }

    void validate_gender()
    {
        start_again:
        cout << "\n\t\t\t\t\tGENDER: "<< "1. Male.\n\t\t\t\t\t        2. Female.\n\t\t\t\t\t        3. Other."<<endl<<"\n\t\t\t\t\tYour selection is: ";
        cin >> selection;

        switch (selection)
        {
        case 1:
            gender = "Male";
            break;
        case 2:
            gender = "Female";
            break;
        case 3:
            gender = "Other";
            break;
        default:
            cout << "\n\n\tEnter valid selection!";
            goto start_again;
        }
       validate_email();
    }

    void validate_email()
    {
        cout << "\n\t\t\t\t\tEmail-ID: ";
        cin >> emailID;
        
        bool correctID = false;
        string str = emailID;
        string c = "@";
        string d = ".";
        
        string *id;
        int size = get_size("Login_Customer.txt");
        id = new string[size];

        ifstream in("Login_Customer.txt");
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (i % 3 == 0)
            {
                in >> id[count];
                count++;
            }
        }

        for (int i = 0; i < size; i++)
        {
            if (emailID == id[i])
            {
                again1:
                cout << "\n\n\n\t\t\t\tYou are already registered!"<< endl;
                cout << "\n\n\t\t1. Login. \n\t\t2. Exit. \n\n\tYour selection is: ";
                cin >> selection;

                switch (selection)
                {
                case 1:                    
                    first_display();
                    break;
                case 2:
                    exit(0);
                    break;
                default:
                    cout << "\n\n\tEnter valid option!";
                    goto again1;
                }
            }
        }

        if (str.find(c) <= str.length() && str.find(d) <= str.length())
        {
            correctID = true;
            validate_DOB();
        }
        else
        {
            correctID = false;
            
            cout << "\n\n\tPlease enter valid Email ID!" << endl;
            again:
            cout << "\n\n\t1. Re-Enter.\n\t2. Exit.\n\n\tYour selection is: " << endl;
            cin >> selection;

            switch (selection)
            {
            case 1:
                system("CLS");
                cout << "\n\n\tRe-enter Email-ID: ";
                cin >> emailID;
                validate_email();
                break;
            case 2:
                exit(0);
                break;
            default:
                cout << "\n\n\tEnter valid option!";
                goto again;
            }
        }
    }

    void validate_DOB()
    {
        cout << "\n\t\t\t\t\tDOB: " << "Enter Day: ";
        cin >> day;
        cout << "\n\t\t\t\t\t     Enter Month: ";
        cin >> month;
        cout << "\n\t\t\t\t\t     Enter Year: ";
        cin >> year;

        if (month > 12 && month <= 0)
        {
            system("CLS");
            cout << "\n\n\tEnter valid DOB!" << endl;
            again:
            cout << "\n\n\t1. Press 1 to re-enter DOB. \n\t2. Press 2 to exit. \n\n\tYour selection is: ";
            cin >> selection;

            switch (selection)
            {
            case 1:
                validate_DOB();
                break;
            case 2:
                exit(0);
                break;
            default:
                cout << "\n\n\tEnter valid option!";
                goto again;
            }
        }
        else
        {
            bool check_year = false;
            if (year <= 2001 && year > 999)
            {
                check_year = true;
            }
            else
            {
                check_year = false;
                cout << "\n\n\tEnter valid DOB!" << endl;
                againn:
                cout << "\n\n\t1. Re-Enter DOB. \n\t2. Exit. \n\n\tYour selection is: ";
                cin >> selection;

                switch (selection)
                {
                case 1:
                    validate_DOB();
                    break;
                case 2:
                    exit(0);
                    break;
                default:
                    cout << "\n\n\tEnter valid option!";
                    goto againn;
                }
            }
        }
       
        bool check_day = false;
        if (month == 2)
        {
            if (year % 4 == 0)
            {
                if (year % 100 == 0)
                {
                    if (year % 400 == 0)
                    {
                        if (day <= 29 && day > 0)
                        {
                            check_day = true;
                        }
                        else
                        {
                            check_day = false;
                            cout << "\n\n\tEnter valid DOB!" << endl;
                            too:
                            cout << "\n\n\t1. Press 1 to re-enter DOB. \n\t2. Press 2 to exit. \n\n\tYour selection is: ";
                            cin >> selection;

                            switch (selection)
                            {
                            case 1:
                                validate_DOB();
                                break;
                            case 2:
                                exit(0);
                                break;
                            default:
                                cout << "\n\n\tEnter valid option!";
                                goto too;
                            }
                        }
                    }
                    else
                    {
                        if (day < 29 && day >0)
                        {
                            check_day = true;
                        }
                        else
                        {
                            cout << "\n\n\tEnter valid DOB!" << endl;
                        Too:
                            cout << "\n\n\t1. Press 1 to re-enter DOB. \n\t2. Press 2 to exit. \n\n\tYour selection is: ";
                            cin >> selection;

                            switch (selection)
                            {
                            case 1:
                                validate_DOB();
                                break;
                            case 2:
                                exit(0);
                                break;
                            default:
                                cout << "\n\n\tEnter valid option!";
                                goto Too;
                            }
                        }
                    }
                }
                else
                {
                    if (day <= 29 && day > 0)
                    {
                        check_day = true;
                    }
                    else
                    {
                        check_day = false;
                        cout << "\n\n\tEnter valid DOB!" << endl;
                    tooo:
                        cout << "\n\n\t1. Press 1 to re-enter DOB. \n\t2. Press 2 to exit. \n\n\tYour selection is: ";
                        cin >> selection;

                        switch (selection)
                        {
                        case 1:
                            validate_DOB();
                            break;
                        case 2:
                            exit(0);
                            break;
                        default:
                            cout << "\n\n\tEnter valid option!";
                            goto tooo;
                        }
                    }
                }
            }
            else
            {
                if (day < 29 && day >0)
                {
                    check_day = true;
                }
                else
                {
                    cout << "\n\n\tEnter valid DOB!" << endl;
                Tooo:
                    cout << "\n\n\t1. Press 1 to re-enter DOB. \n\t2. Press 2 to exit. \n\tYour selection is: ";
                    cin >> selection;

                    switch (selection)
                    {
                    case 1:
                        validate_DOB();
                        break;
                    case 2:
                        exit(0);
                        break;
                    default:
                        cout << "\n\n\tEnter valid option!";
                        goto Tooo;
                    }
                }
            }
        }
        else if ((month == 1 || 3 || 5 || 7 || 8 || 10 || 12) && (month != 0))
        {
            if (day >0 && day <32 )
            {
                check_day = true;
            }
            else
            {
                check_day = false;
                cout << "\n\n\tEnter valid DOB!" << endl;
                Again:
                cout << "\n\n\t1. Press 1 to re-enter DOB. \n\t2. Press 2 to exit. \n\tYour selection is: ";
                cin >> selection;

                switch (selection)
                {
                case 1:
                    validate_DOB();
                    break;
                case 2:
                    exit(0);
                    break;
                default:
                    cout << "\n\n\tEnter valid option!";
                    goto Again;
                }
            }
        }
        else
        {
            if ((month == 4 || 6 || 9 || 11) && (month != 0))
            {
                if (day > 0 && day < 31)
                {
                    check_day = true;
                }
                else
                {
                    check_day = false;
                    cout << "\n\n\tEnter valid DOB!" << endl;
                to:
                    cout << "\n\n\t1. Re-Enter DOB. \n\t2. Exit. \n\n\tYour selection is: ";
                    cin >> selection;

                    switch (selection)
                    {
                    case 1:
                        validate_DOB();
                        break;
                    case 2:
                        exit(0);
                        break;
                    default:
                        cout << "\n\n\tEnter valid option!";
                        goto to;
                    }
                }
            }
        }
        validate_phone();
    }
    void validate_phone()
    {
        cout << "\n\t\t\t\t\tPHONE NUMBER: ";
        cin >> phone;

        string str = phone;
        int count = 0;
        bool check_phone = false;

        string* phone_number_2;
        int size = get_size("Customer_details.txt");
        phone_number_2 = new string[size];

        ifstream in("Customer_details.txt");
        int count_1 = 0;
        int flag = 0;
        for (int i = 0; i < size; i++)
        {
            if (i % 4 == 1)
            {
                in >> phone_number_2[count_1];
                count_1++;
            }
        }

        for (int i = 0; i < size; i++)
        {
            if (phone == phone_number_2[i])
            {
                flag = 1;
                cout<<"\n\n\tYour are already registered!";
                cout << "\n\n\t1. LOGIN \n\t2. RE-ENETER \n3. EXIT";
                cin >> selection;

                switch (selection)
                {
                case 1:
                    first_display();
                    break;
                case 2:
                    validate_phone();
                    break;
                case 3:
                    exit(0);
                    break;
                default:
                    cout << "\n\n\tEnter valid option!";
                    goto top;
                }
                break;
            }
            else
            {
                flag = 0;
            }
        }

        if (flag == 0)
        {
            for (int i = 0; i < str.length(); i++)
            {
                if (isdigit(str[i]))
                {
                    count++;
                    check_phone = true;
                }
                else
                {
                    check_phone = false;
                }
            }
            if (count == str.length() && check_phone == true)
            {
                if (str.length() < 11 && str.length() > 0 && str[0] != '0')
                {
                    check_phone = true;
                }
                else
                {
                    check_phone = false;
                    cout << "\n\n\tEnter valid Phone Number!" << endl;
                    top:
                    cout << "\n\n\t1. RE-ENTER \n\t2. EXIT\n\n\tYour selection is: ";
                    cin >> selection;

                    switch (selection)
                    {
                    case 1:
                        validate_phone();
                        break;
                    case 2:
                        exit(0);
                        break;
                    default:
                        cout << "\n\n\tEnter valid option!";
                        goto top;
                    }
                }
            }
            else
            {
                check_phone = false;
                cout << "\n\n\tEnter valid Phone Number!" << endl;
                Toop:
                cout << "\n\n\t1. RE-ENTER\n\t2. EXIT\n\n\tYour selection is: ";
                cin >> selection;

                switch (selection)
                {
                case 1:
                    validate_phone();
                    break;
                case 2:
                    exit(0);
                    break;
                default:
                    cout << "\n\n\tEnter valid option!";
                    goto Toop;
                }
            }
        }        
        validate_password();
    }   

    void validate_password()
    {
        cout << "\n\t\t\t\t\tNew Password: ";
        cin >> pass;
        cout << "\n\t\t\t\t\tRe-enter Password: ";
        cin >> re_pass;

        bool check_pass = false;
        
        if (pass == re_pass)
        {
            check_pass = true;
        }
        else
        {
            cout << "\n\n\tThe passwords don't match. \n\tPlease retenter the passwords." << endl;
            topp:
            cout << "\n\n\t1. RE-ENTER\n\t2. EXIT" << endl << "\n\n\tYour selection is: ";
            cin >> selection;

            switch (selection)
            {
            case 1:
                validate_password();
                break;
            case 2:
                exit(0);
                break;
            default:
                cout << "\n\n\tEnter valid option!";
                goto topp;
            }
        }
        confirm_details();
    }

    void confirm_details()
    {
        system("CLS");
        cout << "\n\n";
        cout.width(108);
        cout.fill('*');
        cout << " ~ R E G I S T E R A T I O N  P A G E ~ " << setw(100) << setfill('*');
        cout << "\n\n\n\t\t\t\t\t\t\tYour entered details are: ";
        cout << "\n\n\n\t\t\t\t\t\t\t\t\t\tFIRST NAME:" << fname << "\n\n\t\t\t\t\t\t\t\t\t\tLAST NAME: " << lname << "\n\n\t\t\t\t\t\t\t\t\t\tGENDER: " << gender << endl;
        cout<<"\n\t\t\t\t\t\t\t\t\t\tEMAIL-ID: "<< emailID <<"\n\n\t\t\t\t\t\t\t\t\t\tDOB: " <<day<< "/" <<month<< "/" <<year<<"\n\n\t\t\t\t\t\t\t\t\t\tPHONE NUMBER: "<< phone;
        Start_again:
        cout << "\n\n\n\t\t\t\t\t\t\t1. Confirm Details\n\t\t\t\t\t\t\t2. Update Details\n\t\t\t\t\t\t\t3. Exit\n\n\t\t\t\t\t\t\tYour selection is: ";
        cin >> selection;

        switch (selection)
        {
        case 1:             
            append();           
            break;
        case 2:
            get_name();
            break;
        case 3:
            exit(0);
        default:
            cout << "\n\n\tEnter valid selection!";
            goto Start_again;
        }  
    }

    void append()
    {
        fstream fp;
        ofstream fpp;
        fp.open("Customer_details.txt", ios::app);
        fp << fname << "\n" << lname << "\n" << gender << "\n" << emailID << "\n" << day << "\\" << month << "\\" << year << "\n" << phone <<"\n"<< re_pass << "\n\n";
        fp.close();
        fp.open("Login_Customer.txt", ios::app);
        fp << phone << "\n" << re_pass << "\n\n";
        fp.close();
        fpp.open(phone.c_str());
        fpp.close();

        first_display();
    }
};

class customer : public user
{
    string temp_ID, temp_pass;
public:
    void login()
    {
        system("CLS");
        cout << "\n\n\n";
        cout.width(100);
        cout.fill('*');
        cout << " ~ L O G I N  P A G E ~ " << setw(100) << setfill('*');
        cout << "\n\n\n\n\t\t\t\t\t\t\t\tEnter Username: ";
        cin >> temp_ID;

        char password[50];
        char c;
        int i = 0;

        cout << "\n\t\t\t\t\t\t\t\tEnter password: ";

        while (c = _getch())
        {
            if (c == '\r')
            {
                break;
            }
            else if (c == '\b')
            {
                cout << "\b \b";
                i--;
            }
            else
            {
                password[i] = c;
                i++;
                cout << "*";
            }
        }
        password[i] = '\0';
        temp_pass = password;

        int size = get_size("Login_Customer.txt");

        ifstream in("Login_Customer.txt");
        for (int i = 0; i < size; i++)
        {
            in >> ID[i];
            in >> pass[i];
        }

        bool isLogin = false;
        int n = 0;

        for (int i = 0; i < size; i++)
        {
            if (ID[i] == temp_ID)
            {
                n = i;
                if (pass[n] == temp_pass)
                {                    
                    isLogin = true;                    
                    customerDisplay();
                    break;
                }    
                else
                {
                    isLogin = false;
                }
            }           
        }
        if (isLogin == false)
        {
            if (temp_ID == ID[n])
            {
                cout << "\n\n\n\tOOPS! The entered password was unmachted!" << "\n\n\tpress any key to continue";
                _getch();

                back:
                cout << "\n\n\t1. Press 1 to re-enter the details" << endl << "\t2. Press 2 exit" << endl << "\n\n\tYour selection is: ";
                cin >> selection;

                switch (selection)
                {
                case 1:
                    login();
                    break;
                case 2:
                    exit(0);
                    break;
                default:
                    cout << "\n\n\tEnter valid selection!";
                    goto back;
                }
            }
            else
            {
                cout << "\n\n\n\tYou are not a registered memeber";
                backk:
                cout << "\n\n\t1. RE-ENTER DETAILS" << "\n\t2. REGISTER" << "\n\t3. EXIT" << "\n\n\t" << "Your selection is: ";
                cin >> selection;

                Register reg;
                switch (selection)
                {
                case 1:
                    login();
                    break;
                case 2:
                    reg.get_name();
                    break;
                case 3:
                    exit(0);
                    break;
                default:
                    cout << "\n\n\tEnter valid selection!";
                    goto backk;
                }
            }
        }
    }

    void customerDisplay()
    {
        Car objCar;
        label:
        system("cls");
        cout <<"\n\n\n";
        cout.width(107);
        cout.fill('*');
        cout <<" ~ W E L C O M E   C U S T O M E R ~ " <<setw(219) <<setfill('*');
        cout << "\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t1. DISPLAY CARS \n\n\t\t\t\t\t\t\t\t\t\t2. BOOK CAR \n\n\t\t\t\t\t\t\t\t\t\t3. DISPLAY PREVIOUS BOOKINGS \n\n\t\t\t\t\t\t\t\t\t\t4. LOGOUT\n\n\n\t\t\t\t\t\t\t        Your selection is: ";
        cin >> selection;

        switch (selection)
        {
        case 1:
            objCar.display_Cars();
            break;
        case 2:
            objCar.display_Cars();
            objCar.book_car(temp_ID);
            break;
        case 3:
            previous_bookings();
            break;
        case 4:
            exit(0);
        default:
            cout << "\n\n\tEnter valid selection!";
            goto label;
        }
        int ans;
        cout << "\n\n\t1. GO BACK TO MAIN MENU\n\t2. LOGOUT\n\n\tYour selection is: ";
        cin >> ans;
        if (ans == 1)
        {
            goto label;
        }
    }
    
    void previous_bookings()
    {
        system("CLS");
        
        fstream in;
        string car_name, v_id, time, status, date, Type;
        float base_fare, bill;       
        int size = get_size(temp_ID.c_str());
        in.open(temp_ID.c_str(), fstream::in);
        Car* check = new Car[size];

        for (int i = 0; i < size; i++)
        {
            in >> car_name;
            check[i].setcarName(car_name);
            in >> v_id;
            check[i].setvehicleID(v_id);            
            in >> Type;
            check[i].setcarType(Type);
            in >> status;
            check[i].setstatus(status);
            in >> base_fare;
            check[i].setbaseFare(base_fare);
            in >> time;
            check[i].setHours(time);
            in >> date;
            check[i].setDate(date);
            in >> bill;
            check[i].setAmount(bill);
        }
        cout << "\n\n\n";
        cout.width(107);
        cout.fill('*');
        cout << " ~ P R E V I O U S   B O O K I N G S ~ " << setw(244) << setfill('*');
        for (int i = 0; i < size / 9; i++)
        {
            cout << "\n\n\n\t\t\t\t" << i + 1 << ".";
            cout << "  CAR ID: " << check[i].getVehicleID() << endl;
            cout << "\t\t\t\t    CAR NAME: " << check[i].getCarName() << endl;
            cout << "\t\t\t\t    CAR TYPE: " << check[i].getCarType() << endl;
            cout << "\t\t\t\t    BASE FARE: " << check[i].getFare() << endl;
            //cout << "\t\t\t\t    BOOKING STATUS: " << check[i].getFare() << endl;            
            cout << "\t\t\t\t    DURATION (hours): " << check[i].getHours() << endl;
            cout << "\t\t\t\t    BOOKED FOR (date): " << check[i].getDate() << endl;
            cout << "\t\t\t\t    BILL AMOUNT: " << check[i].getAmount() << endl << endl;
            
        }
        in.close();
    }    
};

void first_display()
{  
    customer cust;
    Register reg;

        system("CLS");
        Backk:
        cout << "\n\n\n\n";
        cout.fill('*');
        cout.width(105);
        cout << "  ~ C A R  R E N T A L  S Y S T E M ~  " << setw(70) << setfill('*') << "\n\n\n";
        cout.fill('*');
        cout.width(102);
        cout << "  ~ S E L E C T I O N  P A G E ~  " << setw(72) << setfill('*') << "\n\n";
        cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t     1. LOGIN";
        cout << "\n\n\t\t\t\t\t\t\t\t\t     2. REGISTER";
        cout << "\n\n\t\t\t\t\t\t\t\t\t     3. EXIT";
        cout << "\n\n\n\t\t\t\t\t\t\t     Your selection is: ";
        cin >> selection;

        switch (selection)
        {
        case 1:
            cust.login();
            break;
        case 2:
            reg.terms_condition();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout << "\n\nEnter valid selection!";
            goto Backk;
        } 
}

void main()
{   
    Back_1:
    cout << "\n\n\n\n";
    cout.fill('*');
    cout.width(108);
    cout << "  ~ C A R  R E N T A L  S Y S T E M ~  " << setw(66) << setfill('*') << "\n\n";
    cout.fill('*');
    cout.width(99);
    cout << "  ~ L O G I N  A S ~  "  << setw(77) << setfill('*');
    cout << "\n\n\n\n"<<"\t\t\t\t\t\t\t\t\t\t1. ADMIN\n\n"<<"\t\t\t\t\t\t\t\t\t\t2. CUSTOMER\n\n"<<"\t\t\t\t\t\t\t\t\t\t3. EXIT\n\n\n"<<"\t\t\t\t\t\t\t\tYour selection is: ";
    cin >> selection;
    
    admin ad;
    switch (selection)
    {
    case 1:
        ad.login();
        break;
    case 2:
        first_display();
        break;
    case 3:
        exit(0);
        break;
    default:
        cout << "\n\nEnter valid selection!";
        goto Back_1;
    }
}  