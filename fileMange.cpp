#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    int choice;
    string filename, source, destination;

    while (true) {
        cout << "\n===== File Management Menu =====\n";
        cout << "1. Create File\n";
        cout << "2. Delete File\n";
        cout << "3. Copy File\n";
        cout << "4. Move File\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // flush newline

        switch (choice) {
            case 1:
                cout << "Enter filename to create: ";
                getline(cin, filename);
                system(("touch " + filename).c_str());
                cout << "File created.\n";
                break;

            case 2:
                cout << "Enter filename to delete: ";
                getline(cin, filename);
                system(("rm " + filename).c_str());
                cout << "File deleted.\n";
                break;

            case 3:
                cout << "Enter source filename: ";
                getline(cin, source);
                cout << "Enter destination filename: ";
                getline(cin, destination);
                system(("cp " + source + " " + destination).c_str());
                cout << "File copied.\n";
                break;

            case 4:
                cout << "Enter filename to move: ";
                getline(cin, source);
                cout << "Enter new location/filename: ";
                getline(cin, destination);
                system(("mv " + source + " " + destination).c_str());
                cout << "File moved.\n";
                break;

            case 5:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
