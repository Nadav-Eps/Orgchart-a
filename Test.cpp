#include "doctest.h"
#include "OrgChart.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <vector>
using std::string;
using std::vector;
using std::endl;
using std::cout;
using namespace ariel;

TEST_CASE("Check function dont fail "){

    OrgChart organization;
    CHECK_NOTHROW(organization.add_root("CEO"));
    CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));         // Now the CTO is subordinate to the CEO
    CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));         // Now the CFO is subordinate to the CEO
    CHECK_NOTHROW(organization.add_sub("CEO", "COO"));         // Now the COO is subordinate to the CEO
    CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW")); // Now the VP Software is subordinate to the CTO
    CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));

    CHECK_NOTHROW(organization.begin_level_order());
    CHECK_NOTHROW(organization.end_level_order());
    CHECK_NOTHROW(organization.begin_reverse_order());
    CHECK_NOTHROW(organization.reverse_order());
    CHECK_NOTHROW(organization.begin_preorder());
    CHECK_NOTHROW(organization.end_preorder());
    CHECK_NOTHROW(organization.begin());
    CHECK_NOTHROW(organization.end());

    CHECK_NOTHROW(cout<<organization<<endl);
    }
TEST_CASE("Building new tree (not from demo)"){
    OrgChart nadavs;
     CHECK_NOTHROW(nadavs.add_root("nadav"));
    CHECK_NOTHROW(nadavs.add_sub("nadav", "son"));         
    CHECK_NOTHROW(nadavs.add_sub("nadav", "daughter"));        
    CHECK_NOTHROW(nadavs.add_sub("nadav", "adopted"));        
    CHECK_NOTHROW(nadavs.add_sub("son", "grandson")); 
    CHECK_NOTHROW(nadavs.add_sub("atopted", "brother"));

}    

TEST_CASE("Building and printing trees"){
    OrgChart organization;
    organization.add_root("CEO")
      .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
      .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
      .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
      .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
      .add_sub("COO", "VP_BI");
    std::vector<string> lvl_order{"CEO", "CTO", "CFO", "COO", "VP_SW", "VP_BI"};
      size_t l_o =0;
      for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
        {
            CHECK((*it).n_name==lvl_order.at(l_o));
            l_o++;
            printf("gh");
        } 
        
    size_t r_o=0;    
    std::vector<string> rvr_order{"VP_BI", "VP_SW", "COO", "CFO", "CTO","CEO"};    
        for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
        {
            CHECK((*it).n_name==rvr_order.at(r_o));
            r_o++;
        }

        ; 
    size_t p_o=0;
    std::vector<string> pre_order{"CEO", "CTO", "VP_SW", "CFO", "COO", "VP_BI"};
    for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) 
        {
            CHECK((*it).n_name==pre_order.at(p_o));
            p_o++;
        }  

    CHECK(organization.begin_level_order()==organization.begin());
    cout << organization << endl; /* Prints the org chart in a reasonable format. For example:
       CEO
       |--------|--------|
       CTO      CFO      COO
       |                 |
       VP_SW             VP_BI
 */
    

}