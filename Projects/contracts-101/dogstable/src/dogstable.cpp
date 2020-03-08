#include <dogstable.hpp>

ACTION dogstable::insert(name from, string dogname, int dogage) {
  require_auth(from);
  // Init the dog table
  dog_table dogstable(get_self(), get_self().value);
      
  dogstable.emplace(from, [&](auto& row) {
    row.dogname = dogname;
    row.dogage = dogage;
    row.from = from;
  });
}

EOSIO_DISPATCH(dogstable, (insert))