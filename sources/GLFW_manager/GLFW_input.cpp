#include "GLFW_input.hpp"

GLFW_input::GLFW_input(void) :
		p_key(1024, RELEASED), p_mouse(32, RELEASED), last_pos_x(0.0f),
		last_pos_y(0.0f), x_offset(0.0f), y_offset(0.0f), timer(0.0f),
		first_time(true), mouse_refreshed(true), mouse_exclusive(true)
{
}

GLFW_input::~GLFW_input(void)
{
}
