// Raycaster_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>
#include<C:\Users\ocjla\source\repos\Raycaster_2\Raycaster_2\Enviroment.cpp>
#include<C:\Users\ocjla\source\repos\Raycaster_2\Raycaster_2\Renderer.cpp>
int main()
{
	auto viewport = ViewPort();
	auto enviroment = map.getMap();
	auto rays = viewport.castRays(enviroment);
	std::cout << "\n hit rays = " << rays.size() << "\n";
	auto screen = viewport.render(rays);
	std::cout << screen;
}
