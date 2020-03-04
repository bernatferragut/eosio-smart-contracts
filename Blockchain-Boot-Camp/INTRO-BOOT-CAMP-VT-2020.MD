
**https://cs.vt.edu/blockchain/bootcamp.html**

# The second Virginia Tech Blockchain Boot Camp, hosted by the Department of Computer Science,  was on Jan. 18, 2020 at Goodwin Hall Auditorium on Virginia Tech's campus. 

## The morning was dedicated to the history and evolution of blockchain and the basics of the technology. In the afternoon, students received hands-on experience using blockchain applications.

## The boot camp, led by Virginia Tech faculty with blockchain industry engineers, serves as the kickstart to a blitz of university spring blockchain events. It gives computer science and noncomputer science majors alike a taste of how blockchain technology works and what it can do. 

## Over the spring 2020 semester, students will be eligibe to participate in a semester-long blockchain application development competition. 

## Presenter slides and other resources from the boot camp can be found below.

> Get Started with Blockchain Technology

# WHAT IS EOSIO?

As a developer you will either be interacting with the tool cleos directly or with an eosjs frontend. Both of these will interact with the nodeos through the RPC API. 

## Using CLEOS commands:

cleos get info
cleos set code <account> <path-to-contract>/<contract>.wasm 
cleos set abi <account> <path-to-abi>/<contract>.abi 
cleos create account <creator> <account name> <public key> 

## What is an action?
There are two definitions based on context:
* An action is a function in a Webassembly binary that will be invoked with a push action command and invoked with a set of parameters given to it as a payload of data. This definition is used when talking about actions when developing the smart contract.
* An action is an eosio name for the account this action is going to be run against, an eosio name for the action name itself and a payload of data to act on. This is the definition used when looking at transactions and when interfacing with cleos or EOSJS.

## What is a transaction?
A transaction is a set of actions. Possibly one action, and for most of the
cleos commands this will be only one, but N actions can comprise a
transaction.  The transaction also contains the set of authorizations that
authorized it.

## What is an eosio name?
An eosio name is a string that is encoded into a 64 bit variable.  As such it
has some none obvious restrictions on them.  They can be 12 characters long,
and a character can only be one of [abcdefghijlmnopqrstuvxyz.12345]. These are
used for account names, permission names, action names, table names,
notification handler names, and secondary index names.

## What is an eosio symbol?
An eosio symbol is an all uppercase string of 7 or less characters from [A-Z]
and a precision.
The precision is used to determine how many decimal places are there, this is
a fixed point system.
We will see this in more detail when we talk about eosio.token.

## What is an eosio intrinsic?
Given that the smart contracts are compiled to WebAssembly, creating side
effects outside of the WASM sandbox needs to added.  These are what we refer
to as eosio intrinsics, they act much like syscalls in OS parlance.  These are
things like printing, asserting, table operations.  Some of these intrinsics
are there because of performance concerns, so things like cryptographic
hashing is done through these intrinsics.

## What is an eosio table?
These are persistent data storage used by smart contracts.  These are defined
as either C++ structs or classes.  Intrinsics are available to allow for basic
database operations to act on these tables, so, CRUD operations. These
intrinsics also allow for iteration through the tables and allow the developer
to walk through tables in a manner much like C++ iterators.

## What is an eosio table?
These are persistent data storage used by smart contracts.  These are defined
as either C++ structs or classes.  Intrinsics are available to allow for basic
database operations to act on these tables, so, CRUD operations. These
intrinsics also allow for iteration through the tables and allow the developer
to walk through tables in a manner much like C++ iterators.


## What is WebAssembly (WASM)?
WebAssembly is a platform agnostic assembly language that emphasizes determinism, simplicity and security. 
Nodeos uses WASM as the smart contract language that is executed. 
The developer does not need to implement smart contracts in WebAssembly, a toolchain is provided to compile smart contract written in C++ to this binary format.

## What is an ABI?
This is a data layout and conversion schema for your smart contract. This will
allow tools to interact with your smart contracts in an intelligent way and
pack and unpack data needed by an action or from events.
This is used by cleos to allow for JSON inputs for parameters and generate the
correct binary data needed to satisfy your action and interpret table
structures when querying.  This is also used by EOSJS to do the same type of
things but with the control and expressiveness of Javascript.

## What are smart contracts?
Smart contracts are a blob of code that digitally
facilitate, verify or enforce a contract between N members.
This is general enough of an definition that allows for a
great deal of things to fit into this model.