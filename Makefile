output: main.o Armour.o Character.o Enemy.o EnemyFactory.o FriendlyNPC.o Game.o GaveOverState.o TitleScreenState.o PauseState.o Player.o State.o

Armour.o: Armour.cpp
	g++ -Iheaders -Itextures -Ic:SFML/include -c Armour.cpps

Character.o: characters_cpp/Character.cpp
	g++ -c Character.cpp

Enemy.o: characters_cpp/Enemy.cpp
	g++ -c Enemy.cpp

EnemyFactory.o: characters_cpp/EnemyFactory.cpp
	g++ -c EnemyFactory.cpp

FriendlyNPC.o: characters_cpp/FriendlyNPC.cpp
	g++ -c FriendlyNPC.cpp

Game.o: Game.cpp
	g++ -c Game.cpp

GaveOverState.o: states/GameOverState.cpp
	g++ -c GameOverState.cpp

TitleScreenState.o: states/TitleScreenState.cpp
	g++ -c TitleScreenState

PauseState.o: states/PauseState.cpp
	g++ -c PauseScreenState

State.o: states/State.cpp
	g++ -c State.cpp

Player.o: characters_cpp/Player.cpp
	g++ -c Player.cpp

