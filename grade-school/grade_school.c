#include "grade_school.h"
#include <string.h>

void init_roster(roster_t *r){
    if(r!=NULL){
        *r=(roster_t){0};
    }
}


bool add_student(roster_t *r,const char *nm, uint8_t gr){
    if (r->count>=MAX_STUDENTS) return false;
    for (size_t i=0;i<r->count;i++){
        if(strcmp(r->students[i].name,nm)==0){return false;}
    }
    r->students[r->count].grade=gr;

    strcpy(r->students[r->count].name,nm);

    r->count++;
    for(size_t j=0;j<r->count;j++){
        for(size_t k=0;k<r->count-1;k++){
            if(r->students[k].grade > r->students[k+1].grade){
                student_t x=r->students[k];
                r->students[k]=r->students[k+1];
                r->students[k+1]=x;
            }else if(r->students[k].grade == r->students[k+1].grade){
                if (strcmp(r->students[k].name,r->students[k+1].name)>0){
                    student_t x=r->students[k];
                    r->students[k]=r->students[k+1];
                    r->students[k+1]=x;
                }
            }
        }
    }
    
    return true;
}



roster_t get_grade(roster_t *r, uint8_t gr){
    roster_t nr;
    nr.count=0;
    
    for (size_t i=0;i<r->count;i++){
        if(r->students[i].grade==gr){
            nr.students[nr.count]=r->students[i];
            nr.count++;
        }
    }
    return nr;

}



//AI generated 
// If sorting will be executed every time a new student is added,
// then one while loop is sufficient.
//#include "grade_school.h"
//#include <string.h>
//
//void init_roster(roster_t *r){
//    if(r!=NULL){
//        *r=(roster_t){0};
//    }
//}
//
//bool add_student(roster_t *r, const char *nm, uint8_t gr){
//    if (r->count>=MAX_STUDENTS) return false;
//
//    for (size_t i=0;i<r->count;i++){
//        if(strcmp(r->students[i].name,nm)==0){return false;}
//    }
//
//    strncpy(r->students[r->count].name, nm, sizeof(r->students[r->count].name)-1);
//    r->students[r->count].name[sizeof(r->students[r->count].name)-1] = '\0';
//    r->students[r->count].grade = gr;
//
//    r->count++;
//
//    size_t pos = r->count - 1;
//    student_t new_student = r->students[pos];
//
//    while (pos > 0) {
//        student_t *prev = &r->students[pos-1];
//        bool should_move = (prev->grade > new_student.grade) ||
//                            (prev->grade == new_student.grade &&
//                             strcmp(prev->name, new_student.name) > 0);
//        if (!should_move) break;
//
//        r->students[pos] = *prev;
//        pos--;
//    }
//    r->students[pos] = new_student;
//
//    return true;
//}
//
//roster_t get_grade(roster_t *r, uint8_t gr){
//    roster_t nr;
//    nr.count=0;
//
//    for (size_t i=0;i<r->count;i++){
//        if(r->students[i].grade==gr){
//            nr.students[nr.count]=r->students[i];
//            nr.count++;
//        }
//    }
//    return nr;
//}