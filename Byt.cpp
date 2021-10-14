//
// Created by Admin on 20.09.2021.
//

#include<iostream>
//#include "gtest/gtest.h"
#include "Byt.h"

namespace Lem{
    int menu(){
        int q;
        Byt a;
        do{
            std::cout<<"1. New Class"<<std::endl<<"2. Area"<<std::endl<<"3. Equation"<<std::endl<<"4. Distance"<<std::endl<<"0. Quit"<<std::endl;
            getNum(q);
            if(q != 1 && q != 0 && q!= 2 && q!= 3 && q!= 4)
                continue;
            if(q == 1){
                int C;
                int M;
                std::cout<<"c = ";
                getNum(C);
                std::cout<<std::endl<<"m = ";
                getNum(M);
                std::cout<<std::endl;
                a.set(C, M);
            }
            if(q == 2)
                a.Area();
            if(q == 3)
                a.frm();
            if (q == 4) {
                std::cout<<"Corner = ";
                double Q;
                getNum(Q);
                std::cout<<std::endl<<a.Distance(Q)<<std::endl;
            }
        }while(q != 0);
        return 0;
    }
}

