#include<SDL.h>
#include<iostream>

using namespace std;

int main()
{
	int v = SDL_Init(SDL_INIT_EVERYTHING);
	cout << ("%d", v);

	return 1;
}
