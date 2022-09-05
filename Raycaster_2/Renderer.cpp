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

	float CameraPosX = 0.0f;
	float CameraPosY = 0.0f;
	float CameraAngle = 0.0f;

	float Fov = 90.0f;
	//render settings
	float RayCount = 200.0f;
	float RayStep = 0.25f;
	float RayLimit = 100.0f;
	float WallOffset = 0.0f;
		
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
			//if ((yRounded < enviroment.size() && xRounded < enviroment[yRounded].size() && xRounded < 0 && yRounded < 0)) //CHECK OUT OF RANGE
				if (enviroment[yRounded][xRounded] != ' ') // if is not blank
				{
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
	std::string render(std::vector<RayHit> Rays)
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

		
		std::string Output; // convert to single string
		for (int i = 0; i < screen.size(); i++)
		{
			Output += screen[i];
			Output += "\n";
		}
		return Output;
	}
};
