//
// Created by pelk on 20.08.2019.
//
#include <string>
#include <iostream>

#ifndef EXAMPLE_PELK_H
#define EXAMPLE_PELK_H

using namespace std;

namespace pelk{



    class var {
    private:

        union Value{
            int Int;
            long Long;
            string *String;
            Value(){};
            ~Value(){};
        } val;

    public:

        string type;

        var(int V){
            this->type = "integer";
            this->val.Int = V;
        }

        var(long V){
            this->type = "long";
            this->val.Long = V;
        }

        var(string V){
            this->type = "string";
            string *str = new string(V);
            this->val.String = str;
        }

        var(char V[]){
            this->type = "string";
            auto *s = new string(V);
            this->val.String = s;
        }

        ~var(){}


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

//        var& operator=(var& v){
//            this->val = v.val;
//            return *this;
//        }

        friend ostream& operator<<(ostream& out, var& V){
            if(V.type == "string"){
                if(V.val.String == nullptr){
                    return out;
                }
                out << *V.val.String;
            }else if(V.type == "integer"){
                out << (int) V;
            }else if(V.type == "long"){
                out << (long) V;
            }
            return out;
        }

        friend istream& operator>>(istream &in, var& V){

            auto *S = new string();
            in  >> *S;
            V.type = "string";
            V.val.String = S;

            return in;
        }



    };



}



#endif //EXAMPLE_PELK_H
