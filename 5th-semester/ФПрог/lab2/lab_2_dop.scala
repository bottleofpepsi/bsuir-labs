def sumOddIndexes(lst: List[Int], index: Int) : Int = {
	if (lst.isEmpty) return 0
	
	if (index % 2 == 0) 
		sumOddIndexes(lst.tail, index + 1)
	else
		lst.head + sumOddIndexes(lst.tail, index + 1)
}

def concatenation(lst1: List[Int], lst2: List[Int]) : List[Int] = {
	if (lst.isEmpty && lst.isEmpty) return 0
	
	if (index % 2 == 0) 
		sumOddIndexes(lst.tail, index + 1)
	else
		lst.head + sumOddIndexes(lst.tail, index + 1)
}

def negativeSum (lst: List[Int]) : Int = {
	if (lst.isEmpty) return 0
	
	if (lst.head >= 0) 
		negativeSum(lst.tail)
	else
		lst.head + negativeSum(lst.tail)
}

object lab_2 {
  def main(args: Array[String]): Unit = {   
	println("Input first list: ")
	val input1 = scala.io.StdIn.readLine().trim()
	val input2 = scala.io.StdIn.readLine().trim()
	if (input1.isEmpty || input2.isEmpty) {
		println("Incorrect input!")
		sys.exit(0)
	}
	
	val firstList = input1.split(" ").map(_.toInt).toList 
	val secondList = input2.split(" ").map(_.toInt).toList 
	// val result = concatenation(firstList, secondList)
	println("Result: " + )
	println("Sum of numbers with odd indexes: " + sumOddIndexes(List(1,2,3,4,5,6), 0))
}
}