#include "intergalactic_transmission.h"
#include <stdbool.h>


int transmit_sequence(uint8_t *buffer, const uint8_t *message,int message_length){
    
    if(!message_length)return 0;

    int len=(message_length*8+6)/7;
    int total_bits=message_length*8;

    int bit_index=0;

    for(int out_idx=0;out_idx<len;out_idx++){
        uint8_t chunk_7bit=0;

        for(int b=0;b<7;b++){
            chunk_7bit<<=1;
            int current_bit_pos=bit_index+b;
            if(current_bit_pos<total_bits){
                int byte=current_bit_pos/8;
                int bitoff=7-(current_bit_pos%8);

                if((message[byte]>>bitoff)&1){
                    chunk_7bit|=1;
                }
            }
        }
        bit_index+=7;

        uint8_t tmp=chunk_7bit;
        int num_of_bits=0;
        while(tmp){
            if(tmp&1){
                num_of_bits++;
            }
            tmp>>=1;
        }

        int parity=(num_of_bits%2==0)?0:1;
        buffer[out_idx]=(chunk_7bit<<1)|parity;
    }



    return len;

}




int decode_message(uint8_t *buffer, const uint8_t *message, int message_length){

    if(!message_length || !message || !buffer)return 0;

    int out_byte=0;
    uint32_t bit_accumulator=0;
    int bits_in_accumulator=0;

    for(int i=0;i<message_length;i++){

        int chunks_7bit=message[i]>>1;
        int parity_bit=message[i]&1;

        int ones=0;
        for(int t=chunks_7bit;t>0;t>>=1){
            ones+=t&1;
        }

        if(ones%2!=parity_bit){
            return -1;
        }
        bit_accumulator=(bit_accumulator<<7)|chunks_7bit;
        bits_in_accumulator+=7;
        
        while(bits_in_accumulator>=8){
            bits_in_accumulator-=8;
            buffer[out_byte++]=bit_accumulator>>bits_in_accumulator;
        }

    }
    return out_byte;
}