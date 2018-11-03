# MasterMind Board Game in C++

This Master Mind Board Game uses the MVC Architecture, Observer and State Design Patterns.

For Complete High Level and Low Level design of code go to, please refer to the [related blog post]( http://thispointer.com/designing-a-board-game-mastermind-in-c-using-mvc-state-and-observer-design-patterns/).

## Usage

On a Mac please install XCode and run `xcode-select -install` on the command line.

It might be also helpful to install a recent `gcc` compiler with `brew install gcc`.

### Compiling the Game

```bash
$ git clone https://github.com/VarunAtThisPointer/boardgame-mastermind mastermind
$ cd mastermind

# In the make command below, we specify the number of cores to use with 
# -j 12 flag to make. If your system has less cores, use a smaller number, eg 4.
$ make -j 12
g++ -O3 -c -o src/Model/Board.o src/Model/Board.cpp --std=c++14 -I./include
g++ -O3 -c -o src/Model/GameModel.o src/Model/GameModel.cpp --std=c++14 -I./include
g++ -O3 -c -o src/Model/Peg.o src/Model/Peg.cpp --std=c++14 -I./include
g++ -O3 -c -o src/Model/PegRow.o src/Model/PegRow.cpp --std=c++14 -I./include
g++ -O3 -c -o src/Model/Subject.o src/Model/Subject.cpp --std=c++14 -I./include
g++ -O3 -c -o src/Controller/GameController.o src/Controller/GameController.cpp --std=c++14 -I./include
g++ -O3 -c -o src/Controller/GameEndedStateHandler.o src/Controller/GameEndedStateHandler.cpp --std=c++14 -I./include
g++ -O3 -c -o src/Controller/GameInProgressHandler.o src/Controller/GameInProgressHandler.cpp --std=c++14 -I./include
g++ -O3 -c -o src/Controller/GameStateHandler.o src/Controller/GameStateHandler.cpp --std=c++14 -I./include
g++ -O3 -c -o src/Controller/HelpStateHandler.o src/Controller/HelpStateHandler.cpp --std=c++14 -I./include
g++ -O3 -c -o src/Controller/MainMenuStateHandler.o src/Controller/MainMenuStateHandler.cpp --std=c++14 -I./include
g++ -O3 -c -o src/View/EndScene.o src/View/EndScene.cpp --std=c++14 -I./include
g++ -O3 -c -o src/View/GameScene.o src/View/GameScene.cpp --std=c++14 -I./include
g++ -O3 -c -o src/View/GameView.o src/View/GameView.cpp --std=c++14 -I./include
g++ -O3 -c -o src/View/HelpScene.o src/View/HelpScene.cpp --std=c++14 -I./include
g++ -O3 -c -o src/View/MainMenuScene.o src/View/MainMenuScene.cpp --std=c++14 -I./include
g++ -O3 -c -o src/View/Observer.o src/View/Observer.cpp --std=c++14 -I./include
g++ -O3 -c -o src/View/Scene.o src/View/Scene.cpp --std=c++14 -I./include
g++ -O3 -c -o src/main.o src/main.cpp --std=c++14 -I./include
mkdir -p bin
g++ -o bin/mastermind src/Model/Board.o src/Model/GameModel.o src/Model/Peg.o \
    src/Model/PegRow.o src/Model/Subject.o src/Controller/GameController.o \
    src/Controller/GameEndedStateHandler.o src/Controller/GameInProgressHandler.o\
    src/Controller/GameStateHandler.o src/Controller/HelpStateHandler.o\
    src/Controller/MainMenuStateHandler.o src/View/EndScene.o src/View/GameScene.o \
    src/View/GameView.o src/View/HelpScene.o src/View/MainMenuScene.o \
    src/View/Observer.o src/View/Scene.o src/main.o --std=c++14 -I./include
```

### Running the Game

```bash
$ ./bin/mastermind
```

### Cleaning Up

To remove any object files, run:

```bash
$ make clean
```



