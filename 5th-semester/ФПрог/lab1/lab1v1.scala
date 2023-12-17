def isAllDigit(numberString : String) : Boolean 
	= numberString forall Character.isDigit

def notZero(numberString : String) : Boolean
	= !numberString.equals("0000000000")

object lab1 {
  def main(args: Array[String]): Unit = {
	var a : BigInt = 0
	var b : BigInt = 0
	var c : BigInt = 0
	var rez: Double = 0.0
	var z = ""

	print("Enter the number: ")
	z = scala.io.StdIn.readLine()
	if ( (z.length() != 10)) {
		println("Incorrect number");  
		sys.exit(0)
	}
	if(!isAllDigit(z)) {
		println("It must be a number!")
		sys.exit(0)
	}
	if(!notZero(z)) {
		println("It must be a positive number!")
		sys.exit(0)
	}
	for (i <- 1 to 5) {
		a = BigInt(z.substring(0, 5))
		b = BigInt(z.substring(5, 10))
		c = a * b
		rez = c.toString().substring(0,3).toDouble / 1000
		z = (BigInt(z) + c).toString 
		println(rez.abs); 
	}
}
}
