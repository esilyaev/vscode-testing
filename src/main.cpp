#include <ncurses.h>

#include <chrono>
#include <thread>

#include "shared/lib/Game.h"
#include "shared/lib/defines.h"

int main() {
  Game dsp;

  dsp.init();
  dsp.display();
  getch();

  while (1) {
    dsp.calc_new_generation();
    dsp.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(TIME_OUT));
  }

  return 0;
}