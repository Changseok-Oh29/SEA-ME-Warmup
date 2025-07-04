#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Contact {
private:
    string name;
    string phone;
    string nickname;
    bool bookmarked;

public:
    Contact(string name, string phone, string nickname) : name(name), phone(phone), nickname(nickname), bookmarked(false) {}

    string getName() {
        return name;
    }
    string getPhone() {
        return phone;
    }
    string getNickname() {
        return nickname;
    }
    bool isBookmarked() {
        return bookmarked;
    }
    void setBookmarked(bool value) {
        bookmarked = value;
    }
};

class PhoneBook {
private:
    vector<Contact> contacts;
    unordered_map<string, int> phoneIndexMap;

    void refreshIndexMap() {
        phoneIndexMap.clear();
        for (int i=0;i<contacts.size();i++) {
            phoneIndexMap[contacts[i].getPhone()] = i;
        }
    }

public:
    void add() {
        string name, phone, nickname;

        cout << "Enter Name : ";
        getline(cin, name);
        cout << "Enter Phone number : ";
        getline(cin, phone);
        cout << "Enter Nickname : ";
        getline(cin, nickname);

        contacts.emplace_back(name, phone, nickname);
        phoneIndexMap[phone] = contacts.size() - 1;

        cout << "Contact added.\n";
    }

    void search() {
        if (contacts.empty()) {
            cout << "Phonebook is empty.\n";
            return;
        }

        for (int i=0;i<contacts.size();i++) {
            cout << i << ": " << contacts[i].getName() << "\n";
        }

        int index;
        cout << "Enter index to view details: ";
        cin >> index;

        if (index < 0 || index >= contacts.size()) {
            cout << "Invalid index.\n";
            return;
        }

        Contact c = contacts[index];
        cout << "Name: " << c.getName() << "\n";
        cout << "Phone: " << c.getPhone() << "\n";
        cout << "Nickname: " << c.getNickname() << "\n";

        char choice;
        cout << "Bookmark this contact? (y/n): ";
        cin >> choice;
        
        if (choice == 'y' || choice == 'Y') {
            contacts[index].setBookmarked(true);
            cout << "Contact bookmarked.\n";
        }
    }

    void remove() {
        string input;
        int choice;

        cout << "Select how to removed by : \n";
        cout << "1. Index\n";
        cout << "2. Phone number\n";
        cout << "Enter choice (1 or 2): ";
        cin >> choice;

        if (choice == 1) {
            int index;
            cout << "Enter index to remove : ";
            cin >> index;

            if (0 <= index && index < contacts.size()) {
                phoneIndexMap.erase(contacts[index].getPhone());
                contacts.erase(contacts.begin() + index);
                refreshIndexMap();
                cout << "Contact removed.\n";
            }
            else {
                cout << "Invalid index.\n";
            }
        }
        else if (choice == 2) {
            cout << "Enter phone number to remove : ";
            getline(cin, input);
            
            auto it = phoneIndexMap.find(input);
            if (it != phoneIndexMap.end()) {
                int index = it->second;
                contacts.erase(contacts.begin() + index);
                phoneIndexMap.erase(it);
                refreshIndexMap();
                cout << "Contact removed.\n";
            }
            else {
                cout << "Phone number not found.\n";
            }
        }
        else {
            cout << "invalid choice";
        }
    }

    void bookmark() {
        bool found = false;
        for (int i=0;i<contacts.size();i++) {
            if (contacts[i].isBookmarked()) {
                cout << contacts[i].getName() << " (" << contacts[i].getPhone() << ") - " << contacts[i].getNickname() << "\n";
                found = true;
            }
        }
        if (!found) {
            cout << "No bookmarked contacts.\n";
        }
    }

    void run() {
        while (true) {
            string command;
            cout << "\nCommand (ADD/SEARCH/REMOVE/BOOKMARK/EXIT): ";
            getline(cin, command);

            if (command == "ADD") {
                add();
            }
            else if (command == "SEARCH") {
                search();
            }
            else if (command == "REMOVE") {
                remove();
            }
            else if (command == "BOOKMARK") {
                bookmark();
            }
            else if (command == "EXIT") {
                cout << "Exit PhoneBook.\n";
                break;
            }
            else {
                cout << "Unknown command.\n";
            }
        }
    }
};

int main() {
    PhoneBook pb;
    pb.run();
    return 0;
}