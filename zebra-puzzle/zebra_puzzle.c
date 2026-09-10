#include "zebra_puzzle.h"
#include <string.h>
#include <stdlib.h>

bool next_to(int a, int b){
    return abs(a-b)==1;
}


solution_t solve_puzzle(void){
    solution_t sol={0};

    int norwegian=0;
    //int blue=1;
    //int milk=2;
    for(int red=0;red<5;red++){
        for(int green=0;green<5;green++){
            for(int yellow=0;yellow<5;yellow++){
                for(int ivory=0;ivory<5;ivory++){

                    if(red==green || red==yellow || red==ivory ||
                        yellow==ivory||yellow==green||green==ivory)continue;
                    if(!next_to(green,ivory))continue;

                    for(int englishman=1;englishman<5;englishman++){
                        for(int ukrainian=1;ukrainian<5;ukrainian++){
                            for(int spaniard=1;spaniard<5;spaniard++){
                                for(int japanese=1;japanese<5;japanese++){

                                    if(englishman==ukrainian||englishman==spaniard||englishman==japanese||
                                    ukrainian==spaniard||ukrainian==japanese||spaniard==japanese)continue;
                                    if(englishman!=red)continue;

                                    for(int dog=0;dog<5;dog++){
                                        for(int snail=0;snail<5;snail++){
                                            for(int fox=0;fox<5;fox++){
                                                for(int zebra=0;zebra<5;zebra++){
                                                    for(int horse=0;horse<5;horse++){

                                                        if(dog==snail||dog==fox||dog==zebra||dog==horse||
                                                        snail==fox||snail==zebra||snail==horse||fox==zebra||fox==horse||
                                                        zebra==horse)continue;
                                                        if(dog!=spaniard)continue;

                                                        for(int coffe=0;coffe<5;coffe++){
                                                            for(int tea=0;tea<5;tea++){
                                                                for(int juice=0;juice<5;juice++){
                                                                    for(int water=0;water<5;water++){

                                                                        if(coffe==tea||coffe==juice||coffe==water||
                                                                        tea==juice||tea==water||juice==water)continue;
                                                                        if(green!=coffe)continue;
                                                                        if(ukrainian!=tea)continue;

                                                                        for(int dancing=0;dancing<5;dancing++){
                                                                            for(int painter=0;painter<5;painter++){
                                                                                for(int reading=0;reading<5;reading++){
                                                                                    for(int football=0;football<5;football++){
                                                                                        for(int chess=0;chess<5;chess++){

                                                                                            if(dancing==painter||dancing==reading||dancing==football||dancing==chess||
                                                                                            painter==reading||painter==football||painter==chess||reading==chess||
                                                                                            reading==football||football==chess)continue;

                                                                                            if(snail!=dancing)continue;
                                                                                            if(yellow!=painter)continue;
                                                                                            if(!next_to(reading,fox))continue;
                                                                                            if(!next_to(horse,painter))continue;
                                                                                            if(juice!=football)continue;
                                                                                            if(japanese!=chess)continue;

                                                                                            if(zebra==englishman) sol.owns_zebra="Englishman";
                                                                                            if(zebra==ukrainian) sol.owns_zebra="Ukrainian";
                                                                                            if(zebra==spaniard) sol.owns_zebra="Spaniard";
                                                                                            if(zebra==norwegian) sol.owns_zebra="Norwegian";
                                                                                            if(zebra==japanese) sol.owns_zebra="Japanese";

                                                                                            if(water==englishman) sol.drinks_water="Englishman";
                                                                                            if(water==ukrainian) sol.drinks_water="Ukrainian";
                                                                                            if(water==spaniard) sol.drinks_water="Spaniard";
                                                                                            if(water==norwegian) sol.drinks_water="Norwegian";
                                                                                            if(water==japanese) sol.drinks_water="Japanese";
                                                                                            return sol;
                                                                                        }
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return sol;
}