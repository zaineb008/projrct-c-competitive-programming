#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point data[MAX * MAX];
    int tete, queue;
} File;

void initialisation(File *f) { 
    f->tete = f->queue = 0; 
}
bool est_vide(File *f) {
     return f->tete == f->queue;
}
void enfiler(File *f, Point p) {
     f->data[f->queue++] = p; 
}
Point defiler(File *f) {
     return f->data[f->tete++]; 
}

int n, m;
char grille[MAX][MAX];
bool visite[MAX][MAX];
Point parent[MAX][MAX];
char direction_prise[MAX][MAX];
int distance[MAX][MAX];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
char direction[] = {'N', 'S', 'E', 'O'};

bool Valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && grille[x][y] != '#';
}

void bfs(Point depart, Point arrivee) {
    File f;
    initialisation(&f);
    
    memset(visite, false, sizeof(visite));
    memset(distance, -1, sizeof(distance));
    memset(direction_prise, 0, sizeof(direction_prise));
    
    visite[depart.x][depart.y] = true;
    distance[depart.x][depart.y] = 0;
    parent[depart.x][depart.y] = (Point){-1, -1};
    enfiler(&f, depart);
    
    while (!est_vide(&f)) {
        Point current = defiler(&f);
        if (current.x == arrivee.x && current.y == arrivee.y) break;
        
        for (int i = 0; i < 4; i++) {
            int x1 = current.x + dx[i], y1 = current.y + dy[i];
            if (Valid(x1, y1) && !visite[x1][y1]) {
                visite[x1][y1] = true;
                distance[x1][y1] = distance[current.x][current.y] + 1;
                parent[x1][y1] = current;
                direction_prise[x1][y1] = direction[i];
                enfiler(&f, (Point){x1, y1});
            }
        }
    }
}

void printchemin(Point depart, Point arrivee) {
    if (distance[arrivee.x][arrivee.y] == -1) {
        printf("erreur\n");
        return;
    }
    
    char moves[MAX * MAX];
    int index = 0;
    Point current = arrivee;
    
    while (!(current.x == depart.x && current.y == depart.y)) {
        moves[index++] = direction_prise[current.x][current.y];
        current = parent[current.x][current.y];
    }

    for (int i = index - 1; i >= 0; i--) {
        printf("%c", moves[i]);
    }
    printf("\n");
}

void visualisation(Point depart, Point arrivee) {
    char affichage[MAX][MAX];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            affichage[i][j] = grille[i][j];
        }
    }
    
    if (distance[arrivee.x][arrivee.y] != -1) {
        Point current = arrivee;
        while (!(current.x == depart.x && current.y == depart.y)) {
            if (grille[current.x][current.y] != 'D' && grille[current.x][current.y] != 'A') {
                affichage[current.x][current.y] = '*';
            }
            current = parent[current.x][current.y];
        }
    }
    
    for (int i = 0; i < n; i++) {
        printf("%s\n", affichage[i]);
    }
}

int main() {
    Point depart, arrivee;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; i++) {
        scanf("%s", grille[i]);
        for (int j = 0; j < m; j++) {
            if (grille[i][j] == 'D') {
                depart.x = i;
                depart.y = j;
            } else if (grille[i][j] == 'A') {
                arrivee.x = i;
                arrivee.y = j;
            }
        }
    }
    
    bfs(depart, arrivee);
    printchemin(depart, arrivee);
    visualisation(depart, arrivee);
    
    return 0;
}