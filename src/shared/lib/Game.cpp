#include "Game.h"

#include <cstdlib>
#include <ctime>

#include "defines.h"

int GetRandomNumber(int min, int max);

void Game::calc_new_generation() {
  auto new_state =
      std::vector<std::vector<bool>>(rows, std::vector<bool>(cols));

  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      int neighbors =
          static_cast<int>(get((r - 1 + rows) % rows, c)) +
          static_cast<int>(get((r - 1 + rows) % rows, (c - 1 + cols) % cols)) +
          static_cast<int>(get((r - 1 + rows) % rows, (c + 1 + cols) % cols)) +
          static_cast<int>(get((r + 1 + rows) % rows, c)) +
          static_cast<int>(get((r + 1 + rows) % rows, (c - 1 + cols) % cols)) +
          static_cast<int>(get((r + 1 + rows) % rows, (c + 1 + cols) % cols)) +
          static_cast<int>(get(r, (c - 1 + cols) % cols)) +
          static_cast<int>(get(r, (c + 1 + cols) % cols));

      bool alive = false;
      if (get(r, c) && (neighbors == 2 || neighbors == 3))
        alive = true;
      else if (!get(r, c) && neighbors == 3)
        alive = true;
      new_state[r][c] = alive;
    }
  }

  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      set(r, c, new_state[r][c]);
    }
  }
}
void Game::init() {
  srand(time(NULL));
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      int random = GetRandomNumber(1, 100);
      if (random > 90) {
        set(r, c, true);
      } else {
        set(r, c, false);
      }
    }
  }
}

void Game::display() {
  clear();
  for (int r = 0; r < rows; r++) {
    for (int c = 0; c < cols; c++) {
      if (get(r, c)) {
        mvaddch(r, c, ALIVE_SYMBOL);
      }
    }
  }
  refresh();
}

Game::Game() {
  initscr();
  cbreak();
  // timeout(TIME_OUT);
  getmaxyx(stdscr, rows, cols);
  state_size = rows * cols;
  state = std::vector<std::vector<bool>>(rows);
  for (auto& a : state) {
    a = std::vector<bool>(cols);
  }
  printw("Count of cell: %d \n", state_size);
  printw("Press any key to continue...");
  refresh();
  getch();
}

Game::~Game() { endwin(); }

bool Game::get(int row, int col) { return state[row][col]; }
void Game::set(int row, int col, bool value) { state[row][col] = value; }

int GetRandomNumber(int min, int max) {
  // Получить случайное число - формула
  int num = min + rand() % (max - min + 1);

  return num;
}
