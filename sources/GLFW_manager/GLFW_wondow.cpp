#include "GLFW_window.hpp"

GLFW_Window::GLFW_Window(void)
{
	this->win       = NULL;
	this->cur_win_w = MIN_WIN_W;
	this->cur_win_h = MIN_WIN_H;
	this->min_win_w = MIN_WIN_W;
	this->min_win_h = MIN_WIN_H;
	this->max_win_w = MAX_WIN_W;
	this->max_win_h = MAX_WIN_H;
	this->resized   = true;
}

GLFW_Window::~GLFW_Window(void)
{
}
