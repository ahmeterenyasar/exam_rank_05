#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct {
    int w;
    int h;
    char *m;
} t_map;

int count_neighbors(t_map *map, int x, int y)
{
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;

            int ny = y + i;
            int nx = x + j;

            if (nx >= 0 && nx < map->w && ny >= 0 && ny < map->h) {
                if (map->m[ny * map->w + nx] == 'O')
                    count++;
            }
        }
    }
    return count;
}

void simulate(t_map *map)
{
    char *new_map = malloc(map->w * map->h);
    
    for (int y = 0; y < map->h; y++) {
        for (int x = 0; x < map->w; x++) {
            int neighbors = count_neighbors(map, x, y);
            int idx = y * map->w + x;
            
            if (map->m[idx] == 'O') {
                if (neighbors == 2 || neighbors == 3)
                    new_map[idx] = 'O';
                else
                    new_map[idx] = ' ';
            } else {
                if (neighbors == 3)
                    new_map[idx] = 'O';
                else
                    new_map[idx] = ' ';
            }
        }
    }
    free(map->m);
    map->m = new_map;
}

int main(int ac, char **av)
{
    if (ac != 4) return 0;

    t_map map;
    map.w = atoi(av[1]);
    map.h = atoi(av[2]);
    int iter = atoi(av[3]);

    map.m = malloc(map.w * map.h);
    for (int i = 0; i < map.w * map.h; i++)
        map.m[i] = ' ';

    char c;
    int x = 0, y = 0;
    int drawing = 0;

    while (read(0, &c, 1) > 0)
    {
        if (c == 'w' && y > 0) y--;
        else if (c == 's' && y < map.h - 1) y++;
        else if (c == 'a' && x > 0) x--;
        else if (c == 'd' && x < map.w - 1) x++;
        else if (c == 'x') drawing = !drawing;

        if (drawing && (c == 'w' || c == 's' || c == 'a' || c == 'd' || c == 'x'))
            map.m[y * map.w + x] = 'O';
    }

    while (iter--)
        simulate(&map);

    for (int i = 0; i < map.w * map.h; i++) {
        if (i > 0 && i % map.w == 0)
            write(1, "\n", 1);
        write(1, &map.m[i], 1);
    }
    write(1, "\n", 1);

    free(map.m);
    return 0;
}