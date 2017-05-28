//
// Created by Qibin Chen on 28/05/2017.
//

#include <iostream>
#include "photowindow.h"

class CountDownEffect
{
	Widget *widget;

public:
	CountDownEffect(Widget *widget) : widget(widget)
	{
		std::cout << "CountDownEffects: Set Object PhotoWindow" << std::endl;
	}

	virtual ~CountDownEffect()
	{
		std::cout << "CountDownEffects::~CountDownEffects" << std::endl;
	}

	void Show()
	{
		std::cout << "CountDownEffects::Show" << std::endl;
		std::cout << "\tShowing Counting Down Effect" << std::endl;
		std::cout << "\t3" << std::endl;
		std::cout << "\t2" << std::endl;
		std::cout << "\t1" << std::endl;
		std::cout << "\tCome out!" << std::endl;
		
		widget->Show();
	}
};

int main()
{
	Widget *photoWindow = new PhotoWindow;
	CountDownEffect *effects = new CountDownEffect(photoWindow);

	effects->Show();

	delete photoWindow;
	delete effects;
	return 0;
}