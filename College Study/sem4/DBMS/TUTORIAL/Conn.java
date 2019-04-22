import java.sql.*;

public class Conn {
    public static void main(String args[]) {
        Connection conn = null;
        Statement stm = null;
        try {
            System.out.println("Connecting to database.");
            conn = DriverManager.getConnection("jdbc:mysql://localhost:3306/testdb", "testuser", "Pass123!");
            stm = conn.createStatement();
            String selall = "select * from student;";
            String minage;
            ResultSet rs = stm.executeQuery(selall);

            while(rs.next()) {
                System.out.println("-------------------------------------------------------------------------------");
                System.out.println(rs.getString(1) + "\t"
                + rs.getString(2) + "\t"
                + rs.getString(3) + "\t"
                + rs.getString(4) + "\t"
                + rs.getInt(5));
                System.out.println("-------------------------------------------------------------------------------");
            }

            conn.close();
        } catch (SQLException e) {
            //TODO: handle exception
            System.out.println("Exception " + e.getMessage());
        }
    }
}
