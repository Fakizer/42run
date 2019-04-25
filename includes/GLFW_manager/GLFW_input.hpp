#ifndef GLFW_INPUT_HPP
# define GLFW_INPUT_HPP

# include <vector>
# include <GLFW/glfw3.h>

# define PRESSED true
# define RELEASED false

struct GLFW_input
{
	GLFW_input(void);
	~GLFW_input(void);

	std::vector<bool> p_key;
	std::vector<bool> p_mouse;
	GLfloat           last_pos_x;
	GLfloat           last_pos_y;
	GLfloat           x_offset;
	GLfloat           y_offset;
	float             timer;
	bool              first_time;
	bool              mouse_refreshed;
	bool              mouse_exclusive;
};

#endif
