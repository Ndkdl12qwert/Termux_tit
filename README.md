cat > README.md << 'EOF'
# tit - Termux Tools InsTall

A lightweight CLI tool for installing/uninstalling APKs in Termux,
especially when using ADB or shell environments.

## Features
- Auto-detects runtime environment: ADB shell, Termux+ADB, root, or limited
- `tit install app.apk` → uses `pm` (on-device) or `adb` (from host) automatically
- `tit uninstall com.example.app`
- Written in C++17, no external dependencies
- GPLv3+ licensed

## Build & Install (in Termux)
```bash
pkg install clang make
git clone https://.../tit.git   # or manually create
cd tit
make
make install
```

## Usage
```bash
    tit install <your Table of Contents/yourapk.apk>
    tit uninstall com.your_app name
    tit devices
    tit help
```

## License
GPLv3+ — see [LICENSE](https://www.qianwen.com/chat/LICENSE)
SPDX-License-Identifier: GPL-3.0-or-later