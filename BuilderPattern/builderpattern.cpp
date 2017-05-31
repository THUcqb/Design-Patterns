//
// Created by Qibin Chen on 31/05/2017.
//

#include "scenebuilder2d.h"
#include "director.h"

int main()
{
	SceneBuilder *builder = new SceneBuilder2D;
	Director director(builder);

	Scene *scene = director.Construct("Blue Inside");
	scene->Show();

	delete scene;
	delete builder;
	return 0;
}