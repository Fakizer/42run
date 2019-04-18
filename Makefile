NAME = 42run

# src_dir = ./sources/
# obj_dir = ./objects/
# lib_dir = ./library/
# inc_dir = ./includes/ $(lib_dir)glfw/include/

SRC_PATH = ./sources/
OBJ_PATH = ./objects/
LIB_PATH = ./library/
INC_PATH = ./includes/ \
			$(LIB_PATH)glfw/include/ \
			# ./includes/glad/ \
			# $(LIB_PATH)glad/include/ \
			# $(LIB_PATH)glfw/deps/ \
			# $(LIB_PATH)glad/include/KHR

GCC_FLGS = -Werror -Wextra -Wall -pedantic -g3
GCC_LIBS = -lglfw3 -framework AppKit -framework OpenGL -framework IOKit -framework CoreVideo

SYSCONF_LINK = clang++
LDFLAGS      = -O3 
LIB_NAME 	= glfw/src
INC 		= $(addprefix -I,$(INC_PATH))
LIB 		= $(addprefix -L$(LIB_PATH),$(LIB_NAME))

objectcpp := $(patsubst %.cpp, %.o, $(wildcard $(addprefix $(SRC_PATH), *.cpp)))
objectc := $(patsubst %.c, %.o, $(wildcard $(addprefix $(SRC_PATH), *.c)))
objectcpp := $(patsubst $(SRC_PATH)%.o, $(OBJ_PATH)%.o, $(objectcpp))
objectc := $(patsubst $(SRC_PATH)%.o, $(OBJ_PATH)%.o, $(objectc))
objectcpp := $(objectcpp:.cpp=.o)
objectc := $(objectc:.c=.o)

object := $(objectc) $(objectcpp)

all: $(NAME)

$(NAME) : obj_dir $(object)
		$(SYSCONF_LINK) $(GCC_FLGS) $(LDFLAGS) -o $@ $(INC) $(object) $(GCC_LIBS) $(LIB)

obj_dir:
		mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
		$(SYSCONF_LINK) $(CPPFLAGS) -c $< -o $@ $(INC)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		gcc $(CPPFLAGS) -c $< -o $@ $(INC)

clean:
		rm -f $(object)
		rm -rf $(OBJ_PATH)

fclean: clean
		rm -f $(NAME)

re: fclean all
