import java.awt.event.{ActionEvent, ActionListener}
import javax.swing.{JButton, JFrame, JLabel, JTextField, JPanel, JTextArea, JScrollPane, SwingUtilities}
import java.sql.{Connection, DriverManager, ResultSet}
import java.awt.{Font, Color}

object ButtonModule {
  val frame = new JFrame("My Application")
  frame.setSize(800, 600)
  frame.getContentPane.setBackground(Color.ORANGE)
  frame.setLayout(null)

  def main(args: Array[String]): Unit = {
    SwingUtilities.invokeLater(() => {

      val labelProduct = new JLabel("Product")
      val labelPrice = new JLabel("Price")
      val labelCount = new JLabel("Count")
      labelProduct.setBounds(220, 170, 130, 20)
      labelPrice.setBounds(375, 170, 130, 20)
      labelCount.setBounds(515, 170, 130, 20)

      val buttonInsert = new JButton("Insert")
      val buttonCheckPrice = new JButton("Check Price")
      val buttonHigher = new JButton("Higher Costs")
      val buttonProfit = new JButton("Get product with max profit") 
      
      val buttonAvgPrice = new JButton("Average > 100")
      val buttonMaxPrice = new JButton("Max price")
      buttonProfit.setBounds(185, 510, 410, 30)
      buttonInsert.setBounds(185, 20, 120, 50)
      buttonHigher.setBounds(330, 20, 120, 50)
      buttonCheckPrice.setBounds(475, 20, 120, 50)
      buttonAvgPrice.setBounds(185, 80, 120, 50)
      buttonMaxPrice.setBounds(330, 80, 120, 50)
      buttonMaxPrice.setBackground(Color.BLACK)
      buttonMaxPrice.setForeground(Color.WHITE)
      
      val textFieldProduct = new JTextField(20)
      val textFieldPrice = new JTextField(20)
      val textFieldCount = new JTextField(20)
      textFieldProduct.setBounds(180, 150, 130, 20)
      textFieldPrice.setBounds(325, 150, 130, 20)
      textFieldCount.setBounds(470, 150, 130, 20)
      
      val outputArea = new JTextArea() 
      outputArea.setBackground(Color.white)
      outputArea.setFont(new Font("Arial", Font.PLAIN, 18))
      outputArea.setEditable(false)
      
      val scroll = new JScrollPane(outputArea)
      scroll.setBounds(140, 200, 500, 300)
      
      frame.add(buttonInsert)
      frame.add(buttonCheckPrice)
      frame.add(buttonProfit)
      frame.add(buttonAvgPrice)
      frame.add(buttonMaxPrice)
      frame.add(buttonHigher)
      frame.add(labelProduct)
      frame.add(labelCount)
      frame.add(textFieldProduct)
      frame.add(labelPrice)
      frame.add(textFieldPrice)
      frame.add(scroll)
      frame.add(textFieldCount)
      
      buttonProfit.addActionListener(new ActionListener{
        override def actionPerformed(e: ActionEvent): Unit = {
          val url = "jdbc:mysql://localhost:3306/mydb"
          val username = "root"
          val password = "root"
          Class.forName("com.mysql.jdbc.Driver")
          val conn = DriverManager.getConnection(url, username, password)

          try {
            val stmt = conn.createStatement()
            val rs = stmt.executeQuery("SELECT product, price, product_count, MAX(product_count * price) AS max_profit FROM sklad GROUP BY product ORDER BY max_profit DESC LIMIT 1")          
            val resultText = new StringBuilder()
            while (rs.next()){
              val name = rs.getString("product")
              val price = rs.getInt("price")
              val count = rs.getInt("product_count")
              val maxProfit = rs.getInt("max_profit")
              resultText.append(s"Product: $name\nPrice: $price\nCount: $count\nMax Profit: $maxProfit\n")
            }
            
            textFieldPrice.setText("")
            textFieldProduct.setText("")
            textFieldCount.setText("")
            
            if (resultText.isEmpty) 
              resultText.append(s"Error: \nDatabase table is empty")
            outputArea.setText(resultText.toString())
          } finally {
            conn.close()
          }
        }
      })
      
      buttonHigher.addActionListener(new ActionListener{
        override def actionPerformed(e: ActionEvent): Unit = {
          if (textFieldPrice.getText.isEmpty) {
            outputArea.setText("Error: \nPrice field is empty")
            return
          }
          val url = "jdbc:mysql://localhost:3306/mydb"
          val username = "root"
          val password = "root"
          Class.forName("com.mysql.jdbc.Driver")
          val conn = DriverManager.getConnection(url, username, password)

          try {
            val stmt = conn.createStatement()
            
            val lowPrice = textFieldPrice.getText().toInt
            val query = "SELECT * FROM sklad WHERE price >= ?"
            val pstmt = conn.prepareStatement(query)
            pstmt.setInt(1, lowPrice)
            
            val rs = pstmt.executeQuery()
         
            val resultText = new StringBuilder()
            while (rs.next()){
              val name = rs.getString("product")
              val price = rs.getInt("price")
              val count = rs.getInt("product_count")
              resultText.append(s"Product: $name \nPrice: $price \nCount: $count\n\n")
            }

            textFieldPrice.setText("")
            textFieldProduct.setText("")
            textFieldCount.setText("")
            outputArea.setText(resultText.toString())
          } finally {
            conn.close()
          }
        }
      })

      buttonInsert.addActionListener(new ActionListener {
        override def actionPerformed(e: ActionEvent): Unit = {
          if (textFieldProduct.getText.isEmpty || textFieldPrice.getText.isEmpty || textFieldCount.getText.isEmpty) {
            outputArea.setText("Error: \nFields cannot be empty")
            return
          }
          val url = "jdbc:mysql://localhost:3306/mydb"
          val username = "root"
          val password = "root"
          Class.forName("com.mysql.jdbc.Driver")
          val conn = DriverManager.getConnection(url, username, password)

          try {
            val stmt = conn.createStatement()
            val rs = stmt.execute("INSERT INTO sklad VALUES ('" + textFieldProduct.getText + "'," + textFieldPrice.getText + "," + textFieldCount.getText + ")")

            textFieldPrice.setText("")
            textFieldProduct.setText("")
            textFieldCount.setText("")
            outputArea.setText("Added record")
          } finally {
            conn.close()
          }
        }
      })

      buttonCheckPrice.addActionListener(new ActionListener {
        override def actionPerformed(e: ActionEvent): Unit = {
          if (textFieldProduct.getText.isEmpty) {
            outputArea.setText("Error: \nProduct field is empty")
            return
          }
          val url = "jdbc:mysql://localhost:3306/mydb"
          val username = "root"
          val password = "root"

          Class.forName("com.mysql.jdbc.Driver")
          val conn = DriverManager.getConnection(url, username, password)

          try {
            val stmt = conn.createStatement()
            val prod_name = textFieldProduct.getText().toString().trim()
            val rs = stmt.executeQuery("SELECT * FROM sklad WHERE product = '" + prod_name + "'")

            val resultText = new StringBuilder()
            while (rs.next()) {
              val name = rs.getString("product")
              val price = rs.getInt("price")
              val count = rs.getInt("product_count")
              resultText.append(s"Product: $name \nPrice: $price \nCount: $count\n")
            }
            
            textFieldPrice.setText("")
            textFieldProduct.setText("")
            textFieldCount.setText("")
            if (resultText.isEmpty) 
              resultText.append(s"Error: \nThere are no records of this product in the database")
            outputArea.setText(resultText.toString())
          } finally {
            conn.close()
          }
        }
      })
      
      buttonAvgPrice.addActionListener(new ActionListener {
        override def actionPerformed(e: ActionEvent): Unit = {
          val url = "jdbc:mysql://localhost:3306/mydb"
          val username = "root"
          val password = "root"

          Class.forName("com.mysql.jdbc.Driver")
          val conn = DriverManager.getConnection(url, username, password)

          try {
            val stmt = conn.createStatement()
            val prod_name = textFieldProduct.getText().toString().trim()
            val rs = stmt.executeQuery("SELECT *, AVG(price) AS average FROM sklad GROUP BY product HAVING price > 100")

            val resultText = new StringBuilder()
            while (rs.next()) {
              val product = rs.getString("product")
              val price = rs.getInt("average")
              resultText.append(s"Average price '$product': $price")
            }
            
            textFieldPrice.setText("")
            textFieldProduct.setText("")
            textFieldCount.setText("")
            if (resultText.isEmpty) 
              resultText.append(s"Error: \nThere are no records of this product in the database")
            outputArea.setText(resultText.toString())
          } finally {
            conn.close()
          }
        }
      })
      
      buttonMaxPrice.addActionListener(new ActionListener {
        override def actionPerformed(e: ActionEvent): Unit = {
          val url = "jdbc:mysql://localhost:3306/mydb"
          val username = "root"
          val password = "root"

          Class.forName("com.mysql.jdbc.Driver")
          val conn = DriverManager.getConnection(url, username, password)

          try {
            val stmt = conn.createStatement()
            val prod_name = textFieldProduct.getText().toString().trim()
            val rs = stmt.executeQuery("SELECT * FROM sklad WHERE price >= ALL(SELECT price FROM sklad)")

            val resultText = new StringBuilder()
            while (rs.next()) {
              val name = rs.getString("product")
              val price = rs.getInt("price")
              val count = rs.getInt("product_count")
              resultText.append(s"Product: $name \nPrice: $price \nCount: $count\n\n")
            }
            
            textFieldPrice.setText("")
            textFieldProduct.setText("")
            textFieldCount.setText("")
            if (resultText.isEmpty) 
              resultText.append(s"Error: \nThere are no records of this product in the database")
            outputArea.setText(resultText.toString())
          } finally {
            conn.close()
          }
        }
      })

      frame.setBackground(Color.BLUE)
      frame.setLocationRelativeTo(null)
      frame.setVisible(true)

    })
  }
}