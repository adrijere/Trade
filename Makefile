NAME		=	trade

SRC			=	main.cpp \
				Trade.cpp

OBJ			=	$(SRC:.cpp=.o)

RM			=	rm -rf

CXX			=	clang++

CXXFLAGS	=	-W -Wall -Wextra

all			:	$(NAME)

$(NAME)		:	$(OBJ)
				$(CXX) -o $(NAME) $(OBJ)

clean		:
				$(RM) $(OBJ)

fclean		:	clean
				$(RM) $(NAME)

re			:	fclean all
