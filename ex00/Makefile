CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3
SRCS = main.cpp getRate.cpp readDB.cpp checkDate.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = btc

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re