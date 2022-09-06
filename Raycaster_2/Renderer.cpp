#include "Renderer.h"
#include<vector>
#include<string>
#include<iostream>

class ViewPort
{
#pragma region vars
public:
	int ScreenWidth = 32;
	int ScreenHeight = 32;

	float CameraPosX = 1.0f;
	float CameraPosY = 1.0f;
	float CameraAngle = 360.0f;

	float Fov = 90.0f;
	//render settings
	float RayCount = 200.0f;
	float RayStep = 0.25f;
	float RayLimit = 100.0f;
	float WallOffset = 0.0f;
	float wallSize = 4000.0f;
	class RayHit
	{
	public:
		bool hit;
		float xPos;
		float yPos;
		float distance;
		float angle;
		char charHit;
	};
#pragma endregion
	RayHit castRay(float fromX, float fromY, float angle,std::vector<std::string> enviroment)
	{
		int mapWidth = enviroment[1].size();
		int mapHeight = enviroment.size();
		mapWidth--;
		mapHeight--;

		float xpos = fromX;
		float ypos = fromY;
		float distance = 0.0f; 
		
		while(RayLimit > distance)
		{
			distance += RayStep;
			xpos += sinf(angle) * RayStep;
			ypos += cosf(angle) * RayStep;
			//sensing
			int	xRounded = round(xpos);
			int yRounded = round(ypos);

				if (  // if is not blank
					xRounded > 0 && yRounded > 0 &&
					yRounded <= enviroment.size()-1 && xRounded <= enviroment[yRounded].size()-1 &&
					enviroment[yRounded][xRounded] != ' '
					) 
				{
					std::cout << "\nhit : " << xRounded << " , " << yRounded << " , " << enviroment[yRounded][xRounded];
					auto rayHit = RayHit();
					rayHit.angle = angle;
					rayHit.charHit = enviroment[yRounded][xRounded];
					rayHit.distance = distance;
					rayHit.hit = true;
					rayHit.xPos = xpos;
					rayHit.yPos = ypos;
					return rayHit;
				}

				
		}
		
		auto noHit = RayHit();
		noHit.hit = false;
		return noHit;

	}
	std::vector<RayHit> castRays(std::vector<std::string> enviroment)
	{
		float startAngle = CameraAngle - (Fov/2.0f);
		float endAngle = CameraAngle + (Fov/2.0f);
		float angleStep = Fov / RayCount;

		std::vector<RayHit> rays;
		float currentAngle = startAngle;
		while (currentAngle < endAngle)
		{
			
			auto ray = castRay(CameraPosX, CameraPosY, currentAngle, enviroment);
			if (ray.hit == true)
				rays.push_back(ray);


			currentAngle += angleStep;
		}


		return rays;
	}
	std::string render(std::vector<RayHit> rays)
	{
		//popualte empty screen
		std::vector<std::string> screen;
		for (int y = 0; y < ScreenHeight; y++)
		{
			std::string row = "";
			for (int x = 0; x < ScreenWidth; x++)
			{
				row += ' ';
			}
			screen.push_back(row);
		}





		//insert walls
		for (int i = 0; i < rays.size(); i++)
		{
			float size;
			size = wallSize / rays[i].distance;
			int bottomPos = round(size / 2) + WallOffset;
			for (int ii = 0; ii < size; ii++)
			{

			}
		}






		std::string Output; // convert to single string
		for (int i = 0; i < screen.size(); i++)
		{
			Output += screen[i];
			Output += "\n";
		}
		return Output;
	}
};
