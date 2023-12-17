import scala.util.matching.Regex

object lab_3 {

  val numsNames = Map(
    '0' -> "Zero",
    '1' -> "One",
    '2' -> "Two",
    '3' -> "Three",
    '4' -> "Four",
    '5' -> "Five",
    '6' -> "Six",
    '7' -> "Seven",
    '8' -> "Eight",
    '9' -> "Nine"
  )

  def replaceNums(text: String): String = {
    val numberPattern: Regex = "\\d".r
    val result = numberPattern.replaceAllIn(text, { matchObj =>
      val digit = matchObj.group(0)
      numsNames.getOrElse(digit.charAt(0), "0")
    })
    result
  }
  
  def getWordsByPart(text: String, subString: String): String = {
    var result = ""
    val partPattern: Regex = s"\\b\\w*${Regex.quote(subString)}\\w*\\b".r
    val matchesFound = partPattern.findAllMatchIn(text)
    while(matchesFound.hasNext) {
      result = result + matchesFound.next() + " "
    }
    result
  }

  def replaceWords(text: String, substitute: String, replacement: String): String = {
    val wordPattern: Regex = s"\\b${Regex.quote(substitute)}\\b".r
    val result = wordPattern.replaceAllIn(text, replacement)
    result
  }
  
  def swapWords(text: String): String = {
    val stringPattern = s"(\\b\\w+\\b)(.*)(\\b\\w+\\b)".r
    val result = text match{
      case stringPattern(first, middle, last) => s"$last$middle$first"
      case _ => text
    }
    result
  }

  def trimConsonants(text: String): String = {
    val consonantsPattern: Regex = "[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ]".r
    val result = consonantsPattern.replaceAllIn(text, "")
    result
  }
  
  def cutSecondLetter(text: String): String = {
    val letterPattern: Regex = "\\b(\\w)(\\w)(\\w*)\\b".r
    val result = letterPattern.replaceAllIn(text, matched => matched.group(1) + matched.group(3))
    result
  }

  def trimEs(text: String): String = {
    val ePattern: Regex = "[e]".r
    val result = ePattern.replaceAllIn(text, "")
    result
  }

  def placeWord(text: String, wordToPlace: String): String = {
    val placePattern: Regex = s"^\\b(\\w+)\\b(.*)".r
    val result = placePattern.replaceAllIn(text, matched => matched.group(1) + " " + wordToPlace + matched.group(2))
    result
  }

  def main(args: Array[String]): Unit = {
    println("1) 1 + 2 + 3 = 6 => " + replaceNums("1 + 2 + 3 = 6"))
    println("2) Being quiet beautiful girl she never thought of beauty => " + getWordsByPart("Being quiet beautiful girl she never thought of beauty", "beau"))
    println("3) one plus one is two => " + replaceWords("one plus one is two", "one", "two"))
    println("4) world is nice => " + swapWords("world is nice"))
    println("5) Hello to all my friends => " + trimConsonants("Hello to all my friends"))
    println("6) Hello to everybody => " + cutSecondLetter("Hello to everybody"))
    println("7) Hello to everybody => " + trimEs("Hello to everybody"))
    println("8) Be healthy => " + placeWord("Be healthy", "always"))

  }
}