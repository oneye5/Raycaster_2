// Raycaster_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
#include<vector>
#include<C:\Users\ocjla\source\repos\Raycaster_2\Raycaster_2\Enviroment.cpp>
#include<C:\Users\ocjla\source\repos\Raycaster_2\Raycaster_2\Renderer.cpp>
int main()
{
	auto viewPort = ViewPort();
	auto rays = viewPort.castRays(map.getMap());
	std::cout << viewPort.render(rays);
	std::cout << "\n" << "rays: " << rays.size();
	for (int i = 0; i < rays.size(); i++)
	{
		std::cout << "\n angle: " << rays[i].angle << " char: " << rays[i].charHit << " dist: " << rays[i].distance << " hit: " << rays[i].hit;
	}
	
}
