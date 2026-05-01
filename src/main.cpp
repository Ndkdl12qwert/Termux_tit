#include "tit.hpp"
#include <iostream>
#include <vector>
#include <string>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        print_help();
        return 1;
    }

    std::string cmd = argv[1];
    std::vector<std::string> args(argv + 2, argv + argc);

    try {
        if (cmd == "install") {
            handle_install(args);
        } else if (cmd == "uninstall") {
            handle_uninstall(args);
        } else if (cmd == "devices") {
            handle_devices();
        } else if (cmd == "help" || cmd == "--help") {
            print_help();
        } else {
            std::cerr << "Unknown command: " << cmd << "\n";
            return 1;
        }
    } catch (const std::exception& e) {
        std::cerr << "[tit] Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
