#include<iostream>
#include <cassert>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// A red-black tree table storing ints and their order
// statistics. Note that since the tree uses
// tree_order_statistics_node_update as its update policy, then it
// includes its methods by_order and order_of_key.
typedef 
    tree<int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
orderedList;

int main(int argc, char const *argv[])
{
    /* code */
    orderedList a;
    a.insert(5);
    a.insert(15);
    a.insert(25);
    a.insert(12);
    a.insert(25);
    a.insert(19);
    a.insert(13);
    
    cout<<*a.find_by_order(4)<<endl;
    cout<<a.order_of_key(4)<<endl;
    
    return 0;
}
