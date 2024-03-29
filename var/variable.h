#include <string>
#include <iostream>


#ifndef variable_h
#define variable_h


using namespace std;



namespace pelk{

    class base_array;
    class hash_table;


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

        union Value {
            int Int;
            long long int Long;
            float Float;
            long double DoubleLong;
            string *String;
            base_array *Array;
            hash_table *HashTable;
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

        var (long V){
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

        var(base_array* V){
            this->type = "array";
            this->val.Array = V;
        }

        var(base_array);

        var(hash_table* V){
            this->type = "hash_table";
            this->val.HashTable = V;
        }

        var(hash_table V);

        var(){
            this->type = "empty";
        }

        var(const var &v){
            *this = v;
        }



        ~var(){}


        operator int(){return this->val.Int;}

        operator long(){return this->val.Long;}

        operator long long int(){return this->val.Long;}

        operator float(){return this->val.Float;}

        operator double long(){return this->val.DoubleLong;}

        operator double(){return this->val.DoubleLong;}

        operator string(){return *(this->val.String);}

        operator base_array*(){ return this->val.Array; }

        operator hash_table*(){ return this->val.HashTable; }

        operator hash_table();


        friend bool operator==(var& V, var&v){
            if (v.type == "string" && V.type == "string"){
                if((string) V == (string) v){
                    return true;
                }
                return false;
            }
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


        var& operator/(var& V){
            if(this->calculatble(V)){
                if (this->type == "string" && V.type == "string"){
                    cerr << "Dues not calculatble types" << endl;
                    exit(10);
                }else{
                    *this = this->getVal() / V.getVal();
                    return *this;
                }
            }else {
                cerr << "Dues not calculatble types" << endl;
                exit(10);
            }
        }

        var& operator*(var& V){
            if(this->calculatble(V)){
                if (this->type == "string" && V.type == "string"){
                    cerr << "Dues not calculatble types" << endl;
                    exit(10);
                }else{
                    *this = this->getVal() * V.getVal();
                    return *this;
                }
            }else {
                cerr << "Dues not calculatble types" << endl;
                exit(10);
            }
        }


        friend ostream& operator<<(ostream& out, var& V);


        friend istream& operator>>(istream &in, var& V){

            auto *S = new string();
            in  >> *S;
            V.type = "string";
            V.val.String = S;

            return in;
        }

    };


}

#endif
