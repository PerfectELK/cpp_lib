//
// Created by pelk on 20.08.2019.
//
#include <string>
#include <iostream>

#ifndef EXAMPLE_PELK_H
#define EXAMPLE_PELK_H

using namespace std;

namespace pelk{



    class variable {
    private:

        union Value{
            int Int;
            long Long;
            string *String;
            Value(){};
            ~Value(){
                delete String;
            };
        } val;

        string type;

    public:

        variable(int V){
            this->type = "integer";
            this->val.Int = V;
        }

        variable(long V){
            this->type = "long";
            this->val.Long = V;
        }

        variable(string V){
            this->type = "string";
            this->val.String = &V;
        }

        variable(char V[]){
            this->type = "string";
            auto *s = new string(V);
            this->val.String = s;
        }

        ~variable(){
        }


        void setVariable(int V){
            this->type = "integer";
            this->val.Int = V;
        }

        void setVariable(long V){
            this->type = "long";
            this->val.Long = V;
        }

        void setVariable(string V){
            this->type = "string";
            this->val.String = &V;
        }


        operator int(){ return this->val.Int;}

        operator long(){ return this->val.Long;}

        operator string(){ return *(this->val.String);}

        variable& operator=(variable& v){
            val = v.val;
            return *this;
        }

        friend ostream& operator<<(ostream& out, variable& V){
            if(V.type == "string"){
                cout << *V.val.String;
            }else if(V.type == "integer"){
                cout << (int) V;
            }else if(V.type == "long"){
                cout << (long) V;
            }
        }


    };


}



#endif //EXAMPLE_PELK_H
