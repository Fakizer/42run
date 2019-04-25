#ifndef GLFW_manager_HPP
# define GLFW_manager_HPP

#define __gl3_h_

# define THIS_GLFW static_cast<GLFW_manager *>(glfwGetWindowUserPointer(win))

# include <glad/glad.h>
# include <GLFW/glfw3.h>
// # include "OpenGL/oGL_module.hpp"
# include "GLFW_input.hpp"
# include "GLFW_window.hpp"
# include "GLFW_controller.hpp"
# include "Exeptions_42run.hpp"
# include <cfenv>
# include <iostream>
# include <sstream>
# include <iomanip>

class GLFW_manager
{
	public :

		GLFW_manager(void);
		virtual ~GLFW_manager(void);
		GLFW_manager(GLFW_manager const &src) = delete;
		GLFW_manager &operator=(GLFW_manager const &rhs) = delete;

		static void run_manager(void);
		static void close_manager(void);

		/*
		 * Getter
		 */

		static size_t getActiveWindowNumber(void);
		static float getTime(void);
		GLFW_input const &getGLFW_input(void) const;
		GLFW_Window const &getWindow(void) const;
		GLFW_controller &getGamepad(void);
		std::string const &getStrFps(void) const;
		bool getMouseMode(void) const;

		/*
		 * Other
		 */

		void create_resizable_window(std::string const &name, int major, int minor,
									 int w, int h);
		void destroy_window(void);
		void init_input_callback(void);
		void update_events(void);
		void swap_buffers(void);
		bool should_window_be_closed(void);
		void update_title(std::string const &name);
		void update_title_fps(void);
		void calculate_fps(void);
		void reset_fps_counter(void);
		void toogle_mouse_exclusive(void);
		void triggerWindowClose(void);
		void disableVsync(void);
		void enableVsync(void);

		class InitFailException : public Exeptions_42run
		{
			public :

				explicit InitFailException(void);
				virtual ~InitFailException(void) throw();
		};

		class WindowFailException : public Exeptions_42run
		{
			public :

				explicit WindowFailException(void);
				virtual ~WindowFailException(void) throw();
		};

		class FileOpenException : public Exeptions_42run
		{
			public :

				explicit FileOpenException(void);
				explicit FileOpenException(std::string const &path);
				virtual ~FileOpenException(void) throw();
		};

	private :


		GLFW_input  		_input;
		GLFW_Window 		_window;
		std::string 		_win_name;
		float       		_last_time;
		float       		_last_fps_time;
		size_t      		_nb_frame;
		std::string			_str_fps;
		GLFW_controller		_gamepad;

		static size_t _nb_active_win;

		void _window_creation_callback_setup(void);
};

#endif


