#include <iostream>
#include <Windows.h>
const int COUNT_TURLTES = 10;
volatile char png[COUNT_TURLTES] = { '0','1', '2', '3', '4', '5', '6', '7', '8', '9' };
volatile char track[50] = "------------------------------------------------";
HANDLE turtles[COUNT_TURLTES];
DWORD TurtleIDs[COUNT_TURLTES];
int turtlefinish = 0, winner = -1;
void turtle(LPVOID IDTurtle) {
	int index = (int)IDTurtle, i = 0;
	srand((int)IDTurtle);
	while (i < 50) {
		int step = rand() % 3, speed = rand() % 1000;
		if (i >= 0 && i < 50) { track[i] = '-'; track[i + step] = png[index]; }
		i += step;
		Sleep(speed);
	}
	turtlefinish++;
	if (turtlefinish == 1) winner = (int)IDTurtle + 1;
}
int main() {
	for (int i = 0; i < COUNT_TURLTES; i++) turtles[i] = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)turtle, (void*)i, 0, (TurtleIDs + i));
	while (turtlefinish != COUNT_TURLTES) {
		for (int i = 0; i < 50; i++) std::cout << track[i];
		Sleep(3000);
		system("cls");
	}
	system("cls");
	std::cout << "Winner: " << winner << std::endl;
}