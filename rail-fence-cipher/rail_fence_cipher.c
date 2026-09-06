#include "rail_fence_cipher.h"
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

void one_row(char *text, char *enco, int *index, int rails, int r, int l,int begin){
        if(r==rails || r==1){
            while(begin<l){
                int space=rails*2-2;
                enco[*index]=text[begin];
                (*index)++;
                begin+=space;
            }
        }else{
            while(begin<l){
                int space1=rails*2-2;
                int space2=r*2-2;
                enco[*index]=text[begin];
                (*index)++;
                if(begin+space2<l){
                    enco[*index]=text[begin+space2];
                    (*index)++;
                }
                begin+=space1;
            }
        }
}

char *encode(char *text, size_t rails){

    if (rails == 1) {
    char *enco = malloc(strlen(text) + 1);
    if (!enco) return NULL;
    strcpy(enco, text);
    return enco;
    }

    int l=(int)strlen(text);
    char *enco=malloc((l+1)*sizeof(char));
    if(!enco)return NULL;
    int index=0;
    int begin=0;
    int  r=(int)rails;
    rails=(int)rails;
    while(r>0){
        one_row(text,enco,&index,rails,r,l,begin);
        r--;
        begin++;
    }
    enco[index]='\0';
    return enco;
}

char *decode(char *ciphertext, size_t rails){
    int l=(int)strlen(ciphertext);
    char *deco=malloc((l+1)*sizeof(char));
    int *tab=calloc(l,sizeof(int));
    if(!tab || !deco){
        free(tab);
        free(deco);
        return NULL;
    }

    int r=0;
    int direction=1;
    for(int i=0;i<l;i++){
        tab[i]=r;
        if(r==0){
            direction=1;
        }else if(r==(int)rails-1){
            direction=-1;
        }
        r+=direction;
    }

    int *rows=calloc(rails,sizeof(int));
    int *pos=calloc(rails,sizeof(int));
    if(!rows || !pos){
        free(pos);
        free(rows);
        free(tab);
        free(deco);
        return NULL;
    }
    for(size_t i=0;i<rails;i++){
        for(int j=0;j<l;j++){
            if(tab[j]==(int)i){
                rows[i]++;
            }
        }
    }

    int index=0;
    while(index<l){
        int row=tab[index];
        int space=0;
        for(int k=0;k<row;k++){
            space+=rows[k];
        }
        deco[index++]=ciphertext[space+pos[row]];
        pos[row]++;
    }
    deco[l]='\0';
    free(tab);
    free(rows);
    free(pos);
    return deco;


}


//AI version of encode function
//char *encode(char *text, size_t rails)
//{
    //size_t len = strlen(text);

    //char *enco = malloc(len + 1);
    //if (enco == NULL)
        //return NULL;

    //if (rails == 1) {
        //strcpy(enco, text);
        //return enco;
    //}

    //size_t index = 0;

    //for (size_t row = 0; row < rails; row++) {
        //size_t step1 = 2 * (rails - row - 1);
        //size_t step2 = 2 * row;

        //size_t pos = row;

        //while (pos < len) {
            //enco[index++] = text[pos];

            //if (step2 != 0 && pos + step2 < len)
                //enco[index++] = text[pos + step2];

            //pos += step1 + step2;
        //}
    //}

    //enco[index] = '\0';
    //return enco;
//}