#include <stdio.h>

int pa_recursiva(int *v, int primeiro, int ultimo) {
    if (ultimo - primeiro == 1) return 1;

    if (v[primeiro] + v[ultimo] == v[primeiro + 1] + v[ultimo - 1])
        return pa_recursiva(v, primeiro + 1, ultimo - 1);
    else return 0;
}
