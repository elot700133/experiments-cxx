#include <ncurses.h>

int main()
{
  initscr();
  raw();
  noecho();
  //printw("Start window example");
  refresh();
  WINDOW * w = newwin(10, 10, 0, 0);
  box(w, 0, 0);
  wrefresh(w);
  getch();
  delwin(w);
  getch();
  endwin();
  return 0;
}
