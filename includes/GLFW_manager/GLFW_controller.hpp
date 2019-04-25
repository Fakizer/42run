#ifndef GLFW_CONTROLLER_HPP
# define GLFW_CONTROLLER_HPP

# include <GLFW/glfw3.h>
# include "Exeptions_42run.hpp"
# include <fstream>
# include <iostream>
# include <sstream>
# include <iomanip>
# include <cstring>

# define MAX_GAMEPAD 16
# define MOV_DEAD_ZONE 0.25f
# define CAM_DEAD_ZONE 0.10f

typedef GLFWgamepadstate GamepadState;

class GLFW_controller
{
	public :

		GLFW_controller(size_t refreshed_gamepad_nb);
		virtual ~GLFW_controller(void);
		GLFW_controller(GLFW_controller const &src) = delete;
		GLFW_controller &operator=(GLFW_controller const &rhs) = delete;

		static void updateGamepadMapping(std::string const &file);
		void pollGamepads(void);
		bool isGamepadConnected(unsigned char joy_nb) const;
		void printJoystickInfo(unsigned char joy_nb) const;

		/*
		 * Getter
		 */

		GLFWgamepadstate const &getGamepadState(unsigned char joy_nb) const;


		class FileOpenException : public Exeptions_42run
		{
			public :

				explicit FileOpenException(void);
				explicit FileOpenException(std::string const &path);
				virtual ~FileOpenException(void) throw();
		};

		class TooMuchGamepadException : public Exeptions_42run
		{
			public :

				explicit TooMuchGamepadException(void);
				virtual ~TooMuchGamepadException(void) throw();
		};

	private :

		size_t           _refreshed_gamepad_nb;
		GLFWgamepadstate _state[MAX_GAMEPAD + 1];
};

#endif