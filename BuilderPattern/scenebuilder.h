//
// Created by Qibin Chen on 31/05/2017.
//

#ifndef DESIGNPATTERNS_SCENEBUILDER_H
#define DESIGNPATTERNS_SCENEBUILDER_H

#include "scene.h"

class SceneBuilder
{
protected:
	Scene *mainScene;

public:
	virtual ~SceneBuilder() {}

	virtual void CreateInit() final { mainScene = new Scene; }

	virtual void CreateWall(std::string color) = 0;

	virtual void CreateSky() = 0;

	virtual void CreateFurniture(std::string type) = 0;

	virtual void CreateLuminaire(std::string color) = 0;

	virtual Scene* GetScene() final { return mainScene; }
};


#endif //DESIGNPATTERNS_SCENEBUILDER_H
