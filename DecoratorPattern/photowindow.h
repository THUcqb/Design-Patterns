//
// Created by Qibin Chen on 28/05/2017.
//

#ifndef DESIGN_PATTERNS_PHOTOWINDOW_H
#define DESIGN_PATTERNS_PHOTOWINDOW_H

class Widget
{
public:
	virtual ~Widget() {};

	virtual void Show() = 0;
};

class PhotoWindow : public Widget
{
public:
	PhotoWindow();

	virtual ~PhotoWindow();

	void Show() override ;
};


#endif //DESIGN_PATTERNS_PHOTOWINDOW_H
