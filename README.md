# Nixver
Winver for GNU/Linux

Written in Qt and C++

INSTALLATION (FROM SOURCE)
```
git clone https://github.com/aoh-t/Nixver.git
cd Nixver
qmake # generates makefile
make
```
IF RECOMPILING
```
cd Nixver
uic Qt.ui -o ui_Qt.h # only if you edited the ui file
make clean
make
```
