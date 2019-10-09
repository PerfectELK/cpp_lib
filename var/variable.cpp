#include "../hash/hash_table.h"


namespace pelk{

    var::var(hash_table V) {
        this->type = "hash_table";
        hash_table *M = new hash_table();
        *M = V;
        this->val.HashTable = M;
    }

    var::operator hash_table(){
        return *this->val.HashTable;
    }

    ostream&  operator<<(ostream &out, var &V) {
        if (V.type == "string") {
            if (V.val.String == nullptr) {
                return out;
            }
            out << *V.val.String;
        } else if (V.type == "integer") {
            out << (int) V;
        } else if (V.type == "long") {
            out << (long) V;
        } else if (V.type == "double") {
            out << (double long) V;
        } else if (V.type == "float") {
            out << (float) V;
        } else if (V.type == "hash_table") {
            V.val.HashTable->var_dump();
        }else if (V.type == "array"){
            V.val.Array->var_dump();
        }
        return out;
    }
}





