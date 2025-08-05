#include "robot_simulator.h"

robot_status_t robot_create(robot_direction_t direction, int x, int y){
    robot_status_t robot ;
    robot.position.x = x;
    robot.position.y = y;
    robot.direction = direction;
    return robot;
}
void robot_move(robot_status_t *robot, const char *commands){
    int i = 0;
    if(commands == NULL) return;
    while(commands[i] != '\0'){
        if(commands[i] == 'A'){
            if(robot->direction == 0) robot->position.y++;
            else if(robot->direction == 1) robot->position.x++;
            else if(robot->direction == 2) robot->position.y--;
            else if(robot->direction == 3) robot->position.x--;
        }
        else if(commands[i] == 'R'){
            robot->direction = (robot->direction == 3) ? 0 : robot->direction + 1;  
        }
        else if(commands[i] == 'L'){
            robot->direction = (robot->direction == 0) ? 3 : robot->direction - 1;
        }
        i++;
    }
}
