#include <iostream>
#include <string>
using namespace std;

int main(){
    string version = "v0.1.0";
    char op;
    float num1, num2, answer;
    char finalchoice;

    while(1) {
    system("clear"); //clear the system

    cout << "Calculator " << version << endl; 

    //It allows user to enter operator
    // i.e +, -, *, /
    cout << "Do you want to +, -, *, or /: ";
    cin >> op;
    cout << endl;

    //Allows user to enter numbers
    cout << "Enter your numbers (press enter when done)" << endl;
    cin >> num1;
    cout << op << endl;
    cin >> num2;
    cout << endl << endl;


        //if user enters +
    if(op == '+'){
        answer = num1 + num2;
        cout << num1 << " + " << num2 << " = " << answer << endl;
        cin.ignore();
        cout << "Press Enter to try again or q to quit: ";
        finalchoice = cin.get();
            if(finalchoice == 'q'){ // If the user chooses to quit, exit the program.
            cout << "Have a great day now!" << endl;
            break;
        }
    }

    //if user enters -
    if(op == '-'){
        answer = num1 - num2;
        cout << num1 << " - " << num2 << " = " << answer << endl;
        cin.ignore();
        cout << "Press Enter to try again or q to quit: ";
        finalchoice = cin.get();
            if(finalchoice == 'q'){ // If the user chooses to quit, exit the program.
            cout << "Have a great day now!" << endl;
            break;
        }
    }

        //if user enters *
    if(op == '*'){
        answer = num1 * num2;
        cout << num1 << " * " << num2 << " = " << answer << endl;
        cin.ignore();
        cout << "Press Enter to try again or q to quit: ";
        finalchoice = cin.get();
            if(finalchoice == 'q'){ // If the user chooses to quit, exit the program.
            cout << "Have a great day now!" << endl;
            break;
        }
    }

    //if user enters /
    if(op == '/'){
        answer = num1 / num2;
        cout << num1 << " / " << num2 << " = " << answer << endl;
        cin.ignore();
        cout << "Press Enter to try again or q to quit: ";
        finalchoice = cin.get();
            if(finalchoice == 'q'){ // If the user chooses to quit, exit the program.
            cout << "Have a great day now!" << endl;
            break;
        }
    }

        //if user puts non-operator
    if(op != '/' && op != '*' && op != '+' && op != '-'){
        cout << "Error! operator is not correct" << endl;
        cin.ignore();
        cout << "Press Enter to try again or q to quit: ";
        finalchoice = cin.get();
            if(finalchoice == 'q'){ // If the user chooses to quit, exit the program.
            cout << "Have a great day now!" << endl;
            break;
        } else {

        }
    }
    
    
    }
    return 0;
}