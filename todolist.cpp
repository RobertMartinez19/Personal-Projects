#include <iostream>    // Include the input/output stream library.
#include <string>      // Include the string library.
#include <list>        // Include the list container from the Standard Template Library (STL).
#include <ctime>       // Include the time library for generating random numbers.
using namespace std;   // Declare that we're using the standard namespace for convenience.

class TodoItem {        // Define a class named TodoItem to represent individual to-do list items.
private:
    int id;             // An integer to store the unique ID of the to-do item.
    string description; // A string to store the description of the to-do item.
    bool completed;     // A boolean to indicate whether the to-do item is completed or not.

public:
    TodoItem(): id(0), description(""), completed(false) {} // Constructor to initialize the class members.
    ~TodoItem() = default; // Destructor, which is not explicitly defined.

    bool create(string new_description) { // Method to create a new to-do item with a description.
        id = rand() % 100 + 1; // Generate a random ID between 1 and 100.
        description = new_description; // Set the description to the provided input.
        return true; // Return true to indicate successful creation.
    }

    int getId() { return id; } // Method to get the ID of the to-do item.
    string getDescription() { return description; } // Method to get the description of the to-do item.
    bool isCompleted() { return completed; } // Method to check if the to-do item is completed.
    void setCompleted(bool val) { completed = val; } // Method to mark the to-do item as completed.
};

int main(){
    char input_option;        // A character to store the user's menu choice.
    int input_id;             // An integer to store user input for ID.
    string input_description; // A string to store user input for a new to-do item description.

    string version = "v0.2.0"; // Define the version of the to-do list.
    list<TodoItem> todoItems;  // Create a list to store to-do items.
    list<TodoItem>::iterator it; // Create an iterator for traversing the list.

    srand(time(NULL)); // Seed the random number generator with the current time.

    todoItems.clear(); // Clear any existing to-do items (although there are none initially).

    // Uncommenting these lines would create a test to-do item and add it to the list.
    //TodoItem test;
    //test.create("this is a test");
    //todoItems.push_back(test);

    while(1){ // Infinite loop to display the menu until the user decides to quit.
        system("clear"); // Clear the console screen.

        // Display the program title and version.
        cout << "To-Do List Maker - " << version << endl;
        cout << endl << endl;

        // Iterate through the list of to-do items and display their details.
        for (it = todoItems.begin(); it != todoItems.end(); it++) {
            // Determine if the item is completed and display accordingly.
            string completed = it->isCompleted() ? "done" : "not done";

            // Display the ID, description, and completion status of the to-do item.
            cout << it->getId() << " | " << it->getDescription() << " | " << completed << endl;
        }

        if(todoItems.empty()) {
            cout << "Add your first to-do!" << endl; // If the list is empty, prompt the user to add a to-do.
        }

        cout << endl << endl;
        cout << "[a]dd a new To-do" << endl; // Display the menu option to add a new to-do.
        cout << "[c]omplete a Todo" << endl; // Display the menu option to mark a to-do as completed.
        cout << "[q]uit" << endl; // Display the menu option to quit the program.

        cout << "choice: ";
        cin >> input_option; // Get the user's menu choice.

        if(input_option == 'q'){ // If the user chooses to quit, exit the program.
            cout << "Have a great day now!" << endl;
            break;
        }
        else if (input_option == 'a') { // If the user chooses to add a new to-do item.
            cout << "Add a new description: ";
            cin.clear();
            cin.ignore();

            getline(cin, input_description); // Get the user's input for the new to-do item description.

            TodoItem newItem; // Create a new TodoItem object.
            newItem.create(input_description); // Initialize it with the provided description.
            todoItems.push_back(newItem); // Add the new item to the list of to-do items.
        } 
        else if (input_option == 'c') { // If the user chooses to mark a to-do as completed.
            cout << "Enter id to mark completed: ";
            cin >> input_id;

            // Iterate through the list to find the to-do item with the matching ID.
            for (it = todoItems.begin(); it != todoItems.end(); it++) {
                if (input_id == it->getId()) {
                    it->setCompleted(true); // Mark the item as completed.
                    break; // Exit the loop since we found the item.
                }
            }
        }
    }
    
    return 0;
}
