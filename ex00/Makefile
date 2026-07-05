NAME = Zombie
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

SRC = main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
OBJDIR = obj
DEPDIR = dep
OBJ = $(addprefix $(OBJDIR)/,$(SRC:.cpp=.o))
DEP = $(addprefix $(DEPDIR)/,$(SRC:.cpp=.d))

all : $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

$(OBJDIR) $(DEPDIR):
	mkdir -p $@

$(OBJDIR)/%.o: %.cpp | $(OBJDIR) $(DEPDIR)
	$(CXX) $(CXXFLAGS) -MMD -MP -MF $(DEPDIR)/$*.d -c $< -o $@

clean :
	rm -rf $(OBJDIR) $(DEPDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEP)

.PHONY: all clean fclean re
