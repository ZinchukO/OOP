#include <iostream>
#include <string>

using namespace std;

class UIElement {
protected:
    string Name;

public:
    static int count;
    UIElement(string name) {
        Name = name;
        count++;
    }
    string GetName() { return Name; }
};
int UIElement::count = 0;

class Button : public UIElement {
public:
    Button(string name) : UIElement(name) {}
};

class Checkbox : public UIElement {
public:
    Checkbox(string name) : UIElement(name) {}
};

class IGUIFactory {
public: 
    virtual Button* CreateButton() = 0;
    virtual Checkbox* CreateCheckbox() = 0;
};

class WindowsFactory : public IGUIFactory {
public:
    Button* CreateButton() override {
        return new Button("Windows Button");
    }
    Checkbox* CreateCheckbox() override {
        return new Checkbox("Windows Checkbox");
    }
};

class MacFactory : public IGUIFactory {
public:
    Button* CreateButton() override {
        return new Button("Mac Button");
    }
    Checkbox* CreateCheckbox() override {
        return new Checkbox("Mac Checkbox");
    }
};

int main() {
    
    IGUIFactory* winFactory = new WindowsFactory();
    Button* winButton = winFactory->CreateButton();
    Checkbox* winCheckbox = winFactory->CreateCheckbox();

    cout << winButton->GetName() << endl;
    cout << winCheckbox->GetName() << endl;

    IGUIFactory* macFactory = new MacFactory();
    Button* macButton = macFactory->CreateButton();
    Checkbox* macCheckbox = macFactory->CreateCheckbox();

    cout << macButton->GetName() << endl;
    cout << macCheckbox->GetName() << endl;

    cout << "Total UI elements created: " << UIElement::count << endl;

    delete winFactory;
    delete macFactory;
    delete winButton;
    delete winCheckbox;
    delete macButton;
    delete macCheckbox;

    return 0;
}
