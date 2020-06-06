package main

import (
	"fmt"
)

type node struct{
	cityNumber int
	isSource bool
}

func initData(n int, connections [][]int) map[int][]node {
	result := make(map[int][]node)
	for i := 0; i < n-1; i++ {
		sourceCityID := connections[i][0]
		destCityID := connections[i][1]

		itemSource := node {
			cityNumber: sourceCityID,
			isSource: true,
		}

		result[destCityID] = append(result[destCityID], itemSource)

		itemDest := node {
			cityNumber: destCityID,
			isSource: false,
		}

		result[sourceCityID] = append(result[sourceCityID], itemDest)
	}

	return result
}

func BFS(cityMap map[int][]node, n int) int {
	checkedCity := make([]bool, n)
	result := 0
	queue := make(chan int, n)
	queue <- 0
	checkedCity[0] = true
	for {
		if len(queue) == 0 {
			break
		}

		processingCity := <- queue
		//fmt.Println("Processing city = ", processingCity)
		if listNearCity := cityMap[processingCity]; len(listNearCity) != 0 {
			for _, city := range listNearCity {
				//fmt.Println(city)
				if !checkedCity[city.cityNumber] {
					queue <- city.cityNumber
					if !city.isSource {
						result++
					}

					checkedCity[city.cityNumber] = true
				}
			}
		}
		//fmt.Print("\n\n\n\n")
	}

	return result
}

func minReorder(n int, connections [][]int) int {
	listNode := initData(n, connections)
	return BFS(listNode, n)
}

func main()  {
	n := 6
	connections := [][]int{{0,1},{1,3},{2,3},{4,0},{4,5}}
	fmt.Println(minReorder(n, connections))
}