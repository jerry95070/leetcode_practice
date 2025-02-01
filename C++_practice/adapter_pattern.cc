#include <iostream>
#include <vector>
#include <string>  
using namespace std;

class LegacyPrinter{
    public:
        void printInUppercase(const string& text){
            cout << "Printing: " << text << endl;
        }
};

class ModernComputer{
    public:
        void sendCommand(const string& command){
            cout << "Sending command: " << command << endl;
        }
};

class PrinterAdapter{
    private:
        LegacyPrinter legacyPrinter;
    public:
        void sendCommand(const string& command){
            string uppercaseCommand = command;
            for(char& c : uppercaseCommand){
                c = toupper(c);
            }
            legacyPrinter.printInUppercase(uppercaseCommand);
        }
};

int main(){
    ModernComputer computer;
    PrinterAdapter adapter;

    computer.sendCommand("Print this in lowercase");
    adapter.sendCommand("Print this in lowercase (adapted)");
    return 0;
}