#include <iostream>
using std::string;
using std::invalid_argument;
using std::ostream;

namespace ariel{
    class Iterato;
    class Node;
    class OrgChart{
        public:

        OrgChart(){};
        OrgChart add_root(string nod);
        OrgChart add_sub(string p1, string p2);
        Iterato begin_level_order();
        Iterato end_level_order();
        Iterato begin_reverse_order();
        Iterato reverse_order();
        Iterato begin_preorder();
        Iterato end_preorder();
        Iterato begin();
        Iterato end();      
        friend ostream &operator << ( ostream &ot, const OrgChart &no);

    };
    class Node{  //Ineer class
        public :
        string n_name;

        Node(){};
        friend ostream &operator << ( ostream &ot, const Node &nod){
            ot << "i";
            return(ot);
        };
    };

    class Iterato{ //Innner class
        public:

        Iterato(){};
        Node operator*(){return Node();};
        Iterato operator++(){return *this;};
        string* operator->() const{return nullptr;};
        bool operator == (const Iterato &iter)const{return false;};
        bool operator != (const Iterato &iter)const{return false;};
            
            };
    
}
