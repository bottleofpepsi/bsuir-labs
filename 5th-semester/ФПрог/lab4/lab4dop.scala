import org.apache.spark.SparkConf
import org.apache.spark.SparkContext

object lab_4_dop {

  def main(): Unit = {
    val conf = new org.apache.spark.SparkConf()
    val txt = spark.read.textFile("textdop.txt").collect().mkString(" ")
    println(txt)
	println()

    println("Delete spaces: ")
    println("Result 1: " + txt.replaceAll("\\s", ""))
    println("Result 2: " + txt.filter(chr => chr != ' '))
	// println("Result 3: " + txt.split(" ").mkString(""))
	// println("Result 4: " + txt.replaceAll("(?i)[^a-z.,!]", ""))
	println()

    println("Delete vowels: " + txt.replaceAll("(?i)[aeiou]", ""))
	println()

    val regex = "\\w+".r
    println("Replace the last 3 letters with \"ing\": ")
	println(regex.replaceAllIn(txt, matched => matched.group(0).dropRight(3) + "ing"))
  }
}

// 3 последние буквы заменить на ing
// удалить все гласные
// удалить пробелы двумя способами
