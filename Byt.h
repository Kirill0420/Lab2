//
// Created by Admin on 20.09.2021.
//

#include "gtest/gtest.h"


namespace Lem {



    class Byt {
    public:
        Byt(){
            c = 1;
            m = 1;
            type = 1;
            a = 3;
            b = 2;
        }
        double getA() const {return a;}
        double getB() const{return b;}
        int getC() const{return c;}
        int getM() const {return m;}
        int getT() const {return type;};
        void set(int C, int M){
            if (C == 2*M*M || C == 0)
                throw std::exception("It is not But's lemniscate.");
            c = C;
            m = M;
            if (c > 2*m*m)
                type = 0;
            if(c < 2*m*m)
                type = 1;
            if(type == 1) {
                a = 2 * M * M + C;
                b = 2 * M * M - C;
                std::cout<<a<<" "<<b<<std::endl;
            }
            if(type == 0) {
                a = 2 * M * M + C;
                b = C - 2 * M * M;
            }
        }
        double Area (){
            double S;
            if (type == 0){
                std::cout<<"Type: elliptical"<<std::endl;
                S = 3.14159*(a+b)/2;
                std::cout<<"Area = "<<S<<std::endl;
                return S;
            }
            if (type == 1){
                std::cout<<"Type: hyperbolic"<<std::endl;
                S = ((a-b)/2)*atan(sqrt(a)/sqrt(b)) + sqrt(a)*sqrt(b)/2;
                std::cout<<"Area = "<<S<<std::endl;
                return S;
            }
        };
        char* frm(){
            if(type == 1) {
                char s1[] = "p^2 = ( * (cosQ)^2) - ( * (sinQ))^2";
                int l = strlen(s1) + 1;
                char num[20];
                sprintf_s(num, 20, "%.2f", a);
                l += strlen(num);
                sprintf_s(num, 20, "%.2f", b);
                l += strlen(num);
                char *s = new char[l];
                sprintf_s(s, l, "p^2 = (%.2f * (cosQ)^2) - (%.2f * (sinQ))^2", a, b);
                std::cout << s << std::endl;
                return s;
            }
            if(type == 0){
                char s1[] = "p^2 = ( * (cosQ)^2) + ( * (sinQ))^2";
                int l = strlen(s1) + 1;
                char num[20];
                sprintf_s(num, 20, "%.2f", a);
                l += strlen(num);
                sprintf_s(num, 20, "%.2f", b);
                l += strlen(num);
                char *s = new char[l];
                sprintf_s(s, l, "p^2 = (%.2f * (cosQ)^2) + (%.2f * (sinQ))^2", a, b);
                std::cout << s << std::endl;
                return s;
            }
        };
        double Distance(double q){
            q = q*3.14159/180;
            if(type == 0) {
                double p = sqrt((a * pow(cos(q), 2)) + (b * pow(sin(q), 2)));
                return p;
            }
            if(type == 1){
               double p = sqrt((a * pow(cos(q), 2)) + (b * pow(sin(q), 2)));
               return p;
            }
        };
    private:
        int type;  // 0 - эллиптическая, 1 - гиперболическая, 2 - две окружности, 3 - лемниската Бернулли
        int c;
        int m;
        double a;
        double b;
    };




    template <typename T>
    int getNum(T &a){
        std::cin >> a;
        if(!std::cin.good())
            return 0; //неудачный ввод
        return 1;
    }

    int menu();

}