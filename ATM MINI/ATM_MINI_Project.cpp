#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
using namespace std;

/*Mini Project - ATM MINI Machine
    -> check Balance
    -> cash Withdraw
    -> User Detail
    -> Update Mobile No.
*/

class atm // class atm
{
private: // private member variables
    long int account_no;
    string name;
    int PIN;
    double balance;
    string mobile_no;

public: // public member function
    // setData function
    void setData(long int account_no_a, string name_a, int PIN_a, double balance_a, string mobile_no_a)
    {
        account_no = account_no_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_no = mobile_no_a;
    }

    long int getAccountNo()
    {
        return account_no;
    }

    string getName()
    {
        return name;
    }

    int getPIN()
    {
        return PIN;
    }

    double getBalance()
    {
        return balance;
    }

    string getMobileNo()
    {
        return mobile_no;
    }

    // set Mobile No
    void setMobile(string Mob_prev, string Mob_new)
    {
        if (Mob_prev == mobile_no)
        {
            mobile_no = Mob_new;
            cout << endl
                 << "Successfully Updated Mobile No. ";
            _getch();  // _getch() by conio.h used to held the screen
        }
        else
        {
            cout << endl
                 << "Incorrect  !!! Old Mobile No. ";
            _getch();   // _getch() by conio.h used to held the screen
        }
    }

    void cashWithdraw(int amount_a)
    {
        if (amount_a > 0 && amount_a < balance)
        {
            balance -= amount_a;
            cout << endl
                 << "Please collect your cash";
            cout << endl
                 << "Available Balance : " << balance;
            _getch();
        }
    }
};

///////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int choice = 0;
    int enterPin;
    long int enterAccountNo;

    system("cls");

    // user can be stored using the file handling but here we are hardcoding the user with data
    // creating user
    vector<atm> arr;
    // --------------------
    atm user1;
    // set user Details (into onject)        (setting default data)
    user1.setData(111111, "Tim", 1111, 45000.09, "9876543210");
    arr.push_back(user1);
    // ----------------------
    atm user2;
    // set user Details (into onject)        (setting default data)
    user2.setData(222222, "Jim", 2222, 5000.09, "987654321");
    arr.push_back(user2);
    // -----------------------------
    atm user3;
    // set user Details (into onject)        (setting default data)
    user3.setData(333333, "Raj", 3333, 75000.09, "98765432");
    arr.push_back(user3);

    do
    {
        system("cls");

        cout << endl
             << "****Welcome to ATM****" << endl;
        cout << endl
             << "Enter your Account No. : ";
        cin >> enterAccountNo;

        cout << endl
             << "Enter PIN : ";
        cin >> enterPin;

        for (int i = 0; i < 3; i++)
        {
            if ((enterAccountNo == arr[i].getAccountNo()) && (enterPin == arr[i].getPIN()))
            {
                do
                {
                    int amount = 0;
                    string oldMobileNo, newMobileNo;

                    system("cls");

                    cout << endl
                         << "**** Welcome to ATM ****" << endl;
                    cout << endl
                         << "select Options : ";
                    cout << endl
                         << "1. Check Balance";
                    cout << endl
                         << "2. Cash Withdraw";
                    cout << endl
                         << "3. Show User Details";
                    cout << endl
                         << "4. Update Mobile No.";
                    cout << endl
                         << "5. Exit" << endl;
                    cout << "Option : ";
                    cin >> choice;

                    switch (choice)
                    {
                    case 1:
                        cout << endl
                             << "Your Back balance is : " << arr[i].getBalance();
                        _getch();
                        break;
                    case 2:
                        cout << endl
                             << "Enter the amount : ";
                        cin >> amount;
                        arr[i].cashWithdraw(amount);

                        break;
                    case 3:
                        cout << endl
                             << "**** User Details are :- ";
                        cout << endl
                             << "Account No : " << arr[i].getAccountNo();
                        cout << endl
                             << "Name  : " << arr[i].getName();
                        cout << endl
                             << "Balance  : " << arr[i].getBalance();
                        cout << endl
                             << "Mobile No : " << arr[i].getMobileNo();
                        _getch();
                        break;
                    case 4:
                        cout << endl
                             << "Enter Old Mobile No : ";
                        cin >> oldMobileNo;
                        cout << endl
                             << "Enter New Mobile No : ";
                        cin >> newMobileNo;

                        arr[i].setMobile(oldMobileNo, newMobileNo);
                        break;
                    case 5:
                        exit(0);

                    default:
                        cout << endl
                             << "Enter valid option!!!";
                    }
                } while (1);

                break;
            }
        }

        cout << endl << "Input Details are Invalid !!!";
        cout<<endl<< "For Try Again -> Press Enter";
        _getch();

    } while (1);

    return 0;
}
