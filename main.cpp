#include <iostream>
#include <time.h>
#include "windows.h"
#include "class.h"
using namespace std;
int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "Russian");
	field F;
	F.life();
	return 0;
}
