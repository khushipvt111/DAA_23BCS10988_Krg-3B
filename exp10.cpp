#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> text;
    vector<vector<string>> undoStack, redoStack;
    int choice;

    do {
        cout << "\n==== Simple Text Editor ====\n";
        cout << "1. Add new line\n";
        cout << "2. Delete last line\n";
        cout << "3. Show text\n";
        cout << "4. Undo\n";
        cout << "5. Redo\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            // Save current state before modifying
            undoStack.push_back(text); // pehle ke state ko store krne ke baad hi ham change krenge 
            redoStack.clear();

            string line;
            cout << "Enter line: ";
            getline(cin, line);
            text.push_back(line);
            cout << "Line added successfully!\n";
        } 
        else if (choice == 2) {
            if (text.empty()) {
                cout << "No lines to delete!\n";
            } else {
                undoStack.push_back(text);
                redoStack.clear();

                text.pop_back();
                cout << "Last line deleted.\n";
            }
        } 
        else if (choice == 3) {
            if (text.empty()) {
                cout << "No text available.\n";
            } else {
                cout << "\n=== Current Text ===\n";
                for (int i = 0; i < (int)text.size(); i++) {
                    cout << i + 1 << ": " << text[i] << "\n";
                }
            }
        } 
        else if (choice == 4) { // Undo
            if (undoStack.empty()) {
                cout << "Nothing to undo!\n";
            } else {
                redoStack.push_back(text);
                text = undoStack.back();
                undoStack.pop_back();
                cout << "Undo successful!\n";
            }
        } 
        else if (choice == 5) { // Redo
            if (redoStack.empty()) {
                cout << "Nothing to redo!\n";
            } else {
                undoStack.push_back(text);
                text = redoStack.back();
                redoStack.pop_back();
                cout << "Redo successful!\n";
            }
        } 
        else if (choice == 6) {
            cout << "Exiting editor...\n";
        } 
        else {
            cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 6);

    return 0;
}
