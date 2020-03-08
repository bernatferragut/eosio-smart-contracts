#include <eosio/eosio.hpp>

using namespace std;
using namespace eosio;

CONTRACT dogstable : public contract {
  public:
    using contract::contract;
    // constructor
    dogstable(name receiver, name code, datastream<const char*> ds):contract(receiver, code, ds) {}
    // functions
    ACTION insert(name from, string dogname, int dogage);

  private:
    TABLE dog {
      int     id;
      name    from;
      string  dogname;
      int     dogage;
      auto primary_key() const { return id; }
    };
    typedef multi_index<name("dogstable"), dog> dog_table;
};
