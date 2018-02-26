import java.sql.*;

public class insert{
	
	public static void main (String args[]){
		Class.forName(""oracle.jdbc.driver.OracleDriver"");
		Connection con = DriverManager.getConnection( "jdbc:oracle:thin:@localhost:1521:orcl", "login1", "pwd1");
		Statement stmt = con.createStatement();
             
		String q1 = "insert into userid values('" +id+ "', '" +pwd+ 
							  "', '" +fullname+ "', '" +email+ "')";
		stmt.executeUpdate(q1);
	}
}





