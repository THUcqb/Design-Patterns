//
// Created by Qibin Chen on 31/05/2017.
//

#ifndef DESIGNPATTERNS_SCENEBUILDER2D_H
#define DESIGNPATTERNS_SCENEBUILDER2D_H

#include "scenebuilder.h"

class SceneBuilder2D : public SceneBuilder
{
public:
	void CreateWall(std::string color) override;

	void CreateSky() override;

	void CreateLuminaire(std::string color) override;

	void CreateFurniture(std::string type) override;
};


#endif //DESIGNPATTERNS_SCENEBUILDER2D_H
