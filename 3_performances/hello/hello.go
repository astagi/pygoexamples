package main


import "C"

import (
	"fmt"
)


//export sayHello
func sayHello(message string) string {
	return fmt.Sprintf("Hello %v", message)
}


//export sayHelloSlowly
func sayHelloSlowly(message *C.char) *C.char {
	return C.CString(fmt.Sprintf("Hello %v", C.GoString(message)))
}

//export sayHelloFaster
func sayHelloFaster(message *C.char, count int) {
	for count > 0 {
		fmt.Printf(fmt.Sprintf("\rHello %v", C.GoString(message)))
		count -= 1
	}
}


func main() {}
