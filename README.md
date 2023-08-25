
# Ludo 

A third semester project on Object Oriented Programming made by Computer Engineering students of IOE Pulchowk Campus.
## Contributors

- [Bishal Lamichhane](https://www.github.com/bishallamichhane44) (078BCT035)
- [Bipin Bashyal](https://www.github.com/bipinbashyal) (078BCT033)
- [Ayush KC](https://www.github.com/AyusK4) (078BCT025)



## Screenshots

![Logo](https://github.com/bishallamichhane44/ludo/blob/master/assets/Frame_2.png?raw=true)

![Logo](https://github.com/bishallamichhane44/ludo/blob/master/assets/screenshot.PNG)









## Documentation 

- [Project Reoprt](https://linktodocumentation)
- [Presentation ](https://linktodocumentation)



## Build

### Requirements:
To setup and use the project, you will need to download the following:
- [SFML](https://www.sfml-dev.org/files/SFML-2.6.0-windows-gcc-13.1.0-mingw-32-bit.zip)
- [MINGW](https://github.com/brechtsanders/winlibs_mingw/releases/download/13.1.0-16.0.5-11.0.0-msvcrt-r5/winlibs-i686-posix-dwarf-gcc-13.1.0-mingw-w64msvcrt-11.0.0-r5.7z)

Cut MinGW and SFML-2.6.0 folder and paste in your C: drive.
Add path to environment variables for:
- **bin** from MinGW folder
- **bin** form SFML-2.6.0 folder


### Installation:
- Clone the repository.
```bash
  $ git clone https://github.com/bishallamichhane44/ludo.git
```
- Change the working directory to newly cloned directory.
```bash
  $ cd ludo
```
- Use the following build commnads.
```bash
  $ g++ -IC:\SFML-2.6.0\include -c main.cpp -o main.o
```
```bash
  $ g++ -LC:\SFML-2.6.0\lib .\main.o -o main.exe -lmingw32 -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lsfml-main -mwindows
```
```bash
  $ main.exe
```
- Alternative option for step 3:
  + Double click o.bat.
  + Double click exe.bat.
  + Main.exe will appear.(Open it to play the game).


> [!NOTE]
> If you want to just play the game without any hassle then just clone the repo and open main.exe.





