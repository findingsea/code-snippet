package main
import "fmt"

func sum(s []int, c chan int) {
	sum := 0
	for _, v := range s{
		sum += v
	}
	c <- sum
}

func printSeq(seq int, c chan int) {
	fmt.Println("seq: ", seq)
	c <- seq
}

func main()  {
	s := []int{1,2,3,4,5}
	c := make(chan int)
	go sum(s[:len(s) / 2], c)
	go sum(s[len(s) / 2:], c)
	x, y := <-c, <-c
	fmt.Println(x, y, x + y)

	go printSeq(0, c)
	go printSeq(1, c)
	<-c
	<-c
}