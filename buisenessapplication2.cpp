#include <iostream>
#include <fstream>
#include <conio.h>
#include <windows.h>
#include <vector>

using namespace std;
int menu();
void printHeader();
string checkRole();
int adminInterface(string adminName);
bool signIn(string Name, string Password, string customerName[], string customerPassword[], int count);
bool signUp(string customerName[], string customerPassword[], int count);
void customerList(string customerName[], string customerPassword[], string customerRole[], string name, int count);
void removecustomer(string customerName[], string customerPassword[], string customerRole[], string name, int &count);
int customerInterface(string customerName[], string customerRole[], int number);
int products();
void resetPassword(string customerPassword[], int number);
bool checkInteger(string value);
bool checkFloat(string value);
bool checkString(string name);
bool checkPassword(string password);
int readData(string path,string array[],string array2[],string array3[],int &count);
void storeData(string path,string array[],string array2[],string array3[],int count);
void addProduct(string companyName[], float price[], int quantity[], int &productCount, int size);
void viewProducts(string companyName[], float price[], int quantity[], int productCount);
void updateProduct(string companyName[], float price[], int quantity[], int productCount, int deleteCount);
void deleteProduct(string companyName[], float price[], int quantity[], int &productCount, int &deleteCount);
void buyProduct(string companyName[], float price[], int quantity[], int number, float totalBill[], string boughtProduct[], int &buyCount, int buyQuantity[], string selledProducts[], int selledQuantity[], int &sellCount, int productCount);
void cartProducts(string boughtProduct[], int buyQuantity[], int buyCount);
void customerFeedback(int number, string Feedback[]);
void viewFeedback(string customerName[], string customerRole[], int number, string Feedback[], int count);
void customerBill(string customerName[], string boughtProducts[], int buyQuantity[], float totalBill[], int number, int buyCount);
int DealerInterface();
string getData(string line,int no);
void arrayShift(string companyName[], float price[], int quantity[], int &productCount,int no);
void arrayStringShift(string companyName[], string password[], string role[], int &Count,int no);
void viewDealersDetail(string customerName[], string customerPassword[], string customerRole[], string adminName, int count);
void addDealer(string customerName[], string customerRole[], string customerPassword[], int &count, int &dealerCount, string adminName);
void removeDealer(string customerName[], string customerPassword[], string customerRole[], string name, int &count);
void sellProducts(string selledProducts[], int selledQuantity[], int sellCount);
void initializeBill(float totalBill[], int size);
int ShowMenu(vector<string> &optionList);
void Color(int color);
void hideAndVisibleCursor(bool isShow);
static void gotoxy(int x, int y);
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
int x=45,y=15;

int main()
{

    SetConsoleTextAttribute(h, 15);
    const string adminName = "tayyab";
    const string adminPassword = "Tayyab146";
    int dealerCount = 0;

    int count = 0, productCount = 0;
    int size = 15, customerSize = 100;
    int userIterations=0;
    int productIterations=0;
    int quantity[size];
    string quantityString[size];
    float price[size];
    string priceString[size];
    int deleteCount = 0;
    string customerName[customerSize] = {""};
    string path1="customerData.txt";
    string path2="productData.txt";
    string customerPassword[customerSize] = {""};
    string customerRole[customerSize] = {""};
    string Feedback[customerSize] = {""};
    string companyName[size];

    string selledProducts[10];
    int selledQuantity[10];
    int sellCount = 0;
    float totalBill[size];
    initializeBill(totalBill, size);

    int value = 1;
        
     
    while (value != 0)
    {
         printHeader();
    
    Color(4);
    cout << "L O G I N    M E N U <<" << endl;
    hideAndVisibleCursor(false);
    vector<string> j = {"1. Sign In","2. Sign Up","3. Exit"};
    int option = ShowMenu(j);
    value=option+1;
   //  value = menu();
        string role;
        // string line;
        // int no=0;
       count= readData(path1, customerName, customerPassword, customerRole, count);
       productCount = readData(path2, companyName, priceString, quantityString, productCount);
    //   fstream getrequireData;
    //   getrequireData.open(path2,ios::in);
    //     while(getline(getrequireData,line))
    //     {
        for(int i=0;i<productCount;i++){
            quantity[i] = stoi(quantityString[i]);
           price[i] = stof(priceString[i]);
        }
        //    companyName[no]=getData(line,1);
        //    quantityString[no] = getData(line,2);
        //    priceString[no] = getData(line,3);
        //    no++;
        //   productCount++;
        // }
    // getrequireData.close();
// for(int i=0;i<productCount;i++){
//     // quantity[i] = stoi(quantityString[i]);
//     // price[i] = stof(priceString[i]);
//     cout<<quantityString[i]<<endl;
//     cout<<priceString[i];
//     getch();
// }
      //  productCount = productIterations;
        // count = userIterations;
        if (value == 1)
        {
            role = checkRole();
            if (role == "invalid")
            {
                cout << "Please Enter valid role.";
                getch();
                continue;
            }

            printHeader();
            int number;
            string Name;
            string Password;
            SetConsoleTextAttribute(h, 12);
            cout << "S I G N-I N    M E N U <<" << endl;
            SetConsoleTextAttribute(h, 10);

            cout << "\t\t\t\t\t\t\t"
                 << "Enter Name(atleast 5 characters): ";
            cin.ignore();
            getline(cin, Name);
            //cin>>Name;
            if (!checkString(Name))
            {
                cout << "Enter valid String.";
                getch();
                continue;
            }

            cout << "\t\t\t\t\t\t\t"
                 << "Enter Password(atleast 8 characters): ";
            //getline(cin, Password);
            cin>>Password;
            if (!checkPassword(Password))
            {
                cout << "Password contains at least 1 Uppercase and no special character!.";
                getch();
                continue;
            }

            if (Name == adminName && Password == adminPassword)
            {
                if (role == "admin" || role == "Admin")
                {
                    int select = 1;

                    while (select != 0)
                    {
                        select = adminInterface(adminName);
                        if (select == 1)
                        {
                            viewDealersDetail(customerName, customerPassword, customerRole, adminName, count);
                        }
                        else if (select == 2)
                        {
                            addDealer(customerName, customerRole, customerPassword, count, dealerCount, adminName);
                        }
                        else if (select == 3)
                        {
                            removeDealer(customerName, customerPassword, customerRole, adminName, count);
                        }
                        else if (select == 4)
                        {
                            customerList(customerName, customerPassword, customerRole, adminName, count);
                        }
                        else if (select == 5)
                        {
                            removecustomer(customerName, customerPassword, customerRole, adminName, count);
                        }

                        else if (select == 6)
                        {
                            viewProducts(companyName, price, quantity, productCount);
                        }
                        else if (select == 7)
                        {
                            updateProduct(companyName, price, quantity, productCount, deleteCount);
                        }
                        else if (select == 8)
                        {
                            sellProducts(selledProducts, selledQuantity, sellCount);
                        }
                        else
                        {
                            break;
                        }
                        getch();
                    }
                }
                else
                {
                    cout << "Enter valid role.";
                    getch();
                }
            }
            else
            {
                bool signInValue = signIn(Name, Password, customerName, customerPassword, count);
                if (signInValue == true)
                {
                    for (int i = 0; i <= count; i++)
                    {
                        if (Name == customerName[i] && Password == customerPassword[i])
                        {
                            number = i;
                            break;
                        }
                    }
                    if (role == customerRole[number])
                    {

                        if (role == "Dealer" && (Name == customerName[number]) && (Password == customerPassword[number]))
                        {
                            string name = customerName[number];
                            int option = 1;
                            while (option != 0)
                            {
                                option = DealerInterface();
                                if (option == 1)
                                {
                                    customerList(customerName, customerPassword, customerRole, name, count);
                                }
                                else if (option == 2)
                                {
                                    removecustomer(customerName, customerPassword, customerRole, name, count);
                                }
                                else if (option == 3)
                                {
                                    addProduct(companyName, price, quantity, productCount, size);
                                }
                                else if (option == 4)
                                {
                                    updateProduct(companyName, price, quantity, productCount, deleteCount);
                                }
                                else if (option == 5)
                                {
                                    viewProducts(companyName, price, quantity, productCount);
                                }
                                else if (option == 6)
                                {
                                    deleteProduct(companyName, price, quantity, productCount, deleteCount);
                                }
                                else if (option == 7)
                                {
                                    viewFeedback(customerName, customerRole, number, Feedback, count);
                                }
                                getch();
                            }
                        }
                        else if (role == "Customer")
                        {

                            string boughtProduct[10];
                            int buyQuantity[10];
                            int buyCount = 0;
                            int choice = 1;

                            while (choice != 0)
                            {
                                choice = customerInterface(customerName, customerRole, number);
                                if (choice == 1)
                                {
                                    viewProducts(companyName, price, quantity, productCount);
                                }
                                else if (choice == 2)
                                {
                                    buyProduct(companyName, price, quantity, number, totalBill, boughtProduct, buyCount, buyQuantity, selledProducts, selledQuantity, sellCount, productCount);
                                }
                                else if (choice == 3)
                                {
                                    cartProducts(boughtProduct, buyQuantity, buyCount);
                                }
                                else if (choice == 4)
                                {
                                    customerFeedback(number, Feedback);
                                }
                                else if (choice == 5)
                                {
                                    resetPassword(customerPassword, number);
                                }
                                else if (choice == 6)
                                {
                                    customerBill(customerName, boughtProduct, buyQuantity, totalBill, number, buyCount);
                                }
                                else if (choice == 0)
                                {
                                    break;
                                }
                                else
                                {
                                    SetConsoleTextAttribute(h, 4);
                                    cout << "Invalid input.";
                                }
                                getch();
                            }
                        }
                        else
                        {
                            SetConsoleTextAttribute(h, 4);
                            cout << "Invalid input.";
                            getch();
                        }
                    }
                    else
                    {
                        cout << "Enter valid role.";
                        getch();
                        continue;
                    }
                }
                else
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "Incorrect password or Name.";
                    cout << "Try again...";
                    getch();
                }
            }
            getch();
        }

        else if (value == 2)
        {
            string number = "1";
            while (number == "1")
            {
                string Name;
                string password;
                customerRole[count] = "Customer";
                printHeader();
                SetConsoleTextAttribute(h, 4);
                cout << "S I G N U P    M E N U <<" << endl;
                SetConsoleTextAttribute(h, 9);
                cout << "\t\t"
                     << "SIGN UP AS A:\t" << customerRole[count] << endl;
                SetConsoleTextAttribute(h, 10);
                cout << "\t\t\t\t\t\t\t"
                     << "Enter Name(atleast 4 characters): ";
                cin.ignore();
                getline(cin,Name);
                // cin >> Name;
                if (!checkString(Name))
                {
                    cout << "Enter valid String.";
                    getch();
                    continue;
                }
                if (Name == adminName)
                {
                    cout << "Enter valid Name.";
                    getch();
                    continue;
                }

                cout << "\n\t\t\t\t\t\t\t"
                     << "Enter Password(atleast 8 letters): ";
                cin >> password;
                if (!checkPassword(password))
                {
                    SetConsoleTextAttribute(h, 9);
                    cout << "Password contains at least 1 Uppercase and no special character!";
                    getch();
                    continue;
                }
                customerName[count] = Name;
                customerPassword[count] = password;
                // cout<<"count"<<count;
                // if ((customerRole[count] == "Dealer") || (customerRole[count] == "dealer") || (customerRole[count] == "customer") || (customerRole[count] == "Customer"))

                // {
                bool signUpValue = signUp(customerName, customerPassword, count);
                if (signUpValue)
                {
                    SetConsoleTextAttribute(h, 3);

                    count++;
                    cout << "Registered successfully." << endl;
                    getch();
                }
                else if (!signUpValue)
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "Sorry , customerName is already taken." << endl;
                    customerName[count] = "";
                    customerPassword[count] = "";
                    getch();
                }

                printHeader();
                SetConsoleTextAttribute(h, 6);

                cout << "Enter 1 to add customer or 0 to continue: ";
                cin.ignore();
                getline(cin,number);

                if (number == "0")
                {
                    break;
                }
                else if (number == "1")
                {
                    continue;
                }

                else
                {
                    SetConsoleTextAttribute(h, 4);
                    cout << "Enter valid number.";
                    getch();
                    break;
                }
                // }
                // else
                // {
                //     cout << "Enter your Role correctly." << endl;
                // getch();
                // continue;
                // }
            }
        }
        else if (value == 3)
        {
            return 0;
        }
        else
        {
            SetConsoleTextAttribute(h, 4);
            cout << "Please enter valid number." << endl;
            getch();
        }
        for (int i = 0; i < productCount; i++)
        {
            quantityString[i]=to_string(quantity[i]);
            priceString[i]=to_string(price[i]);
        }
        
         storeData(path1,customerName,customerPassword,customerRole, count);
         storeData(path2,companyName, priceString, quantityString, productCount);
    }

}

int menu()
{
    printHeader();

    int value;
    string menuOption;
    SetConsoleTextAttribute(h, 4);
    cout << "L O G I N    M E N U <<" << endl;
    SetConsoleTextAttribute(h, 10);
    cout << "\t\t\t\t\t\t\t"
         << "1. Sign In" << endl;
    cout << "\t\t\t\t\t\t\t"
         << "2. Sign Up" << endl;
    cout << "\t\t\t\t\t\t\t"
         << "3. Exit" << endl;
    SetConsoleTextAttribute(h, 6);
    cout << "\t\t\t\t\t\t\t"
         << "Enter any number: ";
    cin >> menuOption;
    if (checkInteger(menuOption))
    {
        value = stoi(menuOption);
    }
    else if (!checkInteger(menuOption))
    {
        cout << "The input must be in integers." << endl;
        value = 4;
        getch();
    }
    return value;
}
void printHeader()
{
    system("cls");
    SetConsoleTextAttribute(h, 10);
    cout << "\t"
         << "$$$$$$$$\\                $$$$$$\\      $$$$$$$$\\      $$$$$$\\      $$$$$$$\\      $$$$$$$$\\ " << endl;
    cout << "\t"
         << "$$  _____|              $$  __$$\\     \\__$$  __|    $$  __$$\\     $$  __$$\\     $$  _____|" << endl;
    cout << "\t"
         << "$$ |                    $$ /  \\__|       $$ |       $$ /  $$ |    $$ |  $$ |    $$ |      " << endl;
    cout << "\t"
         << "$$$$$\\       $$$$$$\\    \\$$$$$$\\         $$ |       $$ |  $$ |    $$$$$$$  |    $$$$$\\    " << endl;
    cout << "\t"
         << "$$  __|      \\______|    \\____$$\\        $$ |       $$ |  $$ |    $$  __$$<     $$  __|   " << endl;
    cout << "\t"
         << "$$ |                    $$\\   $$ |       $$ |       $$ |  $$ |    $$ |  $$ |    $$ |      " << endl;
    cout << "\t"
         << "$$$$$$$$\\               \\$$$$$$  |       $$ |        $$$$$$  |    $$ |  $$ |    $$$$$$$$\\ " << endl;
    cout << "\t"
         << "\\________|               \\______/        \\__|        \\______/     \\__|  \\__|    \\________|" << endl;
    cout << "\n\n\n\n";
}
string checkRole()
{
    printHeader();
    SetConsoleTextAttribute(h, 4);
    cout << "S I G N U P    M E N U <<" << endl;
    SetConsoleTextAttribute(h, 10);
    string roleCheck="";
    cout << "\t\t\t\t\t"
         << "Enter your Role(Admin/Dealer/Customer): ";
    cin >> roleCheck;
    
    if (roleCheck == "admin" || roleCheck == "Admin")
    {
    getch();
        return "Admin";
    }
    else if (roleCheck == "dealer" || roleCheck == "Dealer")
    {
        return "Dealer";
    }
    else if (roleCheck == "Customer" || roleCheck == "customer")
    {
        return "Customer";
    }
    else
    {
        return "invalid";
    }
}
bool signUp(string customerName[], string customerPassword[], int count)
{
    bool value = true;
    for (int i = 0; i < count; i++)
    {
        if (customerName[count] == customerName[i] && customerPassword[count] == customerPassword[i])
        {
            value = false;
        }
    }

    return value;
}
bool signIn(string Name, string Password, string customerName[], string customerPassword[], int count)
{
    bool value = false;
    for (int i = 0; i <= count; i++)
    {
        if (Name == customerName[i] && Password == customerPassword[i])
        {
            value = true;
        }
    }
    return value;
}
int adminInterface(string adminName)
{
    printHeader();
    SetConsoleTextAttribute(h, 4);
    cout << "A D M I N    I N T E R F A C E  <<" << endl;
    SetConsoleTextAttribute(h, 10);
    cout << "\t\t"
         << "Welcome " << adminName << endl
         << endl;
    int option;
    string adminOption;
    SetConsoleTextAttribute(h, 6);
    cout << "\t\t\t\t\t"
         << "1.    View Dealers Detail." << endl;
    cout << "\t\t\t\t\t"
         << "2.    Add Dealer." << endl;
    cout << "\t\t\t\t\t"
         << "3.    Remove Dealer." << endl;
    cout << "\t\t\t\t\t"
         << "4.    View Customers Detail." << endl;
    cout << "\t\t\t\t\t"
         << "5.    Remove Customer." << endl;
    cout << "\t\t\t\t\t"
         << "6.    View Products in Store." << endl;
    cout << "\t\t\t\t\t"
         << "7.    Update Products." << endl;
    cout << "\t\t\t\t\t"
         << "8.    Selled Products." << endl;
    cout << "\t\t\t\t\t"
         << "0.    Logout." << endl;
    cout << "\t\t\t\t"
         << "Enter your option:";
    cin >> adminOption;
    if (checkInteger(adminOption))
    {
        option = stoi(adminOption);
    }
    else if (!checkInteger(adminOption))
    {
        cout << "The input must be in integers." << endl;
        getch();
        adminInterface(adminName);
    }
    return option;
}
void customerList(string customerName[], string customerPassword[], string customerRole[], string name, int count)
{
    printHeader();
    Color(12);                            //header  for red color
    cout << "C U S T O M E R S    L I S T" << endl;
    Color(10);                             //list hiding  for green color
    cout << "Welcome  " << name << endl;
    cout << "Here is the list of customers..." << endl;
    cout << "\t\t\t"
         << "Names";
         gotoxy(x,y);
         cout<< "Password" << endl;
    Color(6);                           //list for yellow color
    int line=1;
    for (int i = 0; i <= count; i++)
    {
        if (customerName[i] == "")
        {
            continue;
        }

        if (customerRole[i] == "Dealer")
        {
            continue;
        }

        {
            cout << "\t\t\t" << customerName[i];
            gotoxy(x,y+line);
            cout << customerPassword[i] << endl;
            line++;
        }
    }
    getch();
}
int customerInterface(string customerName[], string customerRole[], int number)
{
    printHeader();
    SetConsoleTextAttribute(h, 4);
    cout << "C U S T O M E R    I N T E R F A C E  <<" << endl;
    SetConsoleTextAttribute(h, 10);
    cout << "\t\t"
         << "Welcome " << customerName[number] << endl
         << endl;
    int option;
    string customerOption;
    SetConsoleTextAttribute(h, 6);
    cout << "\t\t\t\t\t"
         << "1.    View Products." << endl;
    cout << "\t\t\t\t\t"
         << "2.    Buy Product." << endl;
    cout << "\t\t\t\t\t"
         << "3.    View Products in Cart" << endl;
    cout << "\t\t\t\t\t"
         << "4.    Product Feedback." << endl;
    cout << "\t\t\t\t\t"
         << "5.    Change Password." << endl;
    cout << "\t\t\t\t\t"
         << "6.    Generate Bill." << endl;
    cout << "\t\t\t\t\t"
         << "0.    Logout." << endl;
    cout << "\t\t\t\t"
         << "Enter your option:";
    cin >> customerOption;
    if (checkInteger(customerOption))
    {
        option = stoi(customerOption);
    }
    else if (!checkInteger(customerOption))
    {
        cout << "The input must be in integers." << endl;
        option = 10;
        getch();
    }

    return option;
}
void resetPassword(string customerPassword[], int number)
{
    string check = "1";
    while (check == "1")
    {
        printHeader();
        int countDealer = 0;
        SetConsoleTextAttribute(h, 12);//to make header red colour
        cout << "R E S E T   P A S S W O R D>>";
        string newPassword;
        SetConsoleTextAttribute(h, 6);

        cout << endl;
        //      << "Previous Password:";
        // cin >> password;
        cout << "\t\t\tNew Password(atleast 8 characters):";
        cin >> newPassword;
        if (!checkPassword(newPassword))
        {
            SetConsoleTextAttribute(h, 9);
            cout << "Password contains at least 1 Uppercase and no special character!";
            getch();
            continue;
        }
        check="0";
        if (newPassword == customerPassword[number])
        {
            cout<<"Already using."<<endl;
            cout<<"Press 0 to keep this password or 1 to change.";
            cin>>check;
            }
        if (check== "0"){
            customerPassword[number] = newPassword;
            // check = "0";
            cout << "Password updated successfully.";
            getch();
            break;
        }
        else
        {
            continue;
        }
    }
}
int DealerInterface()
{
    printHeader();
    SetConsoleTextAttribute(h, 12);
    cout << "D E A L E R   M E N U >>" << endl
         << endl;
    int option;
    string dealerOption;
    SetConsoleTextAttribute(h, 10);
    cout << "\t\t\t\t\t"
         << "1.    View all customers." << endl;
    cout << "\t\t\t\t\t"
         << "2.    Remove customer." << endl;
    cout << "\t\t\t\t\t"
         << "3.    Add Product." << endl;
    cout << "\t\t\t\t\t"
         << "4.    Update Product." << endl;
    cout << "\t\t\t\t\t"
         << "5.    View all Products." << endl;
    cout << "\t\t\t\t\t"
         << "6.    Delete Product." << endl;
    cout << "\t\t\t\t\t"
         << "7.    View Customer Feedback." << endl;
    cout << "\t\t\t\t\t"
         << "0.    Logout" << endl;
    SetConsoleTextAttribute(h, 6);
    cout << "\t\t\t\t"
         << "Enter your option:";
    cin >> dealerOption;
    if (checkInteger(dealerOption))
    {
        option = stoi(dealerOption);
    }
    else if (!checkInteger(dealerOption))
    {
        cout << "The input must be in integers." << endl;
        option = 10;
        getch();
    }

    return option;
}
void addDealer(string customerName[], string customerRole[], string customerPassword[], int &count, int &dealerCount, string adminName)
{
    string number = "1";
    while (number == "1")
    {
        string checkName;
        string check;
        if (dealerCount > 5)
        {
            cout << "Dealers capacity is full. You can't add more Dealers.";
            break;
        }

        customerRole[count] = "Dealer";
        printHeader();
        SetConsoleTextAttribute(h, 4);
        cout << "S I G N U P    M E N U <<" << endl;
        SetConsoleTextAttribute(h, 9);
        cout << "\t\t"
             << "SIGN UP AS A:\t" << customerRole[count] << endl;
        SetConsoleTextAttribute(h, 10);
        cout << "\t\t\t\t\t\t\t"
             << "Enter dealer Name: ";
        cin >> checkName;
        if (!checkString(checkName))
        {
            cout << "Enter valid String.";
            getch();
            continue;
        }
        if (checkName == adminName)
        {
            cout << "Enter valid Name.";
            getch();
            continue;
        }
        else if (checkString(checkName))
        {
            customerName[count] = checkName;
        }

        cout << "\t\t\t\t\t\t\t"
             << "Enter dealer Password: ";
        cin >> check;
        if (!checkPassword(check))
        {
            cout << "Enter valid String.";
            getch();
            continue;
        }
        else if (checkPassword(check))
        {
            customerPassword[count] = check;
        }
        bool signUpValue = signUp(customerName, customerPassword, count);
        if (signUpValue == false)
        {
            SetConsoleTextAttribute(h, 4);
            cout << "Sorry , Dealer Name is already taken." << endl;
            customerName[count] = "";
            customerPassword[count] = "";
            getch();
            count--;
        }

        else
        {
            SetConsoleTextAttribute(h, 3);
            cout << "Registered successfully." << endl;
            dealerCount++;
            getch();
        }
        printHeader();
        SetConsoleTextAttribute(h, 6);

        cout << "Enter 1 to add Dealer or 0 to continue: ";
        cin >> number;
        count++;

        if (number == "0")
        {
            break;
        }
        else if (number != "1")
        {
            SetConsoleTextAttribute(h, 4);
            cout << "Enter valid number.";
            getch();
            break;
        }
    }
}
void viewDealersDetail(string customerName[], string customerPassword[], string customerRole[], string adminName, int count)
{
    printHeader();
    Color(12);                           //header  for red color
    cout << "D E A L E R S    L I S T" << endl;
    Color(10);                          //list hiding  for green color
    cout << "Welcome  " << adminName << endl;
    cout << "Here is the list of Dealers..." << endl;
    cout << "\t\t\t"
         << "Names";
         gotoxy(x,y);
         cout<< "Password" << endl;
   Color(6);                             //list for yellow color
    int line=1;
    for (int i = 0; i <= count; i++)
    {
        if (customerName[i] == "")
        {
            continue;
        }

        if (customerRole[i] == "Customer" || customerRole[i] == "customer")
        {
            continue;
        }

        {
            cout << "\t\t\t" << customerName[i];
            gotoxy(x,y+line);
            cout<< customerPassword[i] << endl;
            line++;
        }
    }
    getch();
}
void removeDealer(string customerName[], string customerPassword[], string customerRole[], string name, int &count)
{

    printHeader();
    int countDealer = 0;
    int number;
    SetConsoleTextAttribute(h, 12);
    cout << "R E M O V E   D E A L E R >>";
    viewDealersDetail(customerName, customerPassword, customerRole, name, count);
    string dealerName;
    SetConsoleTextAttribute(h, 6);
    cout << "Dealer Name to remove:";
    cin >> dealerName;
    for (int i = 0; i < count; i++)
    {
        if (dealerName == customerName[i])
        {
            number=i;
            customerName[i] = "";
            countDealer++;
            break;
        }
    }
    if (countDealer == 1)
    {
        arrayStringShift(customerName,customerPassword,customerRole,count,number);
        SetConsoleTextAttribute(h, 12);
        cout << "Dealer is Revomed.";
        getch();
    }
    else
    {
        SetConsoleTextAttribute(h, 4);
        cout << "Dealer not exist.";
        getch();
    }
}
int products()
{
    printHeader();
    SetConsoleTextAttribute(h, 4);
    cout << "P R O D U C T S   M E N U >>" << endl
         << endl;
    int productName;
    string productOption;
    SetConsoleTextAttribute(h, 10);
    cout << "\t\t\t\t\t"
         << "Which product you want to add:" << endl;
    cout << "\t\t\t\t\t"
         << "1.         Mobile" << endl;
    cout << "\t\t\t\t\t"
         << "2.         Laptop" << endl;
    cout << "\t\t\t\t\t"
         << "3.         Desktop" << endl;
    cout << "\t\t\t\t\t"
         << "4.         Electrical Appliances" << endl;
    cout << "\t\t\t\t\t"
         << "0.         Exit" << endl;
    SetConsoleTextAttribute(h, 6);
    cout << "\t\t\t\t"
         << "Enter your option:" << endl;
    cin >> productOption;
    if (checkInteger(productOption))
    {
        productName = stoi(productOption);
    }
    else if (!checkInteger(productOption))
    {
        cout << "The input must be in integers." << endl;
        productName = 10;
        getch();
    }
    return productName;
}
void addProduct(string companyName[], float price[], int quantity[], int &productCount, int size)
{
    printHeader();
    SetConsoleTextAttribute(h, 4);
    cout << "M A I N   M E N U << "
         << "A D D   P R O D U C T" << endl
         << endl;
    SetConsoleTextAttribute(h, 10);
    while (true)
    {

        string productType = "";
        int product;
        string checkName;
        product = products();
        if (product == 1)
        {
            productType = "Mobile";
        }

        else if (product == 2)
        {
            productType = "Laptop";
        }
        else if (product == 3)
        {
            productType = "Desktop";
        }
        else if (product == 4)
        {
            productType = "Electrical Appliance";
        }
        else if (product == 0)
        {
            break;
        }
        else
        {
            cout << "Enter valid option";
            getch();
            continue;
        }

        if (productCount < size)
        {
            int index=-1;
            SetConsoleTextAttribute(h, 6);
            string checkQuantity;
            string checkPrice;
            cout << productType << " Company Name:";
            cin >> checkName;
            if (!checkString(checkName))
            {
                cout << "Enter valid String.";
                getch();
                continue;
            }
            else if (checkString(checkName))
            {
                for (int i = 0; i < productCount; i++)
                {
                    if (checkName==companyName[i])
                    {
                        index=i;
                    }
                }
                companyName[productCount] = checkName;
            }

            cout << productType << " Price:";
            cin >> checkPrice;
            if (checkFloat(checkPrice))
            {
                price[productCount] = stof(checkPrice);
            }
            else if (!checkFloat(checkPrice))
            {
                cout << "The input must be in float." << endl;
                getch();
                continue;
            }
            cout << productType << " Quantity:";
            cin >> checkQuantity;
            if (checkInteger(checkQuantity))
            {

                
                quantity[productCount] = stoi(checkQuantity);
                if (index==-1)
                {
                    productCount++;
                }
                else{
                    companyName[productCount]="";
                    price[index]=price[productCount];
                    quantity[index]+=quantity[productCount];
                    price[productCount]=0.0;
                    quantity[productCount]=0;
                }
                
                
                SetConsoleTextAttribute(h, 3);
                cout << "Product Added to stock successfully.";
                getch();
            }
            else if (!checkInteger(checkQuantity))
            {
                cout << "The input must be in integers." << endl;
                continue;
                getch();
            }
        }
        else if (productCount >= size)
        {
            SetConsoleTextAttribute(h, 12);
            cout << "Sorry, capacity is full.";
        }
    }
}

void viewProducts(string companyName[], float price[], int quantity[], int productCount)
{
    printHeader();
    SetConsoleTextAttribute(h, 4);
    cout << "M A I N   M E N U << "
         << "V I E W   P R O D U C T S" << endl
         << endl;
    Color(10);
    cout << "\t"
         << "List of Products..." << endl;
    Color(50);
    cout << "\t\t\t\t"
         << "No. "
         << "Company Name "
         << "\t"
         << "\t"
         << "Price"
         << "\t"
         << "\t"
         << "\t"
         << "Available Stock" << endl;
    SetConsoleTextAttribute(h, 6);
    int count = 1;
    for (int i = 0; i < productCount; i++)
    {
        if (companyName[i] == "")
        {
            continue;
        }
        cout << "\t\t\t\t" << count << " . " << companyName[i] << "\t"
             << "\t"
             << "\t" << price[i] << "\t"
             << "\t"
             << "\t" << quantity[i] << endl;
        count++;
    }
    getch();
}
void updateProduct(string companyName[], float price[], int quantity[], int productCount, int deleteCount)
{
    printHeader();
    SetConsoleTextAttribute(h, 12);
    cout
        << "U P D A T E   P R O D U C T S" << endl
        << endl;
    string number;
    int numbr;
    string checkQuantity;
    string checkPrice;
start:
    viewProducts(companyName, price, quantity, productCount);
    SetConsoleTextAttribute(h, 6);
    cout << "Enter Product No or Name to Update:";
    cin >> number;
    if (number.length() == 1 && number[0] >= '0' && number[0] <= '9')
    {
        numbr = stoi(number);
        numbr--;
        numbr += deleteCount;
    }
    else if (number.length() > 1)
    {
        for (int i = 0; i < productCount; i++)
        {
            if (companyName[i] == number)
            {
                numbr = i;
            }
        }
    }

    else
    {
        cout << "Enter valid input.";
        getch();
        goto start;
    }
    if (numbr >= productCount)
    {
        cout << "Enter valid input.";
        getch();
        goto start;
    }

    SetConsoleTextAttribute(h, 10);
    cout << "Product Detail.." << endl;
    cout << numbr + 1;
    cout << ". " << companyName[numbr] << "\t"
         << "\t" << price[numbr] << "\t"
         << "\t" << quantity[numbr] << endl;
    SetConsoleTextAttribute(h, 6);
    while (true)
    {

        cout << "Enter Updated Name:";
        cin >> companyName[numbr];
        cout << "Enter Updated Price:";
        cin >> checkPrice;
        if (checkFloat(checkPrice))
        {
            price[numbr] = stof(checkPrice);
        }
        else if (!checkFloat(checkPrice))
        {
            cout << "The input must be in float." << endl;
            continue;
            getch();
        }
        cout << "Enter Updated quantity:";
        cin >> checkQuantity;
        if (checkInteger(checkQuantity))
        {
            quantity[numbr] = stoi(checkQuantity);
            cout << "Product Updated Successfully.";
        }
        else if (!checkInteger(checkQuantity))
        {
            cout << "The input must be in integers." << endl;
            continue;
            getch();
        }
        break;
    }
}
void deleteProduct(string companyName[], float price[], int quantity[], int &productCount, int &deleteCount)
{
    while (true)
    {
        printHeader();
        SetConsoleTextAttribute(h, 12);
        cout
            << "D E L E T E   P R O D U C T S" << endl
            << endl;
        SetConsoleTextAttribute(h, 10);
        cout << "\t"
             << "List of Products..." << endl;
        viewProducts(companyName, price, quantity, productCount);
        int no, check;
        string number;
        string checkOption;
    start:
        cout << "Enter Procuct No or Name to Delete: ";
        cin >> number;
        if (number.length() == 1 && number[0] >= '0' && number[0] <= '9')
        {
            no = stoi(number);
            no--;
           // no += deleteCount;
        }
        else if (number.length() > 1)
        {
            for (int i = 0; i < productCount; i++)
            {
                if (companyName[i] == number)
                {
                    no = i;
                }
            }
        }
        if (no >= productCount)
        {
            cout << "Enter valid input.";
            getch();
            goto start;
        }

        SetConsoleTextAttribute(h, 12);
        cout << "Are you sure to delete this Product:" << endl;
        cout << no + 1;
        cout << ". " << companyName[no] << "\t"
             << "\t" << price[no] << "\t"
             << "\t" << quantity[no] << endl;
        SetConsoleTextAttribute(h, 6);
        cout << "Press 1 to Continue or 0 to Recheck:";
        cin >> checkOption;
        if (checkInteger(checkOption))
        {
            check = stoi(checkOption);
        }
        else if (!checkInteger(checkOption))
        {
            cout << "The input must be in integers." << endl;
            check = 0;
            getch();
        }
        if (check == 1)
        {
            arrayShift(companyName,price, quantity,productCount,no);
            cout<<"Product Deleted successfully.";
            cout<<productCount;
            getch();
            deleteCount++;
            break;
        }
    }
}
void arrayShift(string companyName[], float price[], int quantity[], int &productCount,int no){
for (int i = no; i < productCount; i++)
{
    companyName[i]=companyName[i+1];
    price[i]=price[i+1];
    quantity[i]=quantity[i+1];
}
companyName[productCount]="";
price[productCount]=0.0;
   quantity[productCount]=0;
productCount--;

}
void arrayStringShift(string companyName[], string password[], string role[], int &Count,int no){
for (int i = no; i < Count; i++)
{
    companyName[i]=companyName[i+1];
    password[i]=password[i+1];
    role[i]=role[i+1];
}
companyName[Count]="";
password[Count]="";
role[Count]="";
Count--;

}
void removecustomer(string customerName[], string customerPassword[], string customerRole[], string name, int &count)
{
    printHeader();
    int countCustomer = 0;
    int number = 0;
    SetConsoleTextAttribute(h, 12);            //red color for hiding
    cout << "R E M O V E   U S E R >>";
    customerList(customerName, customerPassword, customerRole, name, count);
    string removeName;
    SetConsoleTextAttribute(h, 6);             //yellow color
    cout << "Customer Name to remove:";
    cin >> removeName;
    for (int i = 0; i < count; i++)
    {
        if (removeName == customerName[i])
        {
            customerName[i] = "";
            countCustomer++;
            number=i;
            break;
        }
    }
    if (countCustomer == 1)
    {
        arrayStringShift(customerName,customerPassword,customerRole,count,number);
        SetConsoleTextAttribute(h, 12);
        cout << "Customer is Revomed.";
        getch();
    }
    else
    {
        SetConsoleTextAttribute(h, 4);
        cout << "Customer not exist.";
        getch();
    }
}
void buyProduct(string companyName[], float price[], int quantity[], int number, float totalBill[], string boughtProduct[], int &buyCount, int buyQuantity[], string selledProducts[], int selledQuantity[], int &sellCount, int productCount)
{
    string add = "1";
    int check = -1;
    int already=-1;
    string checkQuantity;
    while (add != "0")
    {
        printHeader();
        SetConsoleTextAttribute(h, 12);
        string productName;
        int Quantity;
        cout << "B U Y   P R O D U C T S" << endl
             << endl;
        viewProducts(companyName, price, quantity, productCount);
        SetConsoleTextAttribute(h, 6);                          //for yellow colour
        cout << "Enter Product Name you Want to Buy:";
        cin >> productName;
        cout << "Enter Product Quantity:";
        cin >> checkQuantity;
        if (checkInteger(checkQuantity))
        {
            Quantity = stoi(checkQuantity);
            getch();
        }
        else if (!checkInteger(checkQuantity))
        {
            cout << "The input must be in integers." << endl;
            continue;
            getch();
        }

        for (int i = 0; i <= productCount; i++)
        {
            if ((companyName[i] == productName) || (to_string(i + 1) == productName))
            {

                check = i;
            }
        }
        if (Quantity==0)
        {
            cout<<"The quantity you entered is 0."<<endl;
            cout<<"Press 1 to buy product or 0 to go back."<<endl;
            cin>>add;
            continue;
        }
        
        else if (quantity[check] >= 1 && check != -1)
        {
            quantity[check] -= Quantity;
            if ((quantity[check]) >= 0)
            {
                float bill = (price[check] * Quantity);
                totalBill[number] += bill;
                for (int i = 0; i < buyCount; i++)
                {
                    if (companyName[check]==boughtProduct[i])
                    {
                        already=i;
                        break;
                    }
                    
                }
                if (already!=-1)
                {
                    buyQuantity[already]+=Quantity;
                    selledQuantity[already]+=Quantity;
                    SetConsoleTextAttribute(h, 3);                  //blue color for successfull buying
                cout << companyName[check] << " added to your cart successfully.";
                }
                else if (already==-1)
                {
                
                boughtProduct[buyCount] = companyName[check];
                selledProducts[sellCount] = companyName[check];
                selledQuantity[sellCount] = Quantity;
                buyQuantity[buyCount] = Quantity;
                SetConsoleTextAttribute(h, 3);                  //blue color for successfull buying
                cout << companyName[check] << " added to your cart successfully.";
                buyCount++;
                sellCount++;
                break;
                }
            }
            else
            {
                SetConsoleTextAttribute(h, 12);                  //red colour for wrong quantity
                quantity[check] += Quantity;
                cout << "Sorry, We have " << quantity[check] << " Left.";
            }
            break;
        }
        else if (quantity[check] < 1 && check != -1)
        {
            SetConsoleTextAttribute(h, 12);
            cout << "This Product is out of stock.";
            break;
        }
        else if (check = -1)
        {
            SetConsoleTextAttribute(h, 12);                        //red color for wrong product name
            cout << "Invalid Product Name.";
        }

        SetConsoleTextAttribute(h, 6);                             //for yellow colour
        cout << endl
             << "Enter 1 to Add Product in cart or 0 to go back";
        cin >> add;
    }
}
void customerFeedback(int number, string Feedback[])
{
    cin.ignore();
    SetConsoleTextAttribute(h, 6);
    string feedbackcustomer;
    cout << "Write your feedback:";
    getline(cin, feedbackcustomer);
    Feedback[number] = feedbackcustomer;
    getch();
}
void initializeBill(float totalBill[], int size)
{

    for (int i = 0; i < size; i++)
    {
        totalBill[i] = 0;
    }
}
void cartProducts(string boughtProduct[], int buyQuantity[], int buyCount)
{
    printHeader();
    SetConsoleTextAttribute(h, 12);
    cout << "P R O D U C T S    I N    C A R T" << endl;
    if (buyCount <= 0)
    {
        cout << "You have not bought anything yet.";
    }
    else
    {
        SetConsoleTextAttribute(h, 10);
        cout << "\t\t\t\t"
             << "Product Names"
             << "\t\t\t"
             << "Quantity" << endl;
        SetConsoleTextAttribute(h, 6);
        for (int i = 0; i < buyCount; i++)
        {
            cout << "\t\t\t" << i + 1 << ". " << boughtProduct[i] << "\t\t\t\t" << buyQuantity[i] << endl;
        }
    }
    getch();
}
void sellProducts(string selledProducts[], int selledQuantity[], int sellCount)
{
    printHeader();
    SetConsoleTextAttribute(h, 12);
    cout << "P R O D U C T S   S E L L E D" << endl;
    if (sellCount <= 0)
    {
        cout << "Not selled anything yet.";
    }
    else
    {
        SetConsoleTextAttribute(h, 10);
        cout << "\t\t\t\t"
             << "Product Names"
             << "\t\t\t"
             << "Quantity" << endl;
        SetConsoleTextAttribute(h, 6);
        for (int i = 0; i < sellCount; i++)
        {
            cout << "\t\t\t" << i + 1 << ". " << selledProducts[i] << "\t\t\t\t" << selledQuantity[i] << endl;
        }
    }
    getch();
}
void changeProduct(string boughtProduct[], int buyQuantity[], int buyCount)
{
    cout << "Bought Products...." << endl;
    cartProducts(boughtProduct, buyQuantity, buyCount);
}
void viewFeedback(string customer[], string customerRole[], int number, string Feedback[], int count)
{
    SetConsoleTextAttribute(h, 12);
    cout << "C U S T O M E R   F E E D B A C K" << endl;
    cout << "\t"
         << "Customers Feedback...." << endl;
    SetConsoleTextAttribute(h, 10);
    cout << "\t\t\t"
         << "Customer Names"
         << "\t\t"
         << "Feedback" << endl;
    SetConsoleTextAttribute(h, 6);
    for (int i = 0; i < count; i++)
    {
        if (customerRole[i] == "Dealer")
        {
            continue;
        }

        if (Feedback[i] == "")
        {
            Feedback[i] = "No Feedback Yet.";
        }
        else
        {
            cout << "\t\t\t" << customer[i] << "\t\t\t" << Feedback[i] << endl;
        }
    }
}
void customerBill(string customerName[], string boughtProducts[], int buyQuantity[], float totalBill[], int number, int buyCount)
{
    printHeader();
    SetConsoleTextAttribute(h, 4);
    cout << "C U S T O M E R   B I L L >>" << endl
         << endl;
    cout << "\t\t\t\t"
         << "\t\t"
         << "Customer Name: " << customerName[number] << endl;
    SetConsoleTextAttribute(h, 10);
    cout << "\t\t\t"
         << "Product Name"
         << "\t\t"
         << "Quantity" << endl;
    SetConsoleTextAttribute(h, 6);
    for (int i = 0; i < buyCount; i++)
    {
        cout << "\t\t\t" << boughtProducts[i] << "\t\t\t" << buyQuantity[i] << endl;
    }
    SetConsoleTextAttribute(h, 3);
    cout << "\n\n\n"
         << "\t\t"
         << "Total Bill........" << totalBill[number];
}
bool checkInteger(string value)
{

    for (int i = 0; value[i] != '\0'; i++)
    {
        if (value[i] < '0' || value[i] > '9')
        {
            return false;
        }
    }
    return true;
}
bool checkFloat(string value)
{
    int count = 0;
    int wrong = 0;

    for (int i = 0; value[i] != '\0'; i++)
    {
        if (value[i] < '0' || value[i] > '9' || value[i] == 'i')
        {
            wrong++;
        }
        if (value[i] == '.')
        {
            count++;
        }
    }
    if (count <= 1 && wrong == (0 + count))
    {
        return true;
    }
    else
    {
        return false;
    }
    // for (int i = 0; value[i] != '\0'; i++)
    // {

    //     if ((value[i] >= '0' && value[i] <= '9'))
    //     {
    //             digits++;
    //     }
    // }
    // if (count<=1 && digits<=(value.length()-1))
    // {

    // }
    // else{
    //     return false;
    // }
}
bool checkString(string name)
{
    int wrong = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || (name[i] >= '0' && name[i] <= '9') || (name[i] == '_')))
        {
            wrong++;
            break;
        }
    }
    if ((name.length() < 4) || wrong >= 1 || name[0] =='\0')
    {
        return false;
    }

    return true;
}
bool checkPassword(string password)
{
    int value = 1;
    int Uppercase = 0;
    int spacecase = 0;
    for (int i = 0; password[i] != '\0'; i++)
    {
        if (!((password[i] >= 'a' && password[i] <= 'z') || (password[i] >= 'A' && password[i] <= 'Z') || (password[i] >= '0' && password[i] <= '9') || (password[i] == '_')))
        {
            value--;
        }
        if ((password[i] >= 'A' && password[i] <= 'Z'))
        {
            Uppercase++;
        }
        if ((password[i] ==' '))
        {
            spacecase++;
        }
    }
    if ((value < 1) || (Uppercase < 1) || (password.length() < 8 )|| (Uppercase < 1) || password[0] =='\0')
    {
        return false;
    }
    return true;
}
void storeData(string path,string array[],string array2[],string array3[],int count){
 fstream file;
 file.open(path,ios::out);
 for (int i = 0; i<count; i++)
 {
    // cout<<array[i]<<","<<array2[i]<<","<<array3[i]<<","<<endl;
    // cout<<count;
    file<<array[i]<<","<<array2[i]<<","<<array3[i]<<","<<endl;
 } 
 getch();
 file.close();
}
int readData(string path,string array[],string array2[],string array3[],int &count){
 fstream file;
 string record;
 int Iteraions=0;
//  int value=0;
 file.open(path,ios::in);
 while(getline(file,record))
 {
 int commaCount=1;
 
 for (int i = 0; record[i]!='\0'; i++)
 {
    if (record[i]==',')
    {
        commaCount++;
    }
    else if(commaCount==1)
    {
        array[count]+=record[i];
    } 
    else if(commaCount==2)
    {
        array2[count]+=record[i];
    } 
    else if(commaCount==3)
    {
        array3[count]+=record[i];
    }   
 } 
//  value++;
 count++;
 Iteraions++;
 }
 file.close();
 return Iteraions;
} 
string getData(string line,int no){

int comma=1;
string value="";
    for(int i=0;i<line.length();i++){
       if (line[i]==',')
       {
        comma++;
       }
       else if (comma==no)
       {
         value+=line[i];
       } 
    }
    return value;
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
int ShowMenu(vector<string> &optionList)
{
    int option = 0;
    while (true)
    {
        for (int i = 0; i < optionList.size(); i++)
        {
            if (option == i)
            {
                Color(121);
                gotoxy(45, 13 + i);
                cout << "  " << optionList[i] << "      ";
                Color(7);
            }
            else
            {
                gotoxy(45, 13 + i);
                cout << "    " << optionList[i] << "        ";
            }
        }
        if (GetAsyncKeyState(VK_UP))
        {
            if (option == 0)
            {
                option = optionList.size() - 1;
            }
            else
            {
                option = option - 1;
            }
        }
        else if (GetAsyncKeyState(VK_DOWN))
        {
            if (option == optionList.size() - 1)
            {
                option = 0;
            }
            else
            {
                option = option + 1;
            }
        }
        else if (GetAsyncKeyState(VK_SPACE)) // space
        {
            return option;
        }
        Sleep(200);
         }
    }

void Color(int color)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void hideAndVisibleCursor(bool isShow)
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = isShow;
    SetConsoleCursorInfo(consoleHandle, &info);
}
