# EOSIO - Smart Contracts

c++```
#include <eosio/eosio.hpp>
class [[eosio::contract('Hello Bernat Contract')]] hello : public eosio::contract {
   public:
      using eosio::contract::contract;
      [[eosio::action]]
      void hi() {
         eosio::print_f("Hello, Bernat!!!\n");
      }
};
```

We need to define this class as an eosio contract. 

This requires that you inherit from the eosio::contract class (this is found in contract.hpp). 
You will also need to add the attribute [[eosio::contract]] to direct the compiler to generate the main dispatcher and for ABI generation.

```class [[eosio::contract]] hello : public eosio::contract {```
Note that you can explicitly name this attribute.

```class [[eosio::contract(“hello_contract”)]] hello : public eosio::contract {```

The first example will use the name of the class itself for the attribute name.
The attribute name is ultimately used to logical connect actions, tables and notification
handlers to a specific compiled smart contract.

This line is used to tell the compiler to use the constructors of the base class.
      using eosio::contract::contract;
You need to mark a method as an eosio::action. This will be an entry point into your smart contract (more on this in the next slide).
```[[eosio::action]]
      void hi() {
         eosio::print_f("Hello, World\n");
      }
};```
This can be invoked with cleos push action <account> hi ‘[]’ -p <account>.