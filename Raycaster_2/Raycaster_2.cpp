// Raycaster_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>  
#include<string>
#include<vector>
#include<C:\Users\ocjla\source\repos\Raycaster_2\Raycaster_2\Enviroment.cpp>
#include<C:\Users\ocjla\source\repos\Raycaster_2\Raycaster_2\Renderer.cpp>
int main()
{
	class Player
	{
	public:
		void input(ViewPort& viewport)
		{
			float multi = 0.25;
		 int xchange = 0;
		 int ychange = 0;
		 int achange = 0;
		 if (GetKeyState('D') < 0)
		 {
			 xchange--;
		 }
		 if (GetKeyState('A') < 0)
		 {
			 xchange++;
		 }
		 if (GetKeyState('W') < 0)
		 {
			 ychange++;
		 }
		 if (GetKeyState('S') < 0)
		 {
			 ychange--;
		 }
		 if (GetKeyState(VK_LEFT) < 0)
		 {
			 achange++;
		 }if (GetKeyState(VK_RIGHT) < 0)
		 {
			 achange--;
		 }
		 viewport. CameraPosX += sin(viewport.CameraAngle * 0.0174533) * ychange * multi;
		 viewport.CameraPosY +=  cos(viewport.CameraAngle * 0.0174533) * ychange * multi;

		 viewport.CameraPosX += sin((viewport.CameraAngle * 0.0174533) + 90) * xchange * multi;
		 viewport.CameraPosY += cos((viewport.CameraAngle * 0.0174533) + 90) * xchange * multi;

		 viewport.CameraAngle += achange * multi * 15;
		}
	};
	bool running = true;
	auto viewport = ViewPort();
	auto player = Player();
	 do
	 { 
		 if (GetKeyState('E') < 0)
		 {
			 viewport.Fov--;
		 }
		 if (GetKeyState('Q') < 0)
		 {
			 viewport.Fov++;
		 }
		 if (GetKeyState('R') < 0)
		 {
			 viewport.screenOffset += 1;
		 }
		 if (GetKeyState('T') < 0)
		 {
			 viewport.screenOffset -= 1;
		 }
		 if (GetKeyState('Y') < 0)
		 {
			 viewport.wallSize += 1;
		 }
		 if (GetKeyState('U') < 0)
		 {
			 viewport.wallSize -= 1;
		 }
		 if (GetKeyState('I') < 0)
		 {
			 viewport.RayStep += 0.05;
		 }
		 if (GetKeyState('O') < 0)
		 {
			 viewport.RayStep -= 0.05;
		 }
		 player.input(viewport);
		auto enviroment = map.getMap();
		auto rays = viewport.castRays(enviroment);
		auto screen = viewport.render(rays);
		auto blank = viewport.blankSpace();
		std::cout << blank << screen;

		//viewport.CameraAngle += 1;
		std::cout << "\n xy rot :" << viewport.CameraPosX << " " << viewport.CameraPosY << " " << viewport.CameraAngle;
		std::cout << "\nfov : " << viewport.Fov << " offset : " << viewport.screenOffset << " wallsize : " << viewport.wallSize << " raystep : " << viewport.RayStep;
		Sleep(10);
		

	 } while (running);
}
