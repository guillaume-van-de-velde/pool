#ifndef RUSH01_H
# define RUSH01_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

int *get_board(char *str);

int row(int *soluce, int advance);
int col(int *soluce, int advance);
int good_number(int *soluce, int advance, int i);

int soluce_found();
int error();
void    print_soluce(int *soluce, int number);
int main(int argc, char **argv);

int ft_strlen(char *str);
int parsing(char *str);

int check_good_buildings(int *view, int ask);
int good_view(int *board, int *soluce);

void    back_tracking(int *board, int *soluce, int advance);
void    set_soluce(int *soluce);
void    start_soluce(int *board);

#endif