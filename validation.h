#define FALSE	0
#define TRUE	!FALSE

#define intCheck(min, max, value) ((value < min || value > max) ?FALSE: TRUE)

int validation(int mapRow, int mapCol, int pRow, int pCol, char pDir, int eRow, int eCol, int eDir);

int charCheck(char value);

int instantLoseCheck(int pRow, int pCol, int eRow, int eCol, int eDir);

int barrelCheck(int mapRow, int mapCol, int pRow, int pCol, int eRow, int eCol, int bRow, int bCol, int valid);