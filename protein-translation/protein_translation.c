#include "protein_translation.h"
#include <string.h>



protein_t protein(const char *const rna){
    protein_t p;
    p.count=0;
    p.valid=true;
    char codon[4]={0};
    size_t len=strlen(rna);
    for (size_t i=0;rna[i]!='\0';i++){
        codon[(i)%3]=rna[i];
        if((i+1)%3==0){
            if(strcmp(codon,"AUG")==0){
                p.amino_acids[p.count++]=Methionine;
            }else if(strcmp(codon,"UUU")==0 || strcmp(codon,"UUC")==0){
                p.amino_acids[p.count++]=Phenylalanine;
            }else if(strcmp(codon,"UUA")==0 || strcmp(codon,"UUG")==0){
                p.amino_acids[p.count++]=Leucine;
            }else if(strcmp(codon,"UCU")==0 || strcmp(codon,"UCC")==0 ||
                    strcmp(codon,"UCA")==0 || strcmp(codon,"UCG")==0){
                p.amino_acids[p.count++]=Serine;
            }else if(strcmp(codon,"UAU")==0 || strcmp(codon,"UAC")==0){
                p.amino_acids[p.count++]=Tyrosine;
            }else if(strcmp(codon,"UGU")==0 || strcmp(codon,"UGC")==0){
                p.amino_acids[p.count++]=Cysteine;
            }else if(strcmp(codon,"UGG")==0){
                p.amino_acids[p.count++]=Tryptophan;
            }else if(strcmp(codon,"UAA")==0 || strcmp(codon,"UAG")==0 ||
                    strcmp(codon,"UGA")==0){
                        return p;
            }else{
                p.valid=false;
                return p;
            }
            memset(codon,0,4);
        }
    }
    if(len%3!=0){p.valid=false; return p;}
    return p;
}

// AI generated
//#include "protein_translation.h"
//#include <string.h>
//
//static protein p_init(void) {
//    protein_t p = {0};
//    p.valid = true;
//    return p;
//}
//
//protein_t protein(const char *const rna) {
//    protein_t p = p_init();
//
//    for (size_t i = 0; rna[i] != '\0'; i += 3) {
//        char a = rna[i];
//        char b = rna[i + 1];
//        char c = rna[i + 2];
//
//        if (b == '\0' || c == '\0') {
//            p.valid = false;
//            return p;
//        }
//
//        if (a == 'U' && b == 'A' && (c == 'A' || c == 'G')) return p;
//        if (a == 'U' && b == 'G' && c == 'A') return p;
//
//        if (a == 'A' && b == 'U' && c == 'G') {
//            p.amino_acids[p.count++] = Methionine;
//        } else if (a == 'U' && b == 'U' && (c == 'U' || c == 'C')) {
//            p.amino_acids[p.count++] = Phenylalanine;
//        } else if (a == 'U' && b == 'U' && (c == 'A' || c == 'G')) {
//            p.amino_acids[p.count++] = Leucine;
//        } else if (a == 'U' && b == 'C') {
//            p.amino_acids[p.count++] = Serine;
//        } else if (a == 'U' && b == 'A') {
//            p.amino_acids[p.count++] = Tyrosine;
//        } else if (a == 'U' && b == 'G') {
//            if (c == 'U' || c == 'C') {
//                p.amino_acids[p.count++] = Cysteine;
//            } else if (c == 'G') {
//                p.amino_acids[p.count++] = Tryptophan;
//            }
//        } else {
//            p.valid = false;
//            return p;
//        }
//    }
//
//    return p;
//}