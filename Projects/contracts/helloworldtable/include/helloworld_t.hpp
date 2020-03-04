#include <eosio/eosio.hpp>

using namespace std;
using namespace eosio;

CONTRACT helloworld_t : public contract {
  public:
    using contract::contract;

    ACTION insert(name from, string dogname, int dogage);
    ACTION clear();

  private:
    TABLE messages {
      int      id;
      name    user;
      string  dogname;
      int     dogage;
      auto primary_key() const { return id; }
    };
    typedef multi_index<name("messages"), messages> messages_table;
};
