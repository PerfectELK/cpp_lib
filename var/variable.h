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
            long long int Long;
            float Float;
            long double DoubleLong;
            string *String;
            Value(){};
            ~Value(){};
        } val;

        var getCurrentValue(){
            if(this->type == "integer"){
                return this->val.Int;
            }else if(this->type == "long"){
                return this->val.Long;
            }else if(this->type == "float"){
                return this->val.Float;
            }else if(this->type == "double"){
                return this->val.DoubleLong;
            }else if(this->type == "string"){
                return *(this->val.String);
            }
            return false;
        }

    public:

        string type;

        var(int V){
            this->type = "integer";
            this->val.Int = V;
        }

        var(long long int V){
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

        var(float V){
            this->type = "float";
            this->val.Float = V;
        }

        var(long double V){
            this->type = "double";
            this->val.DoubleLong = V;
        }



        ~var(){}


        operator int(){return this->val.Int;}

        operator long(){return this->val.Long;}

        operator long long int(){return this->val.Long;}

        operator float(){return this->val.Float;}

        operator double long(){return this->val.DoubleLong;}

        operator double(){return this->val.DoubleLong;}

        operator string(){return *(this->val.String);}



        friend bool operator==(var& V, var&v){
            return (double long) V.getCurrentValue() == (double long) v.getCurrentValue();
        }

        friend bool operator!=(var& V, var&v){
            return (double long) V.getCurrentValue() != (double long) v.getCurrentValue();
        }

        friend bool operator<=(var& V, var&v){
            return (double long) V.getCurrentValue() <= (double long) v.getCurrentValue();
        }

        friend bool operator>=(var& V, var&v){
            return (double long) V.getCurrentValue() >= (double long) v.getCurrentValue();
        }

        friend bool operator<(var& V, var&v){
            return (double long) V.getCurrentValue() < (double long) v.getCurrentValue();
        }

        friend bool operator>(var& V, var&v){
            return (double long) V.getCurrentValue() > (double long) v.getCurrentValue();
        }

        friend var& operator+(var &V, var &v){

             return ((double long) V + (double long) v);
        }

        friend var& operator++(var& V){
             var v = 1;
             return V + v;
        }

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
