import org.apache.spark.SparkConf
import org.apache.spark.SparkContext

object lab_4 {

  def main(): Unit = {
    val conf = new org.apache.spark.SparkConf()
    val txt = spark.read.textFile("text.txt").flatMap(line => line.split("[.,!]?\\s"))
	
	
    val stopList = List("programming", "code", "computer")
    val filtered = txt.filter(word => !stopList.contains(word))
    println("All words except stop-words: ")
    println(filtered.collect().mkString(" "))
    println()

    val containProg = txt.filter(word => word.matches(".*(P|p)rog.*"))
    println("Words that contain \"prog\": ")
    containProg.collect().foreach(println)
    println()
	
    val endsWithIon = txt.filter(word => word.endsWith("ion"))
    println("Words that end with \"ion\"")
    endsWithIon.collect().foreach(println)
    println()

    val thirdLetterR = txt.filter(word => word.matches(".{2}r.*"))
    println("Words in which the third letter is r: ")
    thirdLetterR.collect().foreach(println)
    println()

    val twoEs = txt.filter(word => word.matches("(?i)(.*e.*){2,}"))
    println("Words with two or more e's: ")
    twoEs.collect().foreach(println)
    println()

    val lastWord = txt.tail(1).mkString("")
    println("The last word in text: ")
	println(lastWord)
  }
}