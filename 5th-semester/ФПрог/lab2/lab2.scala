def negativeSum (lst: List[Int]) : Int = {
	if (lst.isEmpty) return 0
	
	if (lst.head >= 0) 
		negativeSum(lst.tail)
	else
		lst.head + negativeSum(lst.tail)
}

def lastThreeSum (lst: List[Int]) : Int = {
	if (lst.isEmpty) return 0
	
	if (lst.length > 3)
		lastThreeSum(lst.tail)
	else
		lst.head + lastThreeSum(lst.tail)
}

def maxValueIndexes(lst: List[Int], max: Int, index: Int, result: String) : String = {
	if (lst.isEmpty) return result
	
	if (max < lst.head)	
		return maxValueIndexes(lst.tail, lst.head, index + 1, index.toString + " ")

	if (max == lst.head)
		return maxValueIndexes(lst.tail, max, index + 1, result + index.toString + " ")
	else	
		return maxValueIndexes(lst.tail, max, index + 1, result)
}

def checkOrder(lst: List[Int], asc: Boolean, desc: Boolean) : Boolean = {
	if (!asc && !desc) return true
	if (lst.length == 1) return false

	if (lst.head > lst.tail.head)
		return checkOrder(lst.tail, false, desc)
	if (lst.head < lst.tail.head)
		return checkOrder(lst.tail, asc, false)
	
	checkOrder(lst.tail, asc, desc)
}

def repeatsThreeTimes(lst: List[Int], num: Option[Int], count: Int) : Boolean = {
	if (count == 3) return true
	if (lst.length + count < 3) return false
	
	if (num == None)
		if (repeatsThreeTimes(lst.tail, Some(lst.head), 1))
			return true
		else
			return repeatsThreeTimes(lst.tail, None, 0)
	
	if (num.get == lst.head) 
		return repeatsThreeTimes(lst.tail, num, count + 1)
	else 
		return repeatsThreeTimes(lst.tail, num, count)
}

object lab_2 {
  def main(args: Array[String]): Unit = {   
	println("Input: ")
	val input = scala.io.StdIn.readLine().trim()
	if (input.isEmpty) {
		println("Incorrect input!")
		sys.exit(0)
	}
	
	val numbers = input.split(" ").map(_.toInt).toList 
	println("Sum of negative numbers: " + negativeSum(numbers))
	println("Sum of the last three numbers: " + lastThreeSum(numbers))
	println("Indexes of max value: " + maxValueIndexes(numbers, Int.MinValue, 0, ""))
	println("Neither ascending nor descending: " + checkOrder(numbers, true, true))
	println("One of the numbers repeats 3 times: " + repeatsThreeTimes(numbers, None, 0))
	println()
}
}