#include "tit.hpp"
#include <iostream>

void handle_install(const std::vector<std::string>& args) {
    if (args.size() != 1) {
        throw std::invalid_argument("Usage: tit install <apk_file>");
    }
    std::string apk = args[0];
    if (!file_exists(apk)) {
        throw std::runtime_error("APK file not found: " + apk);
    }

    RuntimeMode mode = detect_runtime_mode();
    std::string cmd;

    switch (mode) {
        case RuntimeMode::ADB_SHELL:
        case RuntimeMode::ROOT:
            cmd = "pm install -r " + apk;
            break;
        case RuntimeMode::TERMUX_ADB:
            cmd = "adb install " + apk;
            break;
        default:
            throw std::runtime_error(
                "Cannot install APK: please connect ADB or use 'adb shell'"
            );
    }

    std::cout << "[tit] Running: " << cmd << "\n";
    run_command(cmd);
    std::cout << "[tit] Done.\n";
}

void handle_uninstall(const std::vector<std::string>& args) {
    if (args.size() != 1) {
        throw std::invalid_argument("Usage: tit uninstall <package_name>");
    }
    std::string pkg = args[0];

    RuntimeMode mode = detect_runtime_mode();
    std::string cmd;

    switch (mode) {
        case RuntimeMode::ADB_SHELL:
        case RuntimeMode::ROOT:
            cmd = "pm uninstall " + pkg;
            break;
        case RuntimeMode::TERMUX_ADB:
            cmd = "adb uninstall " + pkg;
            break;
        default:
            throw std::runtime_error(
                "Uninstall requires ADB or root access"
            );
    }

    std::cout << "[tit] Running: " << cmd << "\n";
    run_command(cmd);
    std::cout << "[tit] Done.\n";
}

void handle_devices() {
    try {
        std::string out = run_command("adb devices");
        std::cout << out;
    } catch (...) {
        std::cout << "adb not found or not connected.\n";
    }
}
