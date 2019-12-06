#include <iostream>
#include <fstream>
#include <math.h>

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


        if(checkFile(userNameAttempt, "users.dat"))
        {
            cout << "Password:";
            cin >> passwordAttempt;

            if(checkFile(passwordAttempt, "pswds.dat"))
            {
                cout << "Hey, thats right. \n" << endl;;
                login();

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
    bool checkFile(string attempt, const char* p_fileName)
    {
        string line;
        fstream file;

        long long eChar;

        file.open(p_fileName, ios::in);
        
        while(1)
        {
            file >> eChar;
            if(eChar == 0)
            {
                if(attempt == line)
                {
                    file.close();
                    return true;
                }
                else
                {
                    line.erase(line.begin(), line.end());
                }
            }
            else
            {
                line += (char)decrypt(eChar);
            }

            if(file.peek() == EOF)
            {
                file.close();
                return false;
            }
        }
    }

    void saveFile(string p_line, const char* p_fileName)
    {
        fstream file;
        file.open(p_fileName, ios::app);

        for(int i = 0; i < p_line.length(); i++)
        {
            file << encrypt(p_line[i]);
            file << "\n";
        }

        file << "0 \n";
        file.close();
    }

    long long encrypt(int p_letter)
    {
        return powf(p_letter, 5) * 4 - 14;
    }
    int decrypt(long long p_letter)
    {
        return powf((p_letter + 14) / 4, 1/5.f);
    }

private:
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