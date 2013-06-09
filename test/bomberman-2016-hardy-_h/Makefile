##
## Makefile for bbman in /home/loukop_l//bomberman/bb
## 
## Made by laurent loukopoulos
## Login   <loukop_l@epitech.net>
## 
## Started on  Fri May 17 19:53:42 2013 laurent loukopoulos
## Last update Sat Jun  8 02:40:35 2013 laurent loukopoulos
##

NAME		=	bomberman

DIR		=	src/

SRC		=	$(DIR)main.cpp\
			$(DIR)MyGame.cpp\
			$(DIR)Menu.cpp\
			$(DIR)Camera.cpp\
			$(DIR)Camera_Menu.cpp\
			$(DIR)Primitive.cpp\
			$(DIR)Vector3f.cpp\
			$(DIR)Object.cpp\
			$(DIR)BGMenu.cpp\
			$(DIR)Bomberman.cpp\
			$(DIR)Bombe.cpp\
			$(DIR)Map.cpp \
			$(DIR)Trunks.cpp \
			$(DIR)Fire.cpp \
			$(DIR)Player1.cpp \
			$(DIR)Player2.cpp \
			$(DIR)MyPause.cpp \
			$(DIR)Bonus.cpp

OBJ		=	$(SRC:.cpp=.o)

RM		=	rm -f

CC		=	g++

INCLUDE		+=	-I./include/ -I./lib/include

CXXFLAGS	+=	

LDFLAGS		=	-L./lib/lib -Wl,--rpath=./lib/lib -lgdl_gl -lGL -lGLU -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio



$(NAME)	:	$(OBJ)
		$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

all	:	$(NAME)

clean	:
		$(RM) $(OBJ)
		$(RM) src/*~
		$(RM) src/*#
		$(RM) include/*~
		$(RM) include/*#

fclean	:	clean
		$(RM) $(NAME)

re	: 	fclean all

.cpp.o	:
		$(CC) $(CXXFLAGS) $(INCLUDE) -c $< -o $@