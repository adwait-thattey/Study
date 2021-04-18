There are 2 parts in the code

One is the smart-abac, in which we have written the models for the chaincode
The models are located in smart-abac/chaincode/models


Other is the sample_go_blockchain, which is a simple simulated blockchain written in  go using Proof-of-work consensus algorithm
go into sample_go_blockchain/ and run
> go get .
> go run .
This will start a tcpo server and create the genesis block
Now go to another terminal, and run
> nc localhost 8000
After that enter the new desired balance
You will see the main server running the POW algo and finding the hash
Once desireed hash is generated, new block will be added and transmitted back to the client terminal
