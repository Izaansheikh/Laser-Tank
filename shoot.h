#define WIN 1
#define LOSE 2
#define WIN2 3

int playerShoot(char **map, int pRow, int pCol, int eRow, int eCol);

void eraseLaser(char **map, int mRow, int mCol);

int barrelExplode(char **map, int bRow, int bCol, int pRow, int pCol, int eRow, int eCol);