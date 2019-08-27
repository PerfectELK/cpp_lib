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

        int Int(){
            return this->val.Int;
        }

        long long int Lli(){
            return this->val.Long;
        }

        float Float(){
            return this->val.Float;
        }

        long double longDouble(){
            return this->val.DoubleLong;
        }

        string String(){
            return *this->val.String;
        }

        bool calculatble(var &V){
            if(this->type == "string" && V.type == "string"){
                return true;
            }else if(this->type == "string" || V.type == "string"){
                return false;
            }
            return true;
        }


        long double getVal(){

            if(this->type == "string"){
                return false;
            }else if(this->type == "integer"){
                return this->val.Int;
            }else if(this->type == "float"){
                return this->val.Float;
            }else if(this->type == "double"){
                return this->val.DoubleLong;
            }else if(this->type == "long"){
                return this->val.Long;
            }

        }


    public:



        union Value{
            int Int;
            long long int Long;
            float Float;
            long double DoubleLong;
            string *String;
            Value(){};
            ~Value(){};
        } val;

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

        var(double V){
            this->type = "double";
            this->val.DoubleLong = V;
        }

        var(){
            this->type = "empty";
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
            if((V - v).getVal() == 0){
                return true;
            }
            return false;
        }

        friend bool operator!=(var& V, var&v){
            if((V - v).getVal() != 0){
                return true;
            }
            return false;
        }

        friend bool operator<=(var& V, var&v){
            if((V - v).getVal() > 0){
                return false;
            }
            return true;
        }

        friend bool operator>=(var& V, var&v){
            if((V - v).getVal() >= 0){
                return true;
            }
            return false;
        }

        friend bool operator<(var& V, var&v){
            if((V - v).getVal() >= 0){
                return false;
            }
            return true;
        }

        friend bool operator>(var& V, var&v){
            if((V - v).getVal() > 0){
                return true;
            }
            return false;
        }

        var& operator+(var &V){
            if(this->calculatble(V)){
                if (this->type == "string" && V.type == "string"){
                    string *str = new string();
                    *str = this->String() + V.String();
                    this->val.String = str;
                    return *this;
                }else{
                    *this = this->getVal() + V.getVal();
                    return *this;
                }
            }else {
                cerr << "Dues not calculatble types" << endl;
                exit(10);
            }
        }

        var& operator-(var &V){
            if(this->calculatble(V)){
                if (this->type == "string" && V.type == "string"){
                    cerr << "Dues not calculatble types" << endl;
                    exit(10);
                }else{
                    *this = this->getVal() - V.getVal();
                    return *this;
                }
            }else {
                cerr << "Dues not calculatble types" << endl;
                exit(10);
            }
        }



        var operator++(int V){
            if(this->calculatble(*this)){
                if (this->type == "string"){
                    cerr << "Increment does not possible" << endl;
                    exit(10);
                }else{
                    *this = this->getVal() + 1;
                    return *this;
                }
            }else {
                cerr << "Increment does not possible" << endl;
                exit(10);
            }
        }

        var& operator++(){
            if(this->calculatble(*this)){
                if (this->type == "string"){
                    cerr << "Increment does not possible" << endl;
                    exit(10);
                }else{
                    *this = this->getVal() + 1;
                    return *this;
                }
            }else {
                cerr << "Increment does not possible" << endl;
                exit(10);
            }
        }


        var operator--(int V){
            if(this->calculatble(*this)){
                if (this->type == "string"){
                    cerr << "Decrement does not possible" << endl;
                    exit(10);
                }else{
                    *this = this->getVal() - 1;
                    return *this;
                }
            }else {
                cerr << "Decrement does not possible" << endl;
                exit(10);
            }
        }

        var& operator--(){
            if(this->calculatble(*this)){
                if (this->type == "string"){
                    cerr << "Decrement does not possible" << endl;
                    exit(10);
                }else{
                    *this = this->getVal() - 1;
                    return *this;
                }
            }else {
                cerr << "Decrement does not possible" << endl;
                exit(10);
            }
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
            }else if(V.type == "double"){
                out << (double long) V;
            }else if(V.type == "float"){
                out << (float) V;
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
