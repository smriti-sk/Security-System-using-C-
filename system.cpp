#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int option, i=0;
    string text, old, password1, password2, pass, usrname, password0, age, user, word, word1;
    string creds[2], cp[2];

    cout<<"\n         Security System         "<<endl<<endl;
    cout<<"__________________________________"<<endl;
    cout<<"|        1. Register              |"<<endl;
    cout<<"|        2. Login                 |"<<endl;
    cout<<"|        3. Change Password       |"<<endl;
    cout<<"|        4. Exit                  |"<<endl;
    cout<<"|_________________________________|"<<endl;

    do{
        cout<<"\n\nEnter your choice: "<<endl;
        cin>>option;
        cout<<endl;

        switch (option) {
            case 1: {
            cout<<" _________________________________"<<endl;
            cout<<"|            Register             |"<<endl;
            cout<<"|_________________________________|"<<endl;
            cout<<"\nPlease enter username: ";
            cin>>usrname;
            cout<<"\nPlease enter your password: ";
            cin>>password0;
            cout<<"\nPlease enter your age: ";
            cin>>age;

            ofstream of1; //to write in the file
            of1.open("file.txt"); //open the file
            if (of1.is_open()){ //till the file is open
                of1<<usrname<<"\n"  //write in the file
                <<password0;
                cout<<"Registration successful!";
            }
            break;
            }

            case 2:{
                cout<<" _________________________________"<<endl;
                cout<<"|              Login              |"<<endl;
                cout<<"|_________________________________|"<<endl;

                ifstream of2; // to read the file
                of2.open("file.txt"); //open the file

                cout<<"\nPlease enter username: ";
                cin>>user;
                cout<<"\nPlease enter your password: ";
                cin>>pass;

                if (of2.is_open()){ //check all the file
                    while(!of2.eof()) {     //from 'eof()' function we can detect when the end of file is reached.
                        while(getline(of2,text)){
                            istringstream iss(text);
                            iss>>word; //storing the string using extraction operator
                            creds[i] = word; 
                            i++;
                            //creds[0] -> user name; cred[1] -> password
                        }
                        if(user == creds[0] && pass == creds[1]) { 
                            cout<<"\n***Log in successful!***\n"<<endl;
                            cout<<"Details:"<<endl;
                            cout<<"Username: "<<usrname<<endl;
                            cout<<"Password: "<<pass<<endl;
                            cout<<"Age: "<<age;
                        }

                        else {
                            cout<<"Incorrect credentials.\n"<<endl;
                            cout<<"1.   Press 2 to log in"<<endl;
                            cout<<"2.   Press 3 to change password"<<endl;
                            break;
                        }    
                    }

                }
                break;
            }

            case 3: {
                i=0;
                cout<<" _________________________________"<<endl;
                cout<<"|         Change password         |"<<endl;
                cout<<"|_________________________________|"<<endl;
                
                ifstream of0;
                of0.open("file.txt");
                cout<<"\nEnter the old password: ";
                cin>>old;
                if (of0.is_open()){
                    while(!of0.eof()){
                        while(getline(of0, text)){
                            istringstream iss(text);
                            iss>>word1;
                            cp[i]=word1;
                            i++;

                            cout<<"DEBUG00"<<endl;
                            //cp[0] -> username; cp[1] -> password
                        }
                            cout<<"DEBUG11"<<endl;

                        if (old ==cp[1]) {
                            of0.close();
                            cout<<"DEBUG"<<endl;
                            ofstream of1;
                            of1.open("file.txt");
                            if (of1.is_open()){
                                cout<<"Enter your new password: ";
                                cin>>password1;
                                cout<<"Enter your password again: ";
                                cin>>password2;

                                if (password1 == password2){
                                    of1<<cp[0]<<"\n"
                                    <<cp[1];
                                    cout<<"\nPassowrd changed successfully.\n"<<endl;
                                }
                                else {
                                    of1<<cp[0]<<"\n"
                                    <<old;
                                    cout<<"Password do not match"<<endl;
                                }
                            }
                            else{
                                cout<<"Please enter a valid password"<<endl;
                                break;
                            }
                        }
                    }
                }
            }

            case 4:{
                cout<<"_____________THANK YOU!_____________\n"<<endl;
                break;
            }
            default: {
                cout<<"Enter a valid choice."<<endl;
            }
        }
    } while(option!=4);
    return 0;
}
