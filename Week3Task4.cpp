#include <iostream>
#include <map>
#include <string>
using namespace std;

class ThemesHMI {
    string backgroundColor;
    string fontColor;
    int fontSize;
    string iconStyle;
public:
    ThemesHMI() : backgroundColor("Black"), fontColor("White"), fontSize(20), iconStyle("Arial") {}
    ThemesHMI(string bgColor,
    string fntColor,
    int fntSize,
    string icnStyle):backgroundColor(bgColor),fontColor(fntColor),fontSize(fntSize),iconStyle(icnStyle){}

    void display() {
        cout << "BackGround Color : " << backgroundColor;
        cout << "\nFont Color : " << fontColor;
        cout << "\nFont Size : " << fontSize;
        cout << "\nIcon Style : " << iconStyle;
    }
};

int main() {
    map<string, ThemesHMI> themes = {
        {"Classic",ThemesHMI("Black","Blue",22,"Times New ROman")},
        {"Sports",ThemesHMI("Sky Blue","Red",20,"Arial")},
        {"Eco",ThemesHMI("Purple","White",24,"Sarif")}
    };
    cout << "Welcome...\n";
    int choice;
    string cho;
    while (true) {
        cout << "Choose a theme for you...\n1 -> Classic\n2 -> Sports\n3 -> Eco\nEnter 0 for exit...\n";
        cin >> choice;
        if (choice == 0) {
            break;
        }
        switch (choice) {
        case 1:
            cho = "Classic";
            if (themes.find(cho) != themes.end()) {
                themes[cho].display();
            }
            break;
        case 2:
            cho = "Sports";
            if (themes.find(cho) != themes.end()) {
                themes[cho].display();
            }
            break;
        case 3:
            cho = "Eco";
            if (themes.find(cho) != themes.end()) {
                themes[cho].display();
            }
            break;
        default:
            cout << "invalid option... Please Try again..\n";
            continue;
        }
    }
}