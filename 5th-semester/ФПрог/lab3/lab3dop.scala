import scala.util.matching.Regex

object lab_3_dop {

  def tripleFirstLetter(text: String): String = {
    val placePattern: Regex = "\\b(\\w)(\\w*)\\b".r

    val result = placePattern.replaceAllIn(text, matched => matched.group(1) + matched.group(1) + matched.group(0))
    return result
  }
  
  def deleteSpaces(text: String): String = {
    //val placePattern: Regex = "\\s".r
    //val placePattern: Regex = " ".r
    val placePattern: Regex = "(?i)([^a-z])".r
    val result = placePattern.replaceAllIn(text, matched => "")
    return result
  }

  def main(args: Array[String]): Unit = {
    println("He had a great time yesterday.")
    println(tripleFirstLetter("He had a great time yesterday."))
    println(deleteSpaces("He had a great time yesterday."))
  }
}