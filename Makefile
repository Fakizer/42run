NAME = 42run

# src_dir = ./sources/
# obj_dir = ./objects/
# lib_dir = ./library/
# inc_dir = ./includes/ $(lib_dir)glfw/include/

SRC_PATH = ./sources/
SRC_SUB_PATH = GLFW_manager/
OBJ_PATH = ./objects/
OBJ_SUB_PATH = GLFW_manager/
LIB_PATH = ./library/
INC_PATH = ./includes/ \
			$(LIB_PATH)glfw/include/ \
			# ./includes/glad/ \
			# $(LIB_PATH)glad/include/ \
			# $(LIB_PATH)glfw/deps/ \
			# $(LIB_PATH)glad/include/KHR
INC_SUB_PATH = GLFW_manager/

GCC_FLGS = -Werror -Wextra -Wall -pedantic -g3 
CPP_FLGS += -Wno-c++11-extensions
GCC_LIBS = -lglfw3 -framework AppKit -framework OpenGL -framework IOKit -framework CoreVideo

SYSCONF_LINK = g++
LDFLAGS      = -O3 
LIB_NAME 	= glfw/src
INC 		= $(addprefix -I,$(INC_PATH) $(addsuffix $(INC_SUB_PATH), ./includes/))
LIB 		= $(addprefix -L$(LIB_PATH),$(LIB_NAME))

sources_sub_path = $(addprefix $(SRC_PATH), $(SRC_SUB_PATH))
object_sub_path = $(addprefix $(OBJ_PATH), $(OBJ_SUB_PATH))

object_sub_cpp := $(patsubst %.cpp, %.o, $(wildcard $(addprefix $(sources_sub_path), *.cpp)))
objectcpp := $(patsubst %.cpp, %.o, $(wildcard $(addprefix $(SRC_PATH), *.cpp)))
objectc := $(patsubst %.c, %.o, $(wildcard $(addprefix $(SRC_PATH), *.c)))

object_sub_cpp := $(patsubst $(sources_sub_path)%.o, $(object_sub_path)%.o, $(object_sub_cpp))
objectcpp := $(patsubst $(SRC_PATH)%.o, $(OBJ_PATH)%.o, $(objectcpp))
objectc := $(patsubst $(SRC_PATH)%.o, $(OBJ_PATH)%.o, $(objectc))

object_sub_cpp := $(object_sub_cpp:.cpp=.o)
objectcpp := $(objectcpp:.cpp=.o)
objectc := $(objectc:.c=.o)

object := $(object_sub_cpp) $(objectc) $(objectcpp)

all: $(NAME)

$(NAME) : obj_dir $(object)
		$(SYSCONF_LINK) $(GCC_FLGS) $(LDFLAGS) -o $@ $(INC) $(object) $(GCC_LIBS) $(LIB)

obj_dir:
		mkdir $(OBJ_PATH)
		mkdir $(object_sub_path)
		@echo $(object)

$(object_sub_path)%.o: $(sources_sub_path)%.cpp
		$(SYSCONF_LINK) $(GCC_FLGS) $(CPP_FLGS) -c $< -o $@ $(INC)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
		$(SYSCONF_LINK) $(GCC_FLGS) $(CPP_FLGS) -c $< -o $@ $(INC)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		gcc $(GCC_FLGS) -c $< -o $@ $(INC)

clean:
		rm -f $(object)
		rm -rf $(object_sub_path)
		rm -rf $(OBJ_PATH)

fclean: clean
		rm -f $(NAME)

re: fclean all
