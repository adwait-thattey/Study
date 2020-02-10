/*
* The assignment is to make a discrete event simulator that can simulate the following 2 algorithms
* Odd-Even Transposition Sort
* Sasaki Distributed sort
* Median sort
 */
package main

import (
	"fmt"
	"math/rand"
	"os"
	"sort"
	"strconv"
	"time"
	//"os"
)

type Message struct {
	pid   int
	msg   string
	round int
	val   interface{}
}

type Processor struct {
	id       int
	round    int
	data     map[string]int
	channels map[string]chan Message
}

type Algorithm interface {
	getMaxRounds() int
	buildNodes([]Processor)
	runAlgo()
}

/**
***********************************************
**** Sorting Algorithms Begin *****************
***********************************************
**/

/**
***********************************************
**** Odd Even Transposition Sort **************
***********************************************
**/
type OddEvenTranspositionSort struct {
	nodes []Processor
}

func (algoPtr *OddEvenTranspositionSort) buildNodes(nodes []Processor) {
	(*algoPtr).nodes = nodes
}

func (algoPtr *OddEvenTranspositionSort) runNode(nodePtr *Processor) {
	node := *nodePtr
	// fmt.Printf("[Node %d] Started Round %d\n", node.id, node.round)
	sendIter := func() {
		// fmt.Printf("[Node %d Turn to send\n", node.id)
		if rightChan, ok := node.channels["right"]; ok {
			rightChan <- Message{pid: node.id, msg: "Sending Data", round: node.round, val: node.data["val"]}
			rcvMsg := <-rightChan
			node.data["val"], _ = rcvMsg.val.(int)
		}
	}
	recIter := func() {
		// fmt.Printf("[Node %d Turn to receive\n", node.id)
		if leftChan, ok := node.channels["left"]; ok {
			rcvMsg := <-leftChan
			greater := node.data["val"]
			smaller, _ := rcvMsg.val.(int)
			if greater < smaller {
				greater, smaller = smaller, greater
			}

			node.data["val"] = greater
			leftChan <- Message{pid: node.id, msg: "Sending Data", round: node.round, val: smaller}
		}
	}
	// node.channels["observer"] <- Message{pid: node.id, round: 1, msg: "Hello", val: node.data["val"]}
	if node.id%2 == 0 {
		if node.round%2 == 1 {
			// even node, odd round
			// initiate send
			sendIter()
		}
		if node.round%2 == 0 {
			// even node, even round
			// wait for receive
			recIter()
		}
	} else {
		if node.round%2 == 1 {
			// odd node, odd round
			// receive
			recIter()
		}
		if node.round%2 == 0 {
			// odd node, even round
			// send
			sendIter()
		}
	}

	node.channels["observer"] <- Message{pid: node.id, round: node.round, msg: "Round Complete", val: node.data["val"]}
	// fmt.Printf("[Node %d] Completed Round %d\n", node.id, node.round)
}
func (algoPtr *OddEvenTranspositionSort) runAlgo() {
	fmt.Printf("[Algo] Starting Odd Even Transposition Sort\n\n")
	algo := *algoPtr
	for i := 0; i < len(algo.nodes); i++ {
		go func(i int) {
			// fmt.Printf("[Algo] Starting Node %d \n", algo.nodes[i].id)
			for j := 0; j < algo.getMaxRounds(); j++ {
				algo.runNode(&algo.nodes[i])
				algo.nodes[i].round += 1
			}
			// node run complete. Send final message to observer
			node := algo.nodes[i]
			// fmt.Println("Sending final to observer", node.round)
			node.channels["observer"] <- Message{pid: node.id, round: node.round, msg: "Final Output", val: node.data["val"]}

		}(i)
	}
}

func (algoPtr *OddEvenTranspositionSort) getMaxRounds() int {
	return len((*algoPtr).nodes)
}

/**
***********************************************
**** Sasaki N-1 Round Sort ********************
***********************************************
**/

type SasakiSort struct {
	nodes []Processor
}

func (algoPtr *SasakiSort) getMaxRounds() int {
	algo := *algoPtr
	return len(algo.nodes) - 1
}

func (algoPtr *SasakiSort) buildNodes(nodes []Processor) {
	(*algoPtr).nodes = nodes
	for i, _ := range nodes {
		nodes[i].data["lval"] = nodes[i].data["val"]
		nodes[i].data["rval"] = nodes[i].data["val"]
		nodes[i].data["area"] = 0
		nodes[i].data["lmark"] = 0
		nodes[i].data["rmark"] = 0
	}

	nodes[0].data["area"] = -1
	nodes[0].data["rmark"] = 1

	nodes[len(nodes)-1].data["lmark"] = 1

}

func (algoPtr *SasakiSort) runNode(nodePtr *Processor) {
	/*
		1. send to right
		2. receive from left, put greater in lval
		3. send lower to left
		4. update area based on mark
		5. receive lower from right and put in rval
		6. reorder within
	*/

	node := *nodePtr

	if rchan, ok := node.channels["right"]; ok {
		//step 1
		rchan <- Message{pid: node.id, msg: "Sending Data", round: node.round, val: []int{node.data["rval"], node.data["rmark"]}}
	}
	if lchan, ok := node.channels["left"]; ok {
		//step 2
		original_lmark := node.data["lmark"]
		rcv_data := (<-lchan).val.([]int)

		// prepare to send back message assuming received message is smaller
		send_msg := Message{pid: node.id, msg: "", round: node.round, val: []int{rcv_data[0], rcv_data[1]}}

		// check if assumption correct and change
		if rcv_data[0] > node.data["lval"] {
			send_msg.val = []int{node.data["lval"], node.data["lmark"]}
			node.data["lval"] = rcv_data[0]
			node.data["lmark"] = rcv_data[1]
		}

		// send back (step 3)
		lchan <- send_msg
		// update area (step 4)
		node.data["area"] -= node.data["lmark"] - original_lmark
	}
	if rchan, ok := node.channels["right"]; ok {
		//step 5
		rmsg_val, _ := (<-rchan).val.([]int)
		node.data["rval"] = rmsg_val[0]
		node.data["rmark"] = rmsg_val[1]
	}
	// reorder within (step 6)
	// everyone reorders except first and last node
	_, lok := node.channels["right"]
	_, rok := node.channels["left"]

	if lok && rok { // to ensure 1st and last node are not captured
		if node.data["lval"] > node.data["rval"] {
			node.data["lval"], node.data["rval"] = node.data["rval"], node.data["lval"]
			node.data["lmark"], node.data["rmark"] = node.data["rmark"], node.data["lmark"]
		}
		// send to observer as an array of strings having representation for mark
		observerValue := make([]string, 2, 2)
		observerValue[0] = strconv.Itoa(node.data["lval"])
		observerValue[1] = strconv.Itoa(node.data["rval"])

		if node.data["lval"] >= 0 {
			observerValue[0] = " " + observerValue[0] // for printing purposes
		}
		if node.data["rval"] >= 0 {
			observerValue[1] = " " + observerValue[1] // for printing purposes
		}

		if node.data["lmark"] == 1 {
			observerValue[0] += "`"
		} else {
			observerValue[0] += " " // for proper printing purposes
		}

		if node.data["rmark"] == 1 {
			observerValue[1] += "`"
		} else {
			observerValue[1] += " " // for proper printing purposes
		}

		node.channels["observer"] <- Message{
			pid:   node.id,
			msg:   "Sending to observer",
			round: node.round,
			val:   observerValue,
		}
	} else if !rok {
		// first node
		send_str := strconv.Itoa(node.data["rval"])
		if node.data["rval"] >= 0 {
			send_str = " " + send_str // for printing purposes
		}
		if node.data["rmark"] == 1 {
			send_str += "`"
		} else {
			send_str += " "
		}
		node.channels["observer"] <- Message{
			pid:   node.id,
			msg:   "Sending to observer",
			round: node.round,
			val:   send_str,
		}
	} else if !lok {
		// last node
		send_str := strconv.Itoa(node.data["lval"])
		if node.data["lval"] >= 0 {
			send_str = " " + send_str // for printing purposes
		}
		if node.data["lmark"] == 1 {
			send_str += "`"
		} else {
			send_str += " "
		}
		node.channels["observer"] <- Message{
			pid:   node.id,
			msg:   "Sending to observer",
			round: node.round,
			val:   send_str,
		}
	}

}

func (algoPtr *SasakiSort) runAlgo() {
	fmt.Printf("[Algo] Starting Sasaki n-1 round  Sort\n ` refers to the marked element\n\n")
	algo := *algoPtr

	fmt.Printf("[Algo] Pre run state:\n")

	fmt.Printf("             %d` ", algo.nodes[0].data["rval"])
	for i := 1; i < len(algo.nodes)-1; i++ {
		node := algo.nodes[i]
		observerValue := make([]string, 2, 2)
		observerValue[0] = strconv.Itoa(node.data["lval"])
		observerValue[1] = strconv.Itoa(node.data["rval"])
		if node.data["lmark"] == 1 {
			observerValue[0] += "`"
		}
		if node.data["rmark"] == 1 {
			observerValue[1] += "`"
		}
		fmt.Printf("%v ", observerValue)
	}
	fmt.Printf("%d` ", algo.nodes[len(algo.nodes)-1].data["lval"])

	fmt.Printf("\n\n")
	for i := 0; i < len(algo.nodes); i++ {
		go func(i int) {
			// fmt.Printf("[Algo] Starting Node %d \n", algo.nodes[i].id)
			for j := 0; j < algo.getMaxRounds(); j++ {
				algo.runNode(&algo.nodes[i])
				algo.nodes[i].round += 1
			}
			// final run complete. Compile result based on area
			node := algo.nodes[i]
			if node.data["area"] == -1 {
				node.data["val"] = node.data["rval"]
			} else if node.data["area"] == 0 || node.data["area"] == 1 {
				node.data["val"] = node.data["lval"]
			} else {
				fmt.Printf("\nIllegal State: Area not in [-1, 0, 1]\n %#v", node)
			}

			// first and last node special case
			if i == 0 {
				node.data["val"] = node.data["rval"]
			} else if i == len(algo.nodes)-1 {
				node.data["val"] = node.data["lval"]
			}

			// send result to
			node.channels["observer"] <- Message{pid: node.id, round: node.round, msg: "Final Output", val: node.data["val"]}

		}(i)
	}
}

/**
***********************************************
**** Median Based N-1 Round Sort **************
***********************************************
**/

type MedianSort struct {
	nodes []Processor
}

func (algoPtr *MedianSort) getMaxRounds() int {
	algo := *algoPtr
	return len(algo.nodes) - 1
}

func (algoPtr *MedianSort) buildNodes(nodes []Processor) {
	(*algoPtr).nodes = nodes
	for i, _ := range nodes {
		nodes[i].data["mval"] = (i + 1) % 3
	}
}

func (algoPtr *MedianSort) runNode(nodePtr *Processor) {
	/*
		if media_val is 0, send to right
		if median_val is 2, send to left
		if median_val is 1, receive from both ends, compute and send back
	*/

	node := *nodePtr

	switch node.data["mval"] {
	case 0:
		{
			if rchan, ok := node.channels["right"]; ok {
				// send to right
				rchan <- Message{
					pid:   node.id,
					round: node.round,
					msg:   "Sending to right",
					val:   node.data["val"],
				}

				// receive from right
				rmsg := <-rchan
				node.data["val"], _ = rmsg.val.(int)
			}
		}

	case 2:
		{
			if lchan, ok := node.channels["left"]; ok {
				// send to left
				lchan <- Message{
					pid:   node.id,
					round: node.round,
					msg:   "Sending to left",
					val:   node.data["val"],
				}

				// receive from left
				lmsg := <-lchan
				node.data["val"], _ = lmsg.val.(int)
			}
		}

	case 1:
		{
			lchan, lok := node.channels["left"]
			rchan, rok := node.channels["right"]
			var lval, rval int

			// receive from left
			if lok {
				lmsg := <-lchan
				lval = lmsg.val.(int)
			}
			if rok {
				rmsg := <-rchan
				rval = rmsg.val.(int)
			}

			if lok && rok {
				// both channels present. Sort 3 numbers
				a := lval
				b := node.data["val"]
				c := rval

				if a > b {
					a, b = b, a
				}

				if b > c {
					b, c = c, b
				}

				if a > b {
					a, b = b, a
				}

				lval = a
				node.data["val"] = b
				rval = c
			} else if lok {
				// only left channel present. Sort 2 numbers
				if lval > node.data["val"] {
					lval, node.data["val"] = node.data["val"], lval
				}
			} else if rok {
				// only right channel present. Sort 2 numbers
				if node.data["val"] > rval {
					node.data["val"], rval = rval, node.data["val"]
				}
			}

			if lok {
				// send to left
				lchan <- Message{
					pid:   node.id,
					round: node.round,
					msg:   "Sending Least",
					val:   lval,
				}
			}

			if rok {
				// send to left
				rchan <- Message{
					pid:   node.id,
					round: node.round,
					msg:   "Sending Least",
					val:   rval,
				}
			}

		}

	}

	node.channels["observer"] <- Message{
		pid:   node.id,
		round: node.round,
		msg:   "Sending Val",
		val:   node.data["val"],
	}

}

func (algoPtr *MedianSort) runAlgo() {
	fmt.Printf("[Algo] Starting Median n-1 round  Sort\n ` refers to the marked element\n\n")
	algo := *algoPtr

	for i := 0; i < len(algo.nodes); i++ {
		go func(i int) {
			// fmt.Printf("[Algo] Starting Node %d \n", algo.nodes[i].id)
			for j := 0; j < algo.getMaxRounds(); j++ {
				algo.runNode(&algo.nodes[i])
				algo.nodes[i].round += 1
				algo.nodes[i].data["mval"] += 1
				algo.nodes[i].data["mval"] %= 3

			}
			// node run complete. Send final message to observer
			node := algo.nodes[i]
			// fmt.Println("Sending final to observer", node.round)
			node.channels["observer"] <- Message{pid: node.id, round: node.round, msg: "Final Output", val: node.data["val"]}

		}(i)

	}
}

/**
***********************************************
**** Sorting Algorithms End *******************
***********************************************
**/

func central_observer(algo Algorithm, observer_channel chan Message, n int) {
	max_rounds := algo.getMaxRounds()
	rounds := make([]map[int]interface{}, 0, max_rounds+1) // max_rounds +1 to hold the final state
	for i := 0; i < max_rounds+1; i++ {
		tmp_map := map[int]interface{}{}
		rounds = append(rounds, tmp_map)
	}
	for ix, round_map := range rounds {
		round_printer := make([]interface{}, n, n)
		for len(round_map) < n {
			message := <-observer_channel
			if message.round <= n+1 {
				rounds[message.round-1][message.pid] = message.val
			}

		}

		for j, _ := range round_printer {
			round_printer[j] = round_map[j]
		}
		if ix < max_rounds {
			fmt.Printf("[Observer] Round %d Complete\n", ix+1)
		} else {
			fmt.Printf("-----\n[Observer] Algo run complete. Final Output:\n")
		}
		// fmt.Printf("[Observer] %v\n\n", round_printer)
	}

}

func buildProcesor(id int, val int, global_observer chan Message) Processor {
	data_map := map[string]int{
		"val": val,
	}

	channels := map[string]chan Message{
		"observer": global_observer,
	}
	p := Processor{
		id:       id,
		round:    1,
		data:     data_map,
		channels: channels,
	}

	return p
}

func buildLineNetwork(nodes []Processor) {

	for i := 1; i < len(nodes); i++ {
		new_chan := make(chan Message)
		nodes[i-1].channels["right"] = new_chan
		nodes[i].channels["left"] = new_chan
	}
}
func buildNetwork(algo Algorithm, values []int) chan Message {
	observer_channel := make(chan Message)
	nodes := make([]Processor, 0, len(values))
	for index, val := range values {
		p := buildProcesor(index, val, observer_channel)
		nodes = append(nodes, p)
	}
	buildLineNetwork(nodes)
	algo.buildNodes(nodes)

	return observer_channel
}
func printHelp() {
	fmt.Println(`
	Usage: ./result.out [algorithm_code] [input_size] [input_type]
	result.out is the name of file. (change if different)
	
	[algorithm_code] refers to which algo should be applied 
		- 1 : Odd-Even Transposition Sort
		- 2 : Sasaki n-1 round sort
		- 3 : Median based n-1 round sort
	
	[input_size] is the number of integers that need to be sorted

	[input_type] refers to the order in which integers are generated
		- 1 : Generates sorted sequence
		- 2 : Generates random sequence
		- 3 : Generates reverse sorted sequence)

	Example: ./result.out 1 10 1
	Will generate 10 random numbers and sort them using Odd Even Transposition sort)

	Example: ./result.out 2 5 3
	Will generate 5 reverse sorted numbers and sort them using Median Based n-1 sort

	`)
}
func parseArgs() (Algorithm, []int) {
	if len(os.Args) < 4 {
		printHelp()
		os.Exit(-1)
	}
	n, _ := strconv.Atoi(os.Args[2])
	values := make([]int, n, n)
	for i := 0; i < n; i++ {
		rint := rand.Intn(100)
		rbool := rand.Intn(2) // rbool = 1 means positive, 0 means negative
		if rbool == 0 {
			rint *= -1
		}
		values[i] = rint
	}
	ty, _ := strconv.Atoi(os.Args[3])
	if ty == 1 {
		// sorted sequence
		fmt.Printf("[Main Thread] Generating sorted sequence of %d elements\n\n", n)
		sort.Ints(values)
	} else if ty == 3 {
		// reverse sorted seq
		fmt.Printf("[Main Thread] Generating reverse sorted sequence of %d elements\n\n", n)
		sort.Sort(sort.Reverse(sort.IntSlice(values)))
	} else {
		fmt.Printf("[Main Thread] Generating random sequence of %d elements\n\n", n)
	}

	var algo Algorithm

	al_type, _ := strconv.Atoi(os.Args[1])
	if al_type == 1 {
		// Odd even sort
		algo = &OddEvenTranspositionSort{}
	} else if al_type == 2 {
		// Sasaki sort
		algo = &SasakiSort{}
	} else if al_type == 3 {
		// median sort
		algo = &MedianSort{}
	} else {
		fmt.Println("Invalid Input for algo type")
		os.Exit(-1)
	}

	return algo, values
}
func main() {
	rand.Seed(time.Now().UTC().UnixNano())
	algo, values := parseArgs()
	observer_channel := buildNetwork(algo, values)

	// for ix, node := range oddEvenAlgo.nodes {
	// 	fmt.Printf("%d \t %#v\n\n", ix, node)
	// }
	fmt.Printf("[Main Thread] Initial State:\n")
	fmt.Printf("[Main Thread] %v\n\n", values)
	start := time.Now()
	algo.runAlgo()
	central_observer(algo, observer_channel, len(values))
	elapsed := time.Since(start)
	fmt.Printf("\nTotal time taken %s \n", elapsed)
}
