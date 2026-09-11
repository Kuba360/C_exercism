#include "two_bucket.h"
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int gcd(int a, int b){

    while(b!=0){
        int tmp=b;
        b=a%b;
        a=tmp;
    }
    return a;
}

void pour(int *from, int *to, int limit){
    int amount=limit-*to;

    if(amount>*from)amount=*from;

    *to+=amount;
    *from-=amount;
}
void empty(int *from){
    *from=0;
}
void fill(int *from,int limit){
    *from=limit;
}

//I was heavily dependent on ai here, first time using BFS

bucket_result_t measure(bucket_liters_t bucket_1_size,
                        bucket_liters_t bucket_2_size,
                        bucket_liters_t goal_volume, bucket_id_t start_bucket){
        
        bucket_liters_t max=(bucket_1_size>bucket_2_size)?bucket_1_size:bucket_2_size;
        bucket_result_t br={.possible=false,.move_count=0,.goal_bucket=BUCKET_ID_1,.other_bucket_liters=0};
        if(goal_volume >max || goal_volume%gcd(bucket_1_size,bucket_2_size)!=0){
            return br;
        }
        int stride=bucket_2_size+1;
        bool visited[(bucket_1_size+1)*(bucket_2_size+1)];

        memset(visited,0,sizeof(visited));
        state_t queue[2000];
        int front=0, back=0;

        if(start_bucket==BUCKET_ID_1){
            visited[0*stride+bucket_2_size]=true;
        }else{
            visited[bucket_1_size*stride+0]=true;
        }

        state_t start_state={
            .bucket1=(start_bucket==BUCKET_ID_1)?bucket_1_size:0,
            .bucket2=(start_bucket==BUCKET_ID_2)?bucket_2_size:0,
            .moves=1
        };

        queue[back++]=start_state;
        visited[start_state.bucket1*stride+start_state.bucket2]=true;


        while(front<back){
            state_t curr=queue[front++];

            if(curr.bucket1==goal_volume){
                br.possible=true;
                br.move_count=curr.moves;
                br.goal_bucket=BUCKET_ID_1;
                br.other_bucket_liters=curr.bucket2;
                return br;
            }
            if(curr.bucket2==goal_volume){
                br.possible=true;
                br.move_count=curr.moves;
                br.goal_bucket=BUCKET_ID_2;
                br.other_bucket_liters=curr.bucket1;
                return br;
            }
            state_t next_states[6];
            int num_next=0;

            next_states[num_next++]=(state_t){bucket_1_size,curr.bucket2,curr.moves+1};

            next_states[num_next++]=(state_t){curr.bucket1,bucket_2_size,curr.moves+1};

            next_states[num_next++]=(state_t){0,curr.bucket2,curr.moves+1};
            
            next_states[num_next++]=(state_t){curr.bucket1,0,curr.moves+1};

            int b1=curr.bucket1, b2=curr.bucket2;
            pour(&b1,&b2,bucket_2_size);
            next_states[num_next++]=(state_t){b1,b2,curr.moves+1};

            b1=curr.bucket1, b2=curr.bucket2;
            pour(&b2,&b1,bucket_1_size);
            next_states[num_next++]=(state_t){b1,b2,curr.moves+1};

            for(int i=0;i<num_next;i++){
                int idx=next_states[i].bucket1*stride+next_states[i].bucket2;
                if(!visited[idx]){
                    visited[idx]=true;
                    queue[back++]=next_states[i];
                }
            }
        }

        return br;
    }