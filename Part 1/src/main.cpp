#include <iostream>

using namespace std;

class LoginManager{
     public:
         string userNameAttempt;
         string passWordAttempt;

         LoginManager(){

            accessGranted = 0;
         }

         void login(){
             cout << "Hey you need to enter your password and user.\nUsername:";
             cin >> userNameAttempt;
             if(userNameAttempt==userName){
                cout << "Password:";
                cin >> passWordAttempt;

                if(passWordAttempt==passWord){

                    cout << "Hey, that's right.";
                }
            }
        }
    private:
        string passWord = "easypassword";
        string userName = "user@email.com";
        bool accessGranted;
};

int main()
{
    LoginManager loginManagerObj;
    loginManagerObj.login();
}