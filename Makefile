CXXFLAGS = -Isrc/include -std=c++0x
LXXFLAGS = -Lsrc/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

output: main.o mario.o player.o idleState.o movingState.o fallingState.o level.o block.o entity.o collitionSystem.o jumpState.o interactiveBlock.o blockIdleState.o blockBouncingState.o solidBlock.o
	g++ main.o mario.o player.o idleState.o movingState.o fallingState.o level.o block.o entity.o collitionSystem.o jumpState.o interactiveBlock.o blockIdleState.o blockBouncingState.o solidBlock.o -o output $(LXXFLAGS) 

main.o: src/main.cpp 
	g++ src/main.cpp -c $(CXXFLAGS) 

mario.o: src/mario.cpp src/mario.h
	g++ -c src/mario.cpp $(CXXFLAGS)

player.o: src/player.cpp src/player.h
	g++ -c src/player.cpp $(CXXFLAGS)

idleState.o: src/idleState.cpp src/idleState.h
	g++ -c src/idleState.cpp $(CXXFLAGS)

movingState.o: src/movingState.cpp src/movingState.h
	g++ -c src/movingState.cpp $(CXXFLAGS)

fallingState.o: src/fallingState.cpp src/fallingState.h
	g++ -c src/fallingState.cpp $(CXXFLAGS)

jumpState.o: src/jumpState.cpp src/jumpState.h
	g++ -c src/jumpState.cpp $(CXXFLAGS)

level.o: src/level.cpp src/level.h
	g++ -c src/level.cpp $(CXXFLAGS)

block.o: src/block.cpp src/block.h
	g++ -c src/block.cpp $(CXXFLAGS)

entity.o: src/entity.cpp src/entity.h
	g++ -c src/entity.cpp $(CXXFLAGS)

collitionSystem.o: src/collitionSystem.cpp src/collitionSystem.h
	g++ -c src/collitionSystem.cpp $(CXXFLAGS)

interactiveBlock.o: src/interactiveBlock.cpp src/interactiveBlock.h
	g++ -c src/interactiveBlock.cpp $(CXXFLAGS)

blockIdleState.o: src/blockIdleState.cpp src/blockIdleState.h
	g++ -c src/blockIdleState.cpp $(CXXFLAGS)

blockBouncingState.o: src/blockBouncingState.cpp src/blockBouncingState.h
	g++ -c src/blockBouncingState.cpp $(CXXFLAGS)

solidBlock.o: src/solidBlock.cpp src/solidBlock.h
	g++ -c src/solidBlock.cpp $(CXXFLAGS)