#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
    string command = argv[1];
    string input;
    string output;

    for (int i=2;i<argc;i++) {
        input += argv[i];
        if (i != argc-1) {
            input += " ";
        }
    }

    for (int i=0;i<input.size();i++) {
        char c = input[i];

        if (command == "up") {
            if ('a' <= c && c <= 'z') {
                input[i] = c - 'a' + 'A';
            }
        }

        else if (command == "down") {
            if ('A' <= c && c <= 'Z') {
                input[i] = c - 'A' + 'a';
            }
        }
    }

    cout << input << endl;

    return 0;

}