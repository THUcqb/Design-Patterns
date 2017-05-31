//
// Created by Qibin Chen on 31/05/2017.
//

#ifndef DESIGNPATTERNS_DIRECTOR_H
#define DESIGNPATTERNS_DIRECTOR_H

#include <string>

class SceneBuilder;
class Scene;

class Director
{
	SceneBuilder *builder;

public:
	Director(SceneBuilder *builder);

	Scene* Construct(std::string environment);
};


#endif //DESIGNPATTERNS_DIRECTOR_H
