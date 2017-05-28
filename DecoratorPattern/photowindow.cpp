//
// Created by Qibin Chen on 28/05/2017.
//

#include "photowindow.h"
#include <iostream>

PhotoWindow::PhotoWindow()
{
	std::cout << "PhotoWindow::PhotoWindow" << std::endl;
}

PhotoWindow::~PhotoWindow()
{
	std::cout << "PhotoWindow::~PhotoWindow" << std::endl;
}

void PhotoWindow::Show()
{
	std::cout << "PhotoWindow::Show" << std::endl;
}

