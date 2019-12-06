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
        cout << "Ahem. A username is required. \nUsername:";
        cin >> userNameAttempt;

        userName = getFile("users.dat");

        if(userNameAttempt == userName)
        {
            cout << "Password:";
            cin >> passwordAttempt;

            passWord = getFile("pswds.dat");

            if(passwordAttempt == passWord)
            {
                cout << "Hey, thats right.";
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

        int eChar;

        file.open(p_fileName, ios::in);
        
        while(1)
        {
            file >> eChar;
            if(eChar == 0)
            {
                file.close();
                return line;
            }
            line += (char)decrypt(eChar);
        }
    }

    void saveFile(string p_line, const char* p_fileName)
    {
        fstream file;
        file.open(p_fileName, ios::out);

        for(int i = 0; i < p_line.length(); i++)
        {
            file << encrypt(p_line[i]);
            file << "\n";
        }

        file << "0";
        file.close();
    }

    int encrypt(int p_letter)
    {
        return p_letter + 3;   
    }
    int decrypt(int p_letter)
    {
        return p_letter - 3;
    }

private:
    string passWord;
    string userName;
    string userNameAttempt;
    string passwordAttempt;
    bool accessGranted;
};

int main()
{
    LoginManager app;
    app.login();

    cin.get();
}