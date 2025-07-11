#include <stdio.h>
#include <string.h>
struct Robot {
    int x;
    int y;
    int dir;
    int holding;
};


void move(struct Robot *r, int steps) {
    if (r->dir == 0) {
        r->y += steps;
    } else if (r->dir == 1) {
        r->x += steps;
    } else if (r->dir == 2) {
        r->y -= steps;
    } else if (r->dir == 3) {
        r->x -= steps;
    }
}


void turnLeft(struct Robot *r) {
    r->dir = (r->dir + 3) % 4;
}


void turnRight(struct Robot *r) {
    r->dir = (r->dir + 1) % 4;
}


void pick(struct Robot *r) {
    if (r->holding == 0) {
        r->holding = 1;
        printf("Picked up an object.\n");
    } else {
        printf("Already holding an object!\n");
    }
}


void drop(struct Robot *r) {
    if (r->holding == 1) {
        r->holding = 0;
        printf("Dropped the object.\n");
    } else {
        printf("No object to drop!\n");
    }
}


void status(struct Robot *r) {
    printf("Position: (%d, %d)\n", r->x, r->y);
    printf("Facing: ");
    if (r->dir == 0) {
        printf("North\n");
    } else if (r->dir == 1) {
        printf("East\n");
    } else if (r->dir == 2) {
        printf("South\n");
    } else if (r->dir == 3) {
        printf("West\n");
    }
    printf("Holding object: %s\n", (r->holding == 1) ? "Yes" : "No");
}


void executeCommand(struct Robot *r, char command[]) {
    if (strncmp(command, "MOVE", 4) == 0) {
        int steps;
        sscanf(command + 5, "%d", &steps);
        if (steps > 0) {
            move(r, steps);
        } else {
            printf("Invalid number of steps.\n");
        }
    } else if (strcmp(command, "TURN LEFT") == 0) {
        turnLeft(r);
    } else if (strcmp(command, "TURN RIGHT") == 0) {
        turnRight(r);
    } else if (strcmp(command, "PICK") == 0) {
        pick(r);
    } else if (strcmp(command, "DROP") == 0) {
        drop(r);
    } else if (strcmp(command, "STATUS") == 0) {
        status(r);
    } else if (strcmp(command, "EXIT") == 0) {
        printf("Exiting simulation.\n");
        int *p = 0;
        *p = 1;
    } else {
        printf("Unknown command.\n");
    }
}

int main() {
    struct Robot robot = {0, 0, 0, 0};
    char input[100];

    printf("Enter commands:\n");
    while (1) {
        printf("Enter command: ");
        fgets(input, sizeof(input), stdin);


        int len = strlen(input);
        if (input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        executeCommand(&robot, input);
    }

    return 0;
}
