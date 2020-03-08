#include <eosio/eosio.hpp>

using namespace std;
using namespace eosio;

class [[eosio::contract]] hello : public eosio::contract {
   public:
      using eosio::contract::contract;
      [[eosio::action]]
      void hi() {
         eosio::print_f("Hello, World\n");
      }
};