#include "GLFW_controller.hpp"

GLFW_controller::GLFW_controller(size_t refreshed_gamepad_nb) : _refreshed_gamepad_nb(refreshed_gamepad_nb)
{
	if (this->_refreshed_gamepad_nb > MAX_GAMEPAD)
		throw GLFW_controller::TooMuchGamepadException();
	std::memset(&this->_state, 0, sizeof(GLFWgamepadstate) * (MAX_GAMEPAD + 1));
}

GLFW_controller::~GLFW_controller(void)
{
}

void GLFW_controller::updateGamepadMapping(std::string const &file)
{
	std::fstream fs;
	std::string  content;

	std::cout << "Loading : " << file << std::endl;
	try
	{
		fs.exceptions(std::fstream::failbit | std::fstream::badbit);
		fs.open(file, std::fstream::in);
		content.assign((std::istreambuf_iterator<char>(fs)),
					   std::istreambuf_iterator<char>());
		fs.close();
	}
	catch (std::exception &e)
	{
		throw GLFW_controller::FileOpenException(file);
	}
	glfwUpdateGamepadMappings(content.c_str());
}

void GLFW_controller::pollGamepads(void)
{
	for (size_t i = 0; i < MAX_GAMEPAD; ++i)
	{
		if (glfwJoystickPresent(i) && glfwJoystickIsGamepad(i))
			glfwGetGamepadState(i, &this->_state[i]);
	}
}

bool GLFW_controller::isGamepadConnected(unsigned char joy_nb) const
{
	if (joy_nb >= MAX_GAMEPAD)
		return (false);
	if (!glfwJoystickPresent(joy_nb) || !glfwJoystickIsGamepad(joy_nb))
		return (false);
	return (true);
}

void GLFW_controller::printJoystickInfo(unsigned char joy_nb) const
{
	char const *joy_guid = NULL;
	char const *joy_name = NULL;

	if (joy_nb >= MAX_GAMEPAD)
	{
		std::cout << "Invalid Joystick" << std::endl;
		return;
	}
	if (!glfwJoystickPresent(joy_nb))
	{
		std::cout << "No joystick or gamepad connected" << std::endl;
		return;
	}
	std::cout << "Joystick " << joy_nb << " : ";
	if (!(joy_name = glfwGetJoystickName(joy_nb)))
		std::cout << "Unknown Joystick name : ";
	else
		std::cout << joy_name << " : ";
	if (glfwJoystickIsGamepad(joy_nb))
		std::cout << "Is a Gamepad : ";
	if ((joy_guid = glfwGetJoystickGUID(joy_nb)) == NULL)
	{
		std::cout << "Unknowm GUID" << std::endl;
		return;
	}
	else
		std::cout << joy_guid << std::endl;
}

/*
 * Getter
 */

GLFWgamepadstate const &GLFW_controller::getGamepadState(unsigned char joy_nb) const
{
	if (joy_nb >= MAX_GAMEPAD || !glfwJoystickPresent(joy_nb) ||
		!glfwJoystickIsGamepad(joy_nb))
	{
		std::cout << "Invalid Gamepad requested" << std::endl;
		return (this->_state[MAX_GAMEPAD]);
	}
	return (this->_state[joy_nb]);
}

GLFW_controller::FileOpenException::FileOpenException(std::string const &path)
{
	this->_msg = "GLFW_controller : Failed to find to open file : ";
	this->_msg += path.c_str();
}

GLFW_controller::FileOpenException::FileOpenException(void)
{
	this->_msg = "GLFW_controller : Failed to find to open file";
}

GLFW_controller::FileOpenException::~FileOpenException(void) throw()
{
}

GLFW_controller::TooMuchGamepadException::TooMuchGamepadException(void)
{
	this->_msg = "GLFW_controller : Too much gamepad to refresh";
}

GLFW_controller::TooMuchGamepadException::~TooMuchGamepadException(void) throw()
{
}