#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MenuItem {
public:
    string name;
    vector<MenuItem> children;

    MenuItem(string name) : name(name) {}

    void addChild(MenuItem child) {
        children.push_back(child);
    }
};

class MenuNavigation {
private:
    vector<MenuItem> menu;
    vector<MenuItem>* currentMenu;
    vector<MenuItem>* parentMenu;
    int currentSelection;

public:
    MenuNavigation(vector<MenuItem>& rootMenu) 
        : menu(rootMenu), currentMenu(&menu), parentMenu(nullptr), currentSelection(0) {}

    void displayMenu() {
        cout << "\nCurrent Menu: " << endl;
        for (int i = 0; i < currentMenu->size(); ++i) {
            cout << (i + 1) << ". " << (*currentMenu)[i].name << endl;
        }
    }

    void navigateDown() {
        if (currentMenu->size() > currentSelection && !(*currentMenu)[currentSelection].children.empty()) {
            parentMenu = currentMenu;
            currentMenu = &(*currentMenu)[currentSelection].children;
            currentSelection = 0;
        }
        else {
            cout << "No sub-menu available." << endl;
        }
    }

    void navigateUp() {
        if (parentMenu != nullptr) {
            currentMenu = parentMenu;
            parentMenu = nullptr;
            currentSelection = 0;
        } else {
            cout << "No parent menu to navigate to." << endl;
        }
    }

    void enterMenu() {
        if (currentMenu->size() > currentSelection) {
            if ((*currentMenu)[currentSelection].children.empty()) {
                cout << "Entering " << (*currentMenu)[currentSelection].name << "..." << endl;
            } else {
                navigateDown();
            }
        } else {
            cout << "Invalid selection." << endl;
        }
    }

    void handleInput(int input) {
        switch (input) {
            case 1:
                if (currentSelection < currentMenu->size() - 1)
                    currentSelection++;
                break;
            case 2:
                if (currentSelection > 0)
                    currentSelection--;
                break;
            case 3:
                enterMenu();
                break;
            case 4:
                navigateUp();
                break;
            default:
                cout << "Invalid input." << endl;
        }
    }

    int getCurrentSelection() {
        return currentSelection;
    }
};

int main() {
    MenuItem mainMenu("Main Menu");
    MenuItem settings("Settings");
    MenuItem displaySettings("Display Settings");
    MenuItem audioSettings("Audio Settings");
    MenuItem media("Media");
    MenuItem radio("Radio");
    MenuItem bluetoothAudio("Bluetooth Audio");

    settings.addChild(displaySettings);
    settings.addChild(audioSettings);
    media.addChild(radio);
    media.addChild(bluetoothAudio);
    mainMenu.addChild(settings);
    mainMenu.addChild(media);

    vector<MenuItem> menu = { mainMenu };

    MenuNavigation navigation(menu);

    int input = 0;

    while (true) {
        navigation.displayMenu();
        cout << "\nSelect option: (1: down, 2: up, 3: enter, 4: back, 0: exit) ";
        cin >> input;

        if (input == 0) {
            break;
        }

        navigation.handleInput(input);
    }

    return 0;
}
