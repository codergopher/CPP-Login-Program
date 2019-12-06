#include <iostream>
#include <fstream>

using namespace std;

class LoginManager
{
public:
    LoginManager()
    {

        accessGranted = 0;
    }

    void login()
    {
        cout << "Hey you need to enter your password and user.\nUsername:";
        cin >> userNameAttempt;

        userName = getFile("users.dat");
        if(userNameAttempt == userName)
        {
            cout << "Password:";
            cin >> passWordAttempt;

            passWord = getFile("pswds.dat");

            if(passWordAttempt == passWord)
            {
                cout << "Hey, that's right.";
                cin.get();
            }
            else
            {
                cout << "Not even close." << endl;
                login();
            }
        }
        else
        {
            cout << "Nice try, bud." << endl;
            login();
        }
    }
    string getFile(const char* p_fileName)
    {
        string line;
        fstream file;

        file.open(p_fileName, ios::in);
        if(file.is_open())
        {
            getline(file, line);
        }
        file.close();

        return line;
    }
private:
    string passWord = "easypassword";
    string userName = "user@email.com";
    string userNameAttempt;
    string passWordAttempt;
    bool accessGranted;
};

int main()
{
    LoginManager loginManagerObj;
    loginManagerObj.login();
}