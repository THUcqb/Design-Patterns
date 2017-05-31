//
// Created by Qibin Chen on 31/05/2017.
//

#include "scenebuilder2d.h"

void SceneBuilder2D::CreateWall(std::string color)
{
	mainScene->AddComponent(std::string("2D Wall, color: ") + color);
}

void SceneBuilder2D::CreateSky()
{
	mainScene->AddComponent(std::string("2D Sky"));
}

void SceneBuilder2D::CreateFurniture(std::string type)
{
	mainScene->AddComponent(std::string("2D Furniture, type:") + type);
}

void SceneBuilder2D::CreateLuminaire(std::string color)
{
	mainScene->AddComponent(std::string("2D Luminaire, color: ") + color);
}
