//
// Created by Qibin Chen on 31/05/2017.
//

#include "scene.h"

void Scene::AddComponent(std::string newcomp)
{
	components.push_back(newcomp);
}

void Scene::Show()
{
	for (auto comp : components)
		std::cout << comp << std::endl;
}

