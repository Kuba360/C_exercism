#include "robot_simulator.h"




robot_status_t robot_create(robot_direction_t direction, int x, int y){
    robot_status_t r1;
    r1.direction=direction;
    r1.position.x=x;
    r1.position.y=y;

    return r1;
}



void robot_move(robot_status_t *robot, const char *commands){
    for (int i=0;*(commands+i)!='\0';i++){
        if (*(commands+i)=='R'){
            robot->direction=(robot->direction+1)%DIRECTION_MAX;
        }else if(*(commands+i)=='L'){
            robot->direction=(robot->direction+3)%DIRECTION_MAX;
        }else if(*(commands+i)=='A'){
            switch(robot->direction){
                case DIRECTION_NORTH:
                    robot->position.y+=1;
                    break;
                case DIRECTION_EAST:
                    robot->position.x+=1;
                    break;
                case DIRECTION_SOUTH:
                    robot->position.y-=1;
                    break;
                case DIRECTION_WEST:
                    robot->position.x-=1;
                    break;
                default:
                    break;
            }
        }
    }
}



//AI generated 
//void robot_move(robot_status_t *robot, const char *commands) {
    //// dx/dy dla każdego kierunku: N, E, S, W
    //int dx[] = {0, 1, 0, -1};
    //int dy[] = {1, 0, -1, 0};

    //for (int i = 0; commands[i] != '\0'; i++) {
        //if (commands[i] == 'R')
            //robot->direction = (robot->direction + 1) % DIRECTION_MAX;
        //else if (commands[i] == 'L')
            //robot->direction = (robot->direction + 3) % DIRECTION_MAX;
        //else if (commands[i] == 'A') {
            //robot->position.x += dx[robot->direction];
            //robot->position.y += dy[robot->direction];
        //}
    //}
//}