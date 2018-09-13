package main

/*
struct PiumaResult {
  char* path;
  char* message;
} ;
*/
import "C"

import (
	"sync"
	"fmt"
)


//export Countdown
func Countdown() {
	var wg sync.WaitGroup
	for i := 0; i < 2; i++ {
		wg.Add(1)
		go func(n uint) {
			defer wg.Done()
			for n > 0 {
				n -= 1
			}
			fmt.Println("Done! My final value is ", n)
		}(50000000 / 2)
	}
	wg.Wait()
}

func main() {
}
