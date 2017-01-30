NAME_EXE	= nibbler
SRC_EXE		= main.cpp
OBJ_EXE		= $(SRC_EXE:.cpp=.o)

NAME_LIB	= lib_nibbler_ncurses.so

SRC_LIB		= libone.cpp \
		libonefunc.cpp \
		libonecheck.cpp \
		libonefunc2.cpp \
		libonefunc3.cpp

OBJ_LIB		= $(SRC_LIB:.cpp=.o)

LDFLAGS		+= -ldl
CXXFLAGS	+= -fPIC

CXX		= clang++

all:	$(NAME_LIB) $(NAME_EXE)

$(NAME_EXE): $(OBJ_EXE)
	$(CXX) -o $(NAME_EXE) $(OBJ_EXE) $(LDFLAGS) -lncurses

$(NAME_LIB): $(OBJ_LIB)
	$(CXX) -shared -o $(NAME_LIB) $(OBJ_LIB)

clean:
	rm -f $(OBJ_LIB) $(OBJ_EXE)

fclean: clean
	rm -f $(NAME_EXE) $(NAME_LIB)

re:	fclean all
