#include "OrgChart.hpp"
using namespace std;
using namespace ariel;
namespace ariel{
    OrgChart OrgChart::add_root(string nod){
        return *this;
    };
    OrgChart OrgChart::add_sub(string p1, string p2){
        return *this;
    };

    Iterato OrgChart::begin_level_order(){
        Iterato iter;
        ++iter;
        return iter;
    };

    Iterato OrgChart::end_level_order(){
        Iterato iter;
        ++iter;
        return iter;
    };

    Iterato OrgChart::begin_reverse_order(){
        Iterato iter;
        ++iter;
        return iter;
    };

    Iterato OrgChart::reverse_order(){
        Iterato iter;
        ++iter;
        return iter;
    };

    Iterato OrgChart::begin_preorder(){
        Iterato iter;
        ++iter;
        return iter;
    };

    Iterato OrgChart::end_preorder(){
        Iterato iter;
        ++iter;
        return iter;
    };

    Iterato OrgChart::begin(){
        return begin_level_order();
    }

    Iterato OrgChart::end(){
        return end_level_order();
    }
    std::ostream &operator << (ostream &ot , const OrgChart &no){
        ot<<"n";
        return (ot);
    };


}