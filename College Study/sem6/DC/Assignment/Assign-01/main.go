/*
* The assignment is to make a discrete event simulator that can simulate the following 2 algorithms
* Odd-Even Transposition Sort
* Sasaki Distributed sort
* Median sort
 */
package main

import "fmt"

type Message struct {
	pid   int
	msg   string
	round int
	val   int
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

type OddEvenTranspositionSort struct {
	nodes      []Processor
	max_rounds int
}

func (algo OddEvenTranspositionSort) buildNodes([]Processor) {

}

func (algo OddEvenTranspositionSort) runAlgo() {

}

func (algo OddEvenTranspositionSort) getMaxRounds() int {
	return len(algo.nodes)
}

type SasakiSort struct {
	nodes []Processor
}

func central_observer(algo *Algorithm, observer_channel chan Message, n int) {
	max_rounds := (*algo).getMaxRounds()
	rounds := make([]map[int]int, 0, max_rounds)
	for i := 0; i < max_rounds; i++ {
		tmp_map := map[int]int{}
		rounds = append(rounds, tmp_map)
	}

	for ix, round_map := range rounds {
		for len(round_map) < n {
			message := <-observer_channel
			rounds[message.round][message.pid] = message.val
		}

		fmt.Printf("\nRound %d Complete\n", ix)
		fmt.Printf("%#v", round_map)
	}
}

func buildProcesor(id int, val int, global_observer chan Message) Processor {
	data_map := map[string]int{
		"value": val,
	}

	channels := map[string]chan Message{
		"observer": global_observer,
	}
	p := Processor{
		id:       id,
		round:    0,
		data:     data_map,
		channels: channels,
	}

	return p
}

func buildNetwork(algo Algorithm, values []int) chan Message {
	observer_channel := make(chan Message)
	nodes := make([]Processor, 0, len(values))
	for index, val := range values {
		p := buildProcesor(index, val, observer_channel)
		nodes = append(nodes, p)
	}
	algo.buildNodes(nodes)
	return observer_channel
}

func main() {
	fmt.Printf("Hello")
}
