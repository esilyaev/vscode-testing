#include <ncurses.h>

#include <vector>

class Game {
 private:
  int rows;
  int cols;
  std::vector<std::vector<bool>> state;
  bool get(int row, int col);
  void set(int row, int col, bool value);
  int state_size;

 public:
  void calc_new_generation();
  void init();
  void display();
  Game();
  ~Game();
};