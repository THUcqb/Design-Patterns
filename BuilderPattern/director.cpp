//
// Created by Qibin Chen on 31/05/2017.
//

#include "director.h"
#include "scenebuilder.h"

Director::Director(SceneBuilder *builder) : builder(builder)
{}

Scene* Director::Construct(std::string environment)
{
	builder->CreateInit();
	if (environment == std::string("Outside"))
	{
		builder->CreateSky();
	}
	else if (environment == std::string("Blue Inside"))
	{
		builder->CreateWall("blue");
		builder->CreateFurniture("desk");
		builder->CreateLuminaire("white");
	}
	return builder->GetScene();
}
