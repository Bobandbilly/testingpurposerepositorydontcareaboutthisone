#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string filename;
    std::cout << "Enter filename to create/edit: ";
    std::getline(std::cin, filename);

    std::ofstream file(filename, std::ios::app); // Opens in append mode

    if (!file) {
        std::cerr << "Error opening file!\n";
        return 1;
    }

    std::cout << "Start typing (type '::exit' on a new line to save and quit):\n";

    std::string line;
    while (true) {
        std::getline(std::cin, line);
        if (line == "::exit") break;
        file << line << std::endl;
    }

    file.close();
    std::cout << "File saved successfully as " << filename << "\n";

    return 0;
}