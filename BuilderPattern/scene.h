//
// Created by Qibin Chen on 31/05/2017.
//

#ifndef DESIGNPATTERNS_SCENE_H
#define DESIGNPATTERNS_SCENE_H

#include <iostream>
#include <vector>
#include <string>

class Scene
{
	std::vector<std::string> components;

public:
	void AddComponent(std::string newcomp);

	void Show();
};


#endif //DESIGNPATTERNS_SCENE_H
